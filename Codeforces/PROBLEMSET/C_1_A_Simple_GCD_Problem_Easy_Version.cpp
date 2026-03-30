/* Deliberate practice > blind repetition */
// Author: Belal
// URL: https://codeforces.com/contest/2210/problem/C1


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


ll lcm(ll a, ll b) {if (a==0 || b == 0) return 0; return (a * b) / __gcd(a, b);}
void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) {int x;cin >> x;}
    ll ans = 0, m;
    for(int i = 0; i < n; i++) {
       if (i == 0) m = __gcd(a[i],a[i+1]);
       else if (i == n-1) m= __gcd(a[i- 1],a[i]);
       else m = lcm(__gcd(a[i-1], a[i]), __gcd(a[i], a[i+1]));
       ans += (m < a[i]);
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
