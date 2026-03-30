/* Deliberate practice > blind repetition */
// Author: Belal
// URL: https://codeforces.com/group/reRlOrZJrU/contest/676893/problem/E


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


void solve() {

    int n,k;cin>>n>>k;
    vector<pair<ll,ll>> tot(n);
    for(auto &[a,b] : tot)  cin>>a>>b;
    ll a=0,b=0;

    auto simply = [&](){
        sort(all(tot),[&](pair<int,int> l,pair<int,int> r){
                return 1LL * b * l.first - 1LL * a * l.second > 1LL * b * r.first - 1LL * a * r.second;
            }
        );
        ll nA=0,nB=0;
        for(int i = 0; i < k; i++){
            nA += tot[i].first;
            nB += tot[i].second;
        }
        if (a == nA && b == nB) return 0;
        a=nA;b=nB; 
        return 1;
    };
    
    while(simply());
    ll g = __gcd(a,b);
    cout<< a/g <<" "<<b/g;
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
