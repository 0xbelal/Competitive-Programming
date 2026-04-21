/* Deliberate practice > blind repetition */
// Author: Belal
// URL: https://codeforces.com/problemset/problem/245/H


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
const int N =  5002;
string s;
int dp[N][N]{};
bool isP[N][N]{};
void Pre(){
    int n = s.size();
    for (int i = 0; i < n; i++) isP[i][i] = dp[i][i] = isP[i+1][i] = 1;
    for(int l = n - 1; l >= 0; l--){
        for(int r = l + 1; r < n; r++){
            isP[l][r] = isP[l + 1][r - 1] && s[l] == s[r];
            dp[l][r] = dp[l][r - 1] + dp[l + 1][r] - dp[l + 1][r - 1] + isP[l][r];
        }
    }
}
void solve() {
    cin >> s;
    Pre();
    int q; cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << dp[l - 1][r - 1] << '\n';
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
