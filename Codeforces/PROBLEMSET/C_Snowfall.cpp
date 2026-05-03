/* Deliberate practice > blind repetition */
// Author: Belal
// URL: https://codeforces.com/contest/2227/problem/C


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
    int n; cin >> n;
    vector<int>  d2, d3, d6, no;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x % 6 == 0) d6.push_back(x);
        else if (x % 2 == 0) d2.push_back(x);
        else if (x % 3 == 0) d3.push_back(x);
        else no.push_back(x);
    } 
    cout << d6 << d2 << no << d3 << "\n";
    
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
