/* Deliberate practice > blind repetition */
// Author: Belal
// URL: https://codeforces.com/contest/298/problem/A


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
    string s; cin >> s;
    int fl = -1, ll = -1, fr = -1, lr = -1;

    for(int i = 0; i < n; i++){
        if (s[i] == 'R'){
            if(fr == -1) fr = i + 1;
            lr = i + 1; 
        }
        if (s[i] == 'L'){
            if(fl == -1) fl = i + 1;
            ll = i + 1;
        }
    }

    if (fl == -1) {
        cout << fr << " " << lr + 1 << endl;
    } else if (fr == -1) {
        cout << ll << " " << fl - 1 << endl;
    } else {
        cout << fr << " " << fl << endl;
    }   
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
