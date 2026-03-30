/* Deliberate practice > blind repetition */
// Author: Belal
// URL: https://codeforces.com/contest/699/problem/A


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
    vector<char> dir(n); cin >> dir;
    vector<int> coor(n); cin >> coor;
    if(n == 1) {cout << "-1"; return;}
    int r_idx = -1, l_idx = -1;
    int ans = __INT_MAX__;
    bool found = false;
    for(int i = 0; i < n; i++){
        if(dir[i] == 'R'){
            r_idx = i;
            found = true;
        }else{
            if(!found) continue;
            l_idx = i;  
            ans = min(ans, (coor[l_idx] - coor[r_idx] ) / 2);
            found = false;
        }
    }

    if(r_idx == -1 || l_idx == -1){cout << "-1"; return;}
    cout << ans;
    /*
        1  2  3  4  5  6  7  8  9  10 
           ^     ^     ^            ^
           R     L     R            L   
    */    
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
