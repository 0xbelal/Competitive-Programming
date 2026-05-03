/* Deliberate practice > blind repetition */
// Author: Belal
// URL: https://codeforces.com/group/oLXNuV6krr/contest/687746/problem/M


#include<set>
#include<map>
#include<list>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<complex>
#include<sstream>
#include<iostream>
#include<fstream>
#include<algorithm>
#include<assert.h>
#include <climits>

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
    int n, q; cin >> n >> q;
    vector<ll> a(n); cin >> a;
    int l = 0, r = n - 1;
    ll t = 0;
    vector<pair<ll, int>> ans={{0, n}};

    while (l < r) {
        ll step = min(a[l], a[r]);
        t += step;
        a[l] -= step;
        a[r] -= step;
        if (!a[l]) l++;
        if (!a[r]) r--;
        ans.push_back({t, r - l + 1});
    }
    if (l == r) ans.push_back({t + a[l], 0});

    while (q--) {
        ll s; cin >> s;
        auto it = upper_bound(all(ans), make_pair(s, INT_MAX));
        cout << prev(it)->second << "\n";
    }
    cout << "\n";
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
