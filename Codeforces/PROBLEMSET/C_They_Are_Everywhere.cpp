/* Deliberate practice > blind repetition */
// Author: Belal
// URL: https://codeforces.com/contest/701/problem/C


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
    string s; cin >> s;
    set<int> ss;
    for(char c : s) ss.insert(c);
    int disc = ss.size();
    int l = 0, r = 1, win = 0, ans = 1e6;
    map<char, int> freq;
    for(r = 0; r < n; r++){
        if(freq[s[r]] == 0) win++;
        freq[s[r]]++;
        while (win == disc)
        {
            ans = min(ans , r - l + 1);
            freq[s[l]]--;
            if(freq[s[l]] == 0) win--;
            l++;
        }
        
    }
    cout << ans ;
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
