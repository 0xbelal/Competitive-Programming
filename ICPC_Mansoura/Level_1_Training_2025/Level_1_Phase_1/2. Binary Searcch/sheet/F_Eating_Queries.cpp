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
    int n, q; 
    cin >> n >> q;
    vector<ll> sug(n); 
    cin >> sug;

    sort(rall(sug));

    vector<ll> prefix(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + sug[i - 1];
    }

    while (q--) {
        ll qi; 
        cin >> qi;

        int l = 1, r = n, ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (prefix[mid] >= qi) {
                ans = mid;
                r = mid - 1; 
            } else {
                l = mid + 1;
            }
        }

        cout << ans << "\n";
    }
}


int main() {
    fast_io;

    int t = 1;

    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
