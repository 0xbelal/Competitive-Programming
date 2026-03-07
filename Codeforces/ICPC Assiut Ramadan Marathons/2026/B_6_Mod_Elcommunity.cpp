/* Deliberate practice > blind repetition */
// Author: Belal
// URL: https://codeforces.com/group/MEqF8b6wBT/contest/673206/problem/B6


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
const ll p=998244353,mod=1e9+7;
void solve() {

    ll n,k;cin>>n>>k;
    vector<int> v;
    v.reserve(n*100);

    for(int i=0;i<n;i++){
        ll ai;cin>>ai;
        ai%=mod;
        for(int j=1;j<=100;j++){
            ll temp = (int)(ai+ (j*p))%mod;
            v.push_back((int)temp);
        }
    }
    sort(all(v));
    v.erase(unique(all(v)),v.end());
    
    ll missing_count = 0;
    ll last_val = -1; 
    
    for (int x : v) {
        if (x < 0) continue;
        ll gap = (ll)x - last_val - 1;
        if (gap > 0) {
            if (missing_count + gap >= k) {
                cout << last_val + (k - missing_count) << endl;
                return;
            }
            missing_count += gap;
        }
        last_val = x;
    }
        cout << last_val + (k - missing_count) << endl;
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
