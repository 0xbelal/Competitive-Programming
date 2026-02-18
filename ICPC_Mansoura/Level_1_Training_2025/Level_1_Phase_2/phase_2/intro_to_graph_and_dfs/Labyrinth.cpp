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
int n,m;
const int N=1e3+5;

char arr[N][N]; 
string path="",v="";
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
string dir="RLDU";
int sx,sy;
bool vis[N][N],flag;

bool valid(int x,int y){
   return x<n && x>=0 && y<m && y>=0 && !vis[x][y] && arr[x][y]!='#';
}
void dfs(int x,int y){
   
   
   if(arr[x][y] =='B') { 
      if (path=="") path=v;
      else if(path.size() > v.size()) path =v;
      flag=true;
      
   }

   vis[x][y]=true;
   
   for(int i=0;i<4;i++){
      int nx= x+dx[i], ny= y+dy[i];
      if(valid(nx,ny)) {
         v.push_back(dir[i]);
         dfs(nx,ny);
         v.pop_back();
      }
   }
   
   vis[x][y]=false;

}
void solve() {

   cin>>n>>m;
   for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
         cin>>arr[i][j];
         if(arr[i][j] == 'A') sx=i,sy=j;
      }
   }
   
   dfs(sx,sy);
   if (flag) cout<< "YES\n"<< path.size() << "\n" << path;else cout << "NO";
    
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
