#!/usr/bin/env python3
"""
CPH Watcher - Automatically adds problem info as comments at the top of .cpp files
Usage: python3 cph_watcher.py /path/to/your/cp/folder
"""

import json
import os
import sys
import time
from datetime import datetime
from pathlib import Path


def format_comment(metadata: dict) -> str:
    """Build the comment block from metadata"""
    name = metadata.get("name", "Unknown Problem")
    url = metadata.get("url", "N/A")
    time_limit = metadata.get("timeLimit", "N/A")
    memory_limit = metadata.get("memoryLimit", "N/A")
    now = datetime.now().strftime("%m/%d/%Y, %I:%M:%S %p")

    return f"""// {name}
// URL: {url}
// Time: {now}
// Time Limit: {time_limit}ms | Memory Limit: {memory_limit}MB

"""


def add_comment_to_cpp(cpp_path: Path, cph_path: Path):
    """Add comment block to the top of the .cpp file if not already present"""
    try:
        with open(cph_path, "r") as f:
            metadata = json.load(f)
    except Exception as e:
        print(f"❌ Failed to read {cph_path}: {e}")
        return

    try:
        with open(cpp_path, "r") as f:
            content = f.read()
    except Exception as e:
        print(f"❌ Failed to read {cpp_path}: {e}")
        return

    # Skip if comment already exists
    if content.startswith("// ") and "// URL:" in content[:200]:
        print(f"⏭️  Comment already exists in {cpp_path.name}")
        return

    comment = format_comment(metadata)
    new_content = comment + content

    try:
        with open(cpp_path, "w") as f:
            f.write(new_content)
        print(f"✅ Added info for: {metadata.get('name', 'Unknown')}")
    except Exception as e:
        print(f"❌ Failed to write to {cpp_path}: {e}")


def watch_folder(base_folder: str):
    """Watch the folder and add comments automatically when a new problem is opened"""
    base = Path(base_folder)
    cph_folder = base / ".cph"

    if not base.exists():
        print(f"❌ Folder not found: {base_folder}")
        sys.exit(1)

    print(f"👀 Watching: {base_folder}")
    print(f"📁 .cph folder: {cph_folder}")
    print("Press Ctrl+C to stop\n")

    processed = set()

    while True:
        if cph_folder.exists():
            for cph_file in cph_folder.glob("*.json"):
                if cph_file in processed:
                    continue

                try:
                    with open(cph_file, "r") as f:
                        metadata = json.load(f)

                    src_path = metadata.get("srcPath")
                    if src_path:
                        cpp_path = Path(src_path)
                        if cpp_path.exists():
                            add_comment_to_cpp(cpp_path, cph_file)
                            processed.add(cph_file)
                except Exception as e:
                    print(f"❌ Error: {e}")

        time.sleep(1)


if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python3 cph_watcher.py /path/to/your/cp/folder")
        print("Example: python3 cph_watcher.py '/home/belal/data/Computer Science/CP'")
        sys.exit(1)

    folder = " ".join(sys.argv[1:])
    watch_folder(folder)
