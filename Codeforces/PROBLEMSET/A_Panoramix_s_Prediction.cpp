/* Deliberate practice > blind repetition */
// Author: Belal
// URL: https://codeforces.com/contest/80/problem/A


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

    int n,m;cin>>n>>m;
    bool ans = true;

    auto isPrime = [](int x) -> bool {
        if (x < 2) return false;
        if (x == 2) return true;
        if (x % 2 == 0) return false;    
        if (x == 3) return true;
        if (x % 3 == 0) return false;    

    
        for (int i = 5; (long long)i * i <= x; i += 6) {
            if (x % i == 0 || x % (i + 2) == 0) return false;
        }
        return true;
    };
    
    if(!isPrime(m)){ cout<<"NO"; return; }
    for(int i = n+1; i <= m ;i++){
        if(isPrime(i) && i != m){
            cout<<"NO";
            return;
        }
    }
    cout<<"YES"; 
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
