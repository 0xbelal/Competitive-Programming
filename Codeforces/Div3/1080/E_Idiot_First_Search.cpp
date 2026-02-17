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



const int N = 300005;
const ll mod = 1e9 + 7;

int L[N], R[N];
ll sub_time[N], total_time[N];

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> L[i] >> R[i];

    vector<int> order;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.pb(u);
        if (L[u]) q.push(L[u]);
        if (R[u]) q.push(R[u]);
    }

    vector<int> rev_order = order;
    reverse(all(rev_order));

    for (int u : rev_order) {
        if (!L[u] && !R[u]) {
            sub_time[u] = 1;
        } else {
            sub_time[u] = (sub_time[L[u]] + sub_time[R[u]] + 3) % mod;
        }
    }

    total_time[1] = sub_time[1];
    for (int u : order) {
        if (L[u]) {
            total_time[L[u]] = (total_time[u] + mod - 1) % mod;
            total_time[R[u]] = (total_time[u] + mod - (sub_time[L[u]] + 2) % mod) % mod;
        }
    }

    vector<ll> res_vec(n + 1);
    for (int i = 1; i <= n; i++) res_vec[i] = total_time[i];
    cout << res_vec << endl;
}

int main() {
    fast_io;
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}