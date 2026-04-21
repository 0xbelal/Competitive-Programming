/* Deliberate practice > blind repetition */
// Author: Belal
// URL: https://codeforces.com/contest/2218/problem/D


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
const int N =  1e6 + 5;
vector<bool>isPrime(N,true);vector<ll>pre;
void sieve()
{
    isPrime[0]=isPrime[1]=0;
    for(ll i=2;i<N;i++)
    {
        if(isPrime[i]==1) pre.push_back(i);
        for(ll o=0;o<pre.size();o++)
        {
            if(i*pre[o]>=N) break;
            isPrime[i*pre[o]]=0;
            if(i%pre[o]==0) break;
        }
    }
}
void solve() {
    int n; cin >> n;
    for(int i = 1; i <= n; i++) cout << pre[i] * pre[i -1] << " ";
    cout << "\n";
}

int main() {
    fast_io;

    int t = 1;
    sieve();
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
