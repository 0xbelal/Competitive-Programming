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

#define all(v)				((v).begin()), ((v).end())
#define sz(v)				((int)((v).size()))
#define rep(i, v)		for(int i=0;i<sz(v);++i)
#define lp(i, n)		for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)	for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)	for(int i=(j);i>=(int)(n);--i)
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define ff first
#define ss second

const double EPS = (1e-7);


void solve() {
   int n, q;
    cin >> n >> q;

    map<ll, ll> partial;
    lp(i,n){
        ll l,r; 
        cin >> l >> r;
        partial[l] += 1;
        partial[r + 1] -= 1;
    }
    ll pref = 0;
    for (auto &x : partial) {
        pref += x.second;
        x.second = pref;
    }
    while (q--) {
        ll s; cin >> s;
        auto it=partial.upper_bound(s);
        if (it== partial.begin()) cout << 0 << "\n";
        else {
            --it;
            cout << it->second << "\n";
        }
    }
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
