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
#include <climits>

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

        int n;cin>>n;

        vector<int> p1(n + 1), p2(n + 1);
        int xor1 = 0, xor2= 0;

        for (int i = 1; i <= n; ++i) {
            cin >> p1[i];
            xor1 ^= p1[i];
        }

        for (int i = 1;i<=n; ++i) {
            cin>> p2[i];  xor2 ^= p2[i];
        }

        if ((xor1 ^ xor2) == 0) {
            cout << "Tie\n";
            return;
        }

        int last_diff_idx = -1;
        for (int i = 1; i <= n; ++i) {
            if (p1[i] != p2[i]) last_diff_idx = i;
        }

        if (last_diff_idx == -1) {
            cout << "Tie\n";
        } else if (last_diff_idx % 2 == 1) {
            cout << "Ajisai\n";
        } else {
            cout << "Mai\n";
        }

    

}
int main() {
   
   fast_io;
   
    int t;cin>>t;

    while(t--) solve();
    return 0;
}