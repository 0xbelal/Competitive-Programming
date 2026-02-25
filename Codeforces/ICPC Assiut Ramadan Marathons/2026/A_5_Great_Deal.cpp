/* Deliberate practice > blind repetition */
// Author: Belal
// URL: https://codeforces.com/group/MEqF8b6wBT/contest/673206/problem/A5


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

const double EPS = (1e-9);

ll prefix[2000005];

void solve() {

    ll n,q,k;cin>>n>>q>>k;
    for(int i = 1; i <= n; i++){
        ll x; cin >> x;
        prefix[i] = prefix[i-1] + x;
    }
    for(int i=0;i<q;i++){
        int l,r;cin>>l>>r;
        ll rangesum = (prefix[r]-prefix[l-1]);
        if((__int128)8 * rangesum <= (__int128)10 * k){
            cout<<"YES\n";
        }else cout<<"NO\n";
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
