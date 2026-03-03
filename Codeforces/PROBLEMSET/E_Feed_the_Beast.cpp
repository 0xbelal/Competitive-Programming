/* Deliberate practice > blind repetition */
// Author: Belal
// URL: https://codeforces.com/gym/106387/problem/E


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

bool can(ll d,ll b,ll x,vector<ll> &a){
    ll c=0;
    for(ll i=0;i<a.size();i++){
        ll need=d*a[i];
        c+=(need+x-1)/x;
        if(c>b)return false;
    }
    return c<=b;
}
void solve() {

    int n,b,x;cin>>n>>b>>x;
    vector<ll> a(n);cin>>a;
    ll l=0,r=1e12,ans=0;
    while (l<=r)
    {
        ll mid =l+(r-l)/2;
        if(can(mid,b,x,a)){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }

    }
    cout<<ans<<"\n";

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
