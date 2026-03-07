/* Deliberate practice > blind repetition */
// Author: Belal
// URL: https://codeforces.com/group/MEqF8b6wBT/contest/673206/problem/B3


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
    if (n < 3) { 
        cout << "-1\n";
        return;
    }
    if (n == 3) {
        cout << "720\n"; 
        return;
    }
    string prefix(n-4,'9');
    ll rem360 = 0;
    for(char c:prefix) rem360 = (rem360 * 10 + (c - '0')) % 360;
    
    long long rem7 = 0;
    for(char c : prefix) rem7 = (rem7 * 10 + (c - '0')) % 7;

    for (int s = 9999; s >= 0; --s) {
        if (s < 1000 && n > 4) continue;
        
        bool div360 = (rem360 * 10000 + s) % 360 == 0;
        bool div7 = (rem7 * 10000 + s) % 7 == 0;
        
        if (div360 && !div7) {
            cout << prefix;
            string s_str = to_string(s);
            while(s_str.size() < 4) s_str = "0" + s_str;
            cout << s_str << "\n";
            return;
        }
    }
    cout << "-1\n";
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
