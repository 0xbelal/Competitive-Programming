// // belal_cp_temp
// /*                                         ......  
//                                       ..:::^^^^^. 
//                                    .::^^^^^^:^^:. 
//                                 .:^^~~~^^~~~^:^:  
//                              .:^~~^^::.:^~~~^~^   
//                       .....:^^^^::.     :^~^^:    
//                    ::^^^^^~~^^^::.      ^~~^:     
//                 .:^^:^^^^~^^^^~^^:^.   ^~^^:      
//               .:^^^^^^^^~^~~^~~^^^^^:.^~^^.       
//              .^^:::^^^^~!!~~~~~~^^:^^^~^:.        
//             .^^:^^^^^^~!!^^~~~^^^^^:^^:.          
//             :^^^~^^^~~~!^^^~^^^^^^^^^:            
//             :^^~^^~~~^~~~~~~~^^^^^^^^:            
//            :^~~^^^^~~~~^^^~~~~^^^^:^:.            
//          .^~~::^~~~~~^^^^^~~^^^^^^^:.             
//         :^~~..^^^^^^^^^^^^^^^^:^:::.              
//       .^^~~.  .^^^^:^^^^^^^^^^:::.                
//      :^^~^.     .:::::^^^^^^::..                  
//     :^^~~:      ..^^^:....:.                      
//    :^^~~^^:..:^^~~^^..                            
//   .^^^~~~~^^~^~~^:.                               
//   :^^^^^^^~~^::.                                  
//   :^^^^^^:...                                     
//   .:.....                                         
// */
// #include<set>
// #include<map>
// #include<list>
// #include<iomanip>
// #include<cmath>
// #include<string>
// #include<vector>
// #include<queue>
// #include<stack>
// #include<complex>
// #include<sstream>
// #include<iostream>
// #include<fstream>
// #include<algorithm>
// #include<assert.h>

// using namespace std;


// template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
// template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }

// #define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);

// using ll = long long;
// using ull = unsigned long long;
// using ld = long double;

// #define all(v)				((v).begin()), ((v).end())
// #define sz(v)				((int)((v).size()))
// #define rep(i, v)		for(int i=0;i<sz(v);++i)
// #define lp(i, n)		for(int i=0;i<(int)(n);++i)
// #define lpi(i, j, n)	for(int i=(j);i<(int)(n);++i)
// #define lpd(i, j, n)	for(int i=(j);i>=(int)(n);--i)
// #define rall(x) (x).rbegin(), (x).rend()
// #define pb push_back
// #define ff first
// #define ss second

// const double EPS = (1e-7);

// ll N = 1e6+10;
// vector<ll> primes_g;
// vector<ll> sieve(ll n){
//    vector<ll> primes;
//    vector<bool> is_prime(n+1,true);
//    is_prime[0]=is_prime[1]=false;

//    for(ll i=2; i<=n ; i++ ){

//       if (is_prime[i]) primes.push_back(i);
//         for (ll &p : primes) {
//             if (i * p > n) break;
//             is_prime[i * p] = false;
//             if (i % p == 0) break;
//       }
//    }

//    return primes;
// }


// vector<ll> prime_factorization(ll n,vector<ll> &primes){
//    vector<ll> facts;
//    for(ll p : primes){
//       if(p * p > n) break;

//       while(n % p == 0){
//          facts.pb(p);
//          n/=p;
//       }
//    }
//    if(n>1) facts.pb(n);
//    return facts;
// }

// void solve() {

//    int q; cin>>q;
//    primes_g = sieve(N);

//    while(q--){

//       ll n;cin>>n;
//       vector<ll> res = prime_factorization(n,primes_g);

//       for(ll &x : res) cout<<x<<" ";
//       cout<<"\n";
//    }
    
// }

// int main() {
//     fast_io;

//     int t = 1;
//     //cin >> t;
//     while (t--) {
//         solve();
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10 , M = 2;


vector<int> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    vector<int> primes;
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
        for (int p : primes) {
            if (i * p > n) {
                break;
            }
            is_prime[i * p] = false;
            if (i % p == 0) {
                break;
            }
        }
    }
    return primes;
}

vector<int> prime_factorization(int n, vector<int>& primes) {
    vector<int> ret;
    for (int i = 0; i < (int)primes.size(); ++i) {
        if (primes[i] * primes[i] > n) {
            break;
        }
        while (n % primes[i] == 0) {
            n /= primes[i];
            ret.push_back(primes[i]);
        }
    }
    if (n != 1) {
        ret.push_back(n);
    }
    return ret;
}

void solve()
{

    vector <int> primes = sieve(1e6 + 1);
    int q; cin >> q;

    while (q--) {
        int n; cin >> n;
        auto ans = prime_factorization(n , primes);
        sort(ans.begin(), ans.end());

        for (int i : ans) cout << i << ' ';
        cout << '\n';
    }

}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);


    int testCases = 1;
    //  cin >> testCases;
    for (int testCase = 1 ; testCase <= testCases ; ++testCase){
        solve();
    }
}