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
const int N=3e4+5;
vector<int> adj[N];
int vis[N];
int can=0,target;


void dfs(int u){
    vis[u]=1;
    for(int x:adj[u]){
        if(vis[x]==0){
            if(x == target){
                can=1;
                return;
            }else {
                vis[x]=2;
                dfs(x);
            }
        }else if(vis[x]==1) continue;
        else return;
    }
}
void solve() {

    int n;cin>>n>>target;
    for(int i=1;i<=(n-1);i++){
        int a;cin>>a;
        adj[i].push_back(i+a);
    }
    dfs(1);

    cout<<(can==1 ? "YES":"NO");   
    
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
