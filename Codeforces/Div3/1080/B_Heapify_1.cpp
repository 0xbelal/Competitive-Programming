/*
                                         ......  
                                      ..:::^^^^^. 
                                   .::^^^^^^:^^:. 
                                .:^^~~~^^~~~^:^:  
                             .:^~~^^::.:^~~~^~^   
                      .....:^^^^::.     :^~^^:    
                   ::^^^^^~~^^^::.      ^~~^:     
                .:^^:^^^^~^^^^~^^:^.   ^~^^:      
              .:^^^^^^^^~^~~^~~^^^^^:.^~^^.       
             .^^:::^^^^~!!~~~~~~^^:^^^~^:.        
            .^^:^^^^^^~!!^^~~~^^^^^:^^:.          
            :^^^~^^^~~~!^^^~^^^^^^^^^:            
            :^^~^^~~~^~~~~~~~^^^^^^^^:            
           :^~~^^^^~~~~^^^~~~~^^^^:^:.            
         .^~~::^~~~~~^^^^^~~^^^^^^^:.             
        :^~~..^^^^^^^^^^^^^^^^:^:::.              
      .^^~~.  .^^^^:^^^^^^^^^^:::.                
     :^^~^.     .:::::^^^^^^::..                  
    :^^~~:      ..^^^:....:.                      
   :^^~~^^:..:^^~~^^..                            
  .^^^~~~~^^~^~~^:.                               
  :^^^^^^^~~^::.                                  
  :^^^^^^:...                                     
  .:.....                                         
*/
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

vector<vector<int>> adj;
vector<bool> visited;
vector<int> comp_indices, comp_values;
vector<int> a;

void dfs(int u) {
    visited[u] = true;
    comp_indices.push_back(u);
    comp_values.push_back(a[u]);

    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

void solve() {
    int n;
    cin >> n;

    a.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];

    adj.assign(n + 1, {});
    visited.assign(n + 1, false);

    for(int i=1;i<=n;i++) {
        if (2 * i <= n) {
            adj[i].push_back(2 * i);
            adj[2 * i].push_back(i);
        }
    }
       for(int i=1;i<=n;i++) {
        if (!visited[i]) {
            comp_indices.clear();
            comp_values.clear();
            dfs(i);
            vector<int> need=comp_indices;
            sort(comp_values.begin(), comp_values.end());
            sort(need.begin(), need.end());

            if (comp_values != need) {
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
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
