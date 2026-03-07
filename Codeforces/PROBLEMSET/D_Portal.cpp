/* Deliberate practice > blind repetition */
// Author: Belal
// URL: https://codeforces.com/contest/2200/problem/D


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
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> p(n);
    for (int& e : p)
        cin >> e;
    vector cycle(p.begin() + x, p.begin() + y);
    p.erase(p.begin() + x, p.begin() + y);
    ranges::rotate(cycle, ranges::min_element(cycle));
    auto pos = p.begin();
    while (pos != p.end() && *pos < cycle[0])
        ++pos;
    p.insert(pos, cycle.begin(), cycle.end());
    for (int& e : p)
        cout << e << ' ';
    cout << '\n';
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
