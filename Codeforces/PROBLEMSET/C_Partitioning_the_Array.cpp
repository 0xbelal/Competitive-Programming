/* Deliberate practice > blind repetition */
// Author: Belal
// URL: https://codeforces.com/contest/1920/problem/C


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

    int n; cin >> n;
    vector<int> a(n); cin >> a;
    set<int> divis;
    int ans = 0;
    for(int i = 1; i * i <= n; i++){
        if (n % i == 0){
            divis.insert(i);
            if(n / i != i) divis.insert(n / i);
        }
    }

    for(int k : divis){
        int gcd = 0;
        for(int i = 0; i < k; i++){
            for(int j = i + k; j < n; j += k){
                gcd = __gcd(gcd,abs(a[j] - a[j-k]));  
            }
        }
        if (gcd == 0 || gcd > 1) ans++;
    }
    cout<< ans <<"\n";
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
