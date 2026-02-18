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

     int n; cin >> n;
    vector<ll> a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    string s; cin >> s;
    s = ")" + s; 

    vector<ll> pref(n+1, 0);
    for (int i = 1; i <= n; i++) pref[i] = pref[i-1] + a[i];

    ll ans = 0;
    int l = 1, r = n;

    while (l < r) {
        while (l < r && s[l] != 'L') l++;
        while (l < r && s[r] != 'R') r--;
        if (l < r) {
            ans += pref[r] - pref[l-1];
            l++;
            r--;
        }
    }

    cout << ans << "\n";
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
