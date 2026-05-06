/* Deliberate practice > blind repetition */
// Author: Belal
// URL: https://codeforces.com/contest/1372/problem/C


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

    int n, ans = 1, flag = true; cin >> n;
    // map<int,int> mp; 
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] != i) flag = false;
    }
    if(flag) return void(cout << "0\n");
    int l = 1, r = n;
    while (a[l] == l) l++;
    while(a[r] == r) r--;
    for(int i = l; i <= r; i++)
        if (a[i] == i){ ans = 2; break; }
    
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
