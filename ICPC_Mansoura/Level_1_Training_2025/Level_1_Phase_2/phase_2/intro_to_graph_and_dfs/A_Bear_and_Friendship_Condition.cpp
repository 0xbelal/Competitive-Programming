/* Deliberate practice > blind repetition */
// Author: Belal
// URL: https://codeforces.com/problemset/problem/771/A


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

const int N = 150123;
vector<int> edges[N];
bool vis[N];
int n,m;
 
void dfs(int a, int & cnt_vertices, int & cnt_edges) {

	vis[a] = true;
	++cnt_vertices;
	cnt_edges += edges[a].size();
	for(int b : edges[a])
		if(!vis[b]) dfs(b, cnt_vertices, cnt_edges);
}

void solve() {

    cin>>n>>m;

    while(m--) {
		int a,b;cin>>a>>b;
        edges[a].push_back(b);
		edges[b].push_back(a);
	}
	for(int i=1;i<=n;++i)
		if(!vis[i]) {
			int cnt_vertices=0,cnt_edges=0;
			dfs(i,cnt_vertices,cnt_edges);
			if(cnt_edges != (ll)cnt_vertices*(cnt_vertices-1)) {cout<<"NO";return;}
		}
    cout<<"YES";
    
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
