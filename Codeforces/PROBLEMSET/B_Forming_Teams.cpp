/* Deliberate practice > blind repetition */
// Author: Belal
// URL: https://codeforces.com/contest/216/problem/B


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
const int N = 101;
vector<int> a[N];
int vis[N];
bool cycle = false;
int cnt = 1;
void dfs(int v, int par){
    vis[v] = 1;
    for(int x : a[v]){ 
        if(!vis[x]) { cnt++; dfs(x, v); }
        else if(x != par) { cycle = true; } 
    }
}
void solve() {

    int n,m;cin>>n>>m;
    while(m--){
        int x,y;cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
  int odd_cycles = 0;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            cnt = 1;
            dfs(i, i);
            if(cycle && cnt % 2 == 1) odd_cycles++; 
            cycle = false;
        }
    }

    int total = n - odd_cycles;         
    if(total % 2 == 1) total--;         
    cout << n - total;  
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
