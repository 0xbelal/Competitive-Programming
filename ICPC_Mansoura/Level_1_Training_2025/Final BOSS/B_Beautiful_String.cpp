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

bool is_palindrome(const string& s) {
    int l = 0, r = s.size() - 1;
    while ( l < r){
        if (s[l] != s[r]) return false;
        ++l;
        --r;
    }
    return true;
}

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    if (is_palindrome(s)) {
        cout << "0\n";
        return;
    }

    string x1;
    vector<int> p1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') x1 += '1';
        else p1.push_back(i + 1);
    }
    if (is_palindrome(x1)) {
        cout << p1.size() << "\n";
        for (int i = 0; i < (int)p1.size(); ++i) {
            if (i) cout << " ";
            cout << p1[i];
        }
        cout << "\n";
        return;
    }

    string x2;
    vector<int> p2;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') x2 += '0';
        else p2.push_back(i + 1);
    }
    if (is_palindrome(x2)) {
        cout << p2.size() << "\n";
        for (int i = 0; i < (int)p2.size(); ++i) {
            if (i) cout << " ";
            cout << p2[i];
        }
        cout << "\n";
        return;
    }

    cout << -1 << "\n";
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
