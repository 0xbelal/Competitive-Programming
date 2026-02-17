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


int min_swaps_group(const string& s, char c) {
    int n = s.size();
    int cnt = 0;

    // عدد الحروف c
    for (char x : s)
        if (x == c) cnt++;

    // لو صفر أو واحد → already grouped
    if (cnt <= 1) return 0;

    int bad = 0;

    // أول نافذة
    for (int i = 0; i < cnt; i++)
        if (s[i] != c) bad++;

    int ans = bad;

    // Sliding Window
    for (int i = cnt; i < n; i++) {
        if (s[i] != c) bad++;
        if (s[i - cnt] != c) bad--;
        ans = min(ans, bad);
    }

    return ans;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int res = min(
        min_swaps_group(s, 'a'),
        min_swaps_group(s, 'b')
    );

    cout << res << "\n";
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
