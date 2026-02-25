/* Deliberate practice > blind repetition */
// Author: Belal
// URL: https://codeforces.com/problemset/problem/510/C


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

const int N=26;
int n;
vector<int> adj[N];
int vis[N];
vector<char> topo_srt;
bool cyc;
bool dfs(int u) {
    vis[u] = 2;
    for (int v : adj[u]) {
        if (vis[v] == 2) return true; 
        if (vis[v] == 0) {
            if (dfs(v)) return true;
        }
    }
    vis[u] = 1; 
    topo_srt.push_back(u + 'a');
    return false;
}
void solve() {

    cin>>n;
    vector<string> names(n);
    for(int i=0;i<n;i++){
        string s;cin>>s;
        names[i] =(s);
    }
    for(int i=0;i<=n-2;i++){
       string a=names[i];
       string b=names[i+1];

       int min_len = min(a.length(),b.length());
       bool flag=false;

        
        for(int j=0;j <min_len;j++){
            if(a[j] != b[j]){
                flag=true;
                adj[a[j]-'a'].push_back(b[j]-'a');
                break;
            }
        }
        if(!flag && a.size() > b.size()){cout<<"Impossible\n"; return;}
    }

    for (int i = 0; i < 26; i++) {
        if (vis[i] == 0) {
            if (dfs(i)) {
                cout << "Impossible\n";
                return;
            }
        }
    }
    // reverse(all(topo_srt));
    for(char i:topo_srt)cout<<i;
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
