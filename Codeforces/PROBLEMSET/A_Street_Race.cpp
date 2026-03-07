/* Deliberate practice > blind repetition */
// Author: Belal
// URL: https://codeforces.com/group/reRlOrZJrU/contest/676893/problem/A


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
#include <math.h>
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
#define rall(x) (x).rbegin(), (x).rend()\
#define pb push_back
#define ff first
#define ss second

const double EPS = (1e-7);


void solve() {

    double a,b,c,x1,y1,x2,y2; 
    cin>>a>>b>>c>>x1>>y1>>x2>>y2;
    double xr=x2-2*a*((a*x2 + b*y2 + c) / (a*a + b*b));
    double yr=y2-2*b*((a*x2 + b*y2 + c) / (a*a + b*b));
    double ans = sqrt( pow(x1-xr,2) + pow(y1-yr,2) );
    cout<<ans<<"\n";
}

int main() {
    fast_io;

    int t = 1;


    cin >> t;
    cout << fixed << setprecision(9);
    while (t--) {
        solve();
    }

    return 0;
}
