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

   int n,q; cin >> n >> q;
    vector<ll> a(n+1,0);
       for(int i=1;i<=n;i++) cin >> a[i];

    vector<ll> prefixsum(n+1,0);
    for(int i=1;i<=n;i++) prefixsum[i] = prefixsum[i-1] + a[i];

    ll total = prefixsum[n];

    while(q--){
        int l,r; ll k; cin >> l >> r >> k;
        ll range_sum = prefixsum[r] - prefixsum[l-1];
        ll len = r - l + 1;

        ll q_sum = total - range_sum + len * k;

        if(q_sum % 2) cout << "YES\n";
        else cout << "NO\n";
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
