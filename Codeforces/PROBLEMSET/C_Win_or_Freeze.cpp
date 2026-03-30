/* Deliberate practice > blind repetition */
// Author: Belal
// URL: https://codeforces.com/contest/151/problem/C


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

vector<ll> factorization(ll q){
    vector<ll> primes;
    
    if (q == 1) return primes;

    for(ll d=1,i=2; i*i <= q && primes.size() <= 3; i += d,d = 2){
        while(q % i == 0) primes.push_back(i), q/=i;
    }

    if(q > 1)  primes.push_back(q);
    return primes;
}

void solve() {

    ll q;cin>>q;
    vector<ll> primes = factorization(q);

    if (primes.size() <= 1) cout << "1\n0";
    else if (primes.size() == 2) cout << "2";
    else  cout << 1 << "\n" << primes[0] * primes[1]; 
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
