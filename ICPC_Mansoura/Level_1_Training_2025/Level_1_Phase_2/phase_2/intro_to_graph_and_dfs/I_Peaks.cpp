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


void solve() {
    int n,m;cin>>n>>m;
    vector<int> h(n+1);
    for (int i=1;i<=n;i++)cin>>h[i];
    
    vector<vector<int>> adj(n+1); 
    
    while (m--) {
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans=0;
    for (int i=1;i<=n;i++) {
        bool is_good = true;
        for (int neighbor : adj[i]) {
            if (h[i] <= h[neighbor]) {
                is_good = false;
                break;
            }
        }
        if (is_good) ans++;
    }

    cout << ans;
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
