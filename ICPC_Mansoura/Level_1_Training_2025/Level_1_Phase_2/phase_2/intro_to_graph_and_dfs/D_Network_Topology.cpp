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

const double EPS = (1e-7);

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, m;
vector<int> adj[N];
int vis[N];

map<string,string> ans{
    {"bus","bus topology"},
    {"ring","ring topology"},
    {"star","star topology"},
    {"unknown","unknown topology"}
};

void dfs(int u){
    vis[u] = 1;
    for(int v : adj[u]){
        if(!vis[v])
            dfs(v);
    }
}

void solve() {
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        adj[i].clear();
        vis[i] = 0;
    }

    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1);
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            cout << ans["unknown"];
            return;
        }
    }

    if(m == n){
        bool ok = true;
        for(int i = 1; i <= n; i++){
            if(adj[i].size() != 2){
                ok = false;
                break;
            }
        }
        if(ok){
            cout << ans["ring"];
            return;
        }
    }

    if(m == n - 1){
        int center = 0;
        bool star_ok=true,bus_ok= true;

        for(int i = 1; i <= n; i++){
            if(adj[i].size() == n - 1)
                center++;
            else if(adj[i].size() != 1)
                star_ok = false;
            
        }
        if(star_ok && center == 1){
            cout << ans["star"];
            return;
        }else{
            int start_end=0;
            for(int i = 1; i <= n; i++){
               if(adj[i].size() == 1){
                  start_end++;
                  if(start_end>2) bus_ok = false;
                 continue;
               }
              if(adj[i].size() != 2) bus_ok = false;
            }

         }
            
            if(bus_ok){ cout <<ans["bus"]; return;}
        }
    

    cout << ans["unknown"];
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
