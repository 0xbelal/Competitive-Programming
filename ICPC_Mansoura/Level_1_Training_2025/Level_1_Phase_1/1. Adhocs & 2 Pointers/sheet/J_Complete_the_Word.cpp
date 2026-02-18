// belal_cp_temp
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;


template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);

using ll = long long;
using ull = unsigned long long;
using ld = long double;


#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define ff first
#define ss second

void solve() {
    string s; 
    cin >> s;
    if (s.size() < 26) {
        cout << -1;
        return;
    }

    for (int i = 0; i + 26 <= (int)s.size(); i++) {
        vector<int> seen(26, 0);
        bool ok = true;
        int Q = 0;

        for (int j = i; j < i + 26; j++) {
            if (s[j] == '?') {
                Q++;
            } else {
                seen[s[j] - 'A']++;
                if (seen[s[j] - 'A'] > 1) {
                    ok = false;
                    break;
                }
            }
        }

        if (!ok) continue;

        string miss = "";
        for (int k = 0; k < 26; k++) {
            if (seen[k] == 0) miss += char('A' + k);
        }

        if ((int)miss.size() <= Q) {
            int miss_pos = 0;
            for (int j = i; j < i + 26; j++) {
                if (s[j] == '?') {
                    s[j] = miss[miss_pos++];
                }
            }
            for (int j = 0; j < (int)s.size(); j++) {
                if (s[j] == '?') s[j] = 'A';
            }
            cout << s;
            return;
        }
    }

    cout << -1;
}

int main() {
    fast_io;

    int t = 1;

    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
