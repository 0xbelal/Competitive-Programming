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


void solve() {

   int n;cin>>n;
   vector<int>seq(n);cin>>seq;
   vector<int>p(6);
   for(int i=0;i<6;i++) p[i]=(seq[0]==i+1?0:1);
   for(int i=1;i<n;i++){
      vector<int>next_p(6,1e9);
      for(int cur=0;cur<6;cur++){
         int cost=(seq[i]==cur+1?0:1);
         for(int prev=0;prev<6;prev++){
            if(cur!=prev&&cur+prev!=5)next_dp[cur]=min(next_dp[cur],p[prev]+cost);
         }
   }
   p=next_dp;
   }
   int min_ops=1e9;
   for(int i=0;i<6;i++)min_ops=min(min_ops,p[i]);
   cout<<min_ops<<"\n";

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
