/* Deliberate practice > blind repetition */
// Author: Belal
// URL: https://codeforces.com/contest/143/problem/A


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
int  r1, r2, c1, c2, d1, d2;
bool check (int a12,int a11,int a22,int a21){
    set<int> sq = {a11, a12, a21, a22};
    if(sq.size() < 4 || a11 > 9 || a12 > 9 
        || a21 > 9 || a22 > 9
        || a11 < 1 || a12 < 1 
        || a21 < 1 || a22 < 1
        || a11 + a12 != r1 
        || a21 + a22 != r2 
        || a11 + a21 != c1 
        || a12 + a22 != c2 
        || a11 + a22 != d1 
        || a12 + a21 != d2 ) return false;

    return true;
}
void solve() {

    cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;
    int a12, a11, a22, a21;

    a12 = (d2 + r1 - c1) / 2;
    a11 = r1 - a12;
    a21 = c1 - a11;
    a22 = c2 - a12;
    if(!check(a12, a11, a22, a21)) cout << -1;
    else cout << a11 << " " << a12 << "\n" << a21 << " " << a22;
 
}

/*

    a11 a12
    a21 a22

    d1 = a11 + a22  
    d2 = a12 + a21

    r1 = a11 + a12
    r2 = a21 + a22

    c1 = a11 + a21
    c2 = a12 + a22
===========================
    > r1 - a12 = c1 - a21
    => a12 - a21 = r1 - c1
    => d2 = a12 + a21 
    == 2*a12 = d2 + r1 - c1
===========================
*/
int main() {
    fast_io;

    int t = 1;

    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
