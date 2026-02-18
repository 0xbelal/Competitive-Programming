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
vector<bool> is_prime;

vector<bool> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] =is_prime[1] = false;
    vector<ll>primes;
    for (int i=2;i <= n; ++i) {
        if (is_prime[i]) primes.push_back(i);
        for (ll &p : primes) {
            if (i * p > n) break;
            is_prime[i * p] = false;
            if (i % p == 0) break;
        }
    }
    return is_prime;
}

vector<vector<int>> subsets(vector<int> &primes){

    vector<vector<int>> subsets = {{}};
    for (int x :primes ) {
        int sz = subsets.size();
        for (int i = 0; i < sz; i++) {
            vector<int> temp = subsets[i];

            temp.push_back(x);
            subsets.push_back(temp);
        }
    }
    return subsets;
}
void solve() {
    int n; cin >> n;
    if (n == 1){
        cout << -1;
        return;}

    is_prime = sieve(n);
    if (is_prime[n]) {
        cout << "1 1";
        return;}

    vector<int> primes;
    for (int i=2;i<=n; i++){
        if (is_prime[i]) 
        primes.push_back(i);
    }

    vector<vector<int>> allsub = subsets(primes);
    vector<vector<int>> valid;
    for(vector<int> x : allsub){
      ll sum=0;
       
       for(int i:x){
           sum+=i;
       }
       if(sum == n) valid.push_back(x);       
   }

    if (valid.empty()) {
        cout << -1;
        return;
    }

    int min_prime = INT_MAX, count = 0;
    for (vector<int> &v:valid) {
        min_prime = min(min_prime,(int)v.size());
    }
    for (vector<int>&v : valid) 
     {
        if ((int)v.size() == min_prime) count++;
    }

    cout << min_prime << " " << count << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
