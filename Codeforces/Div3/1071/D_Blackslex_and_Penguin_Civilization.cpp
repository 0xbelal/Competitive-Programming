// belal_cp_temp
/*                                         ......  
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
#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define vec vector
#define pb push_back
#define INF INT_MAX
#define se second
#define fi first
#define pii pair<int, int>
#define pil pair<int, long long>
#define pli pair<long long, int>
#define pll pair<long long, long long>
#define str string
#define yes cout << "YES\n";
#define no cout << "NO\n";

using ll = long long;
using ull = unsigned long long;
using ui = unsigned int;

const int MOD = 1000000007;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxx(v) *max_element(v.begin(), v.end())
#define minn(v) *min_element(v.begin(), v.end())

using namespace std;

void solve() {
    int n; 
    cin >> n;

    static bool in = false;
    static vec<vec<int>> ps;

    if (!in) {
        ps.assign(17, {});
        ps[0] = {0};
        for (int i = 1; i <= 16; i++) {
            vec<int> v;
            v.reserve(1LL << i);
            for (int x : ps[i - 1]) v.pb(x * 2 + 1);
            for (int x = 0; x < (1LL << i); x += 2) v.pb(x);
            ps[i] = move(v);
        }
        in = true;
    }

    for (int x : ps[n]) cout << x << " ";
    cout << endl;
}

signed main() {
    #ifdef LOCAL
    freopen("a2.txt","r", stdin);
    freopen("a2.txt","w", stdout);
    #endif LOCAL
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    for (int i = 0; i < t; i++)
        solve();
}
