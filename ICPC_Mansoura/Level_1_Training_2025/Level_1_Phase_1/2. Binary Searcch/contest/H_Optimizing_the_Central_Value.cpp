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

  int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;

    sort(all(a));
    int mid = n / 2;  

    ll l = a[mid], r = a[mid] + k + 1;

    while (l + 1 < r) {
        
        ll m = l + (r - l) / 2;
        ll need = 0;

        for (int i = mid; i < n; ++i) {
            if (a[i] < m)
                need += (m - a[i]);
            if (need > k) break; 
        }

        if (need <= k)
            l = m;  
        else
            r = m;
    }

    cout << l << "\n";
    
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
