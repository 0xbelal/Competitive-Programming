#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        long long x;
        cin >> n >> k >> x;
        
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        sort(a.begin(), a.end());
        
        // احسب كل الفجوات
        vector<pair<long long, pair<long long, long long>>> segments;
        
        // فجوة من 0 إلى أول صديق
        if (a[0] > 0) {
            segments.push_back({a[0], {0, a[0]}});
        }
        
        // فجوات بين الأصدقاء
        for (int i = 0; i < n - 1; i++) {
            if (a[i + 1] > a[i]) {
                segments.push_back({a[i + 1] - a[i], {a[i], a[i + 1]}});
            }
        }
        
        // فجوة من آخر صديق إلى x
        if (a[n - 1] < x) {
            segments.push_back({x - a[n - 1], {a[n - 1], x}});
        }
        
        vector<long long> result;
        
        auto canAchieve = [&](long long minDist) {
            int teleportsNeeded = 0;
            for (auto& seg : segments) {
                long long len = seg.first;
                long long parts = (len + minDist - 1) / minDist;
                teleportsNeeded += max(0LL, parts - 1);
            }
            return teleportsNeeded <= k;
        };
        
        long long left = 0, right = x, bestDist = 0;
        while (left <= right) {
            long long mid = (left + right) / 2;
            if (canAchieve(mid)) {
                bestDist = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        for (auto& seg : segments) {
            long long L = seg.second.first;
            long long R = seg.second.second;
            long long len = seg.first;
            
            if (bestDist == 0) break;
            
            long long parts = (len + bestDist - 1) / bestDist;
            int teleportsInSegment = max(0LL, parts - 1);
            
            for (int i = 1; i <= teleportsInSegment && result.size() < k; i++) {
                long long pos = L + (len * i) / parts;
                result.push_back(pos);
            }
        }
        
        while (result.size() < k) {
            result.push_back(0);
        }
        
        for (int i = 0; i < k; i++) {
            cout << result[i];
            if (i < k - 1) cout << " ";
        }
        cout << "\n";
    }
    
    return 0;
}