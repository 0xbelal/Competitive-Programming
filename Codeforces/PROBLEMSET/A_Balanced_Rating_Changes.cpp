/* Deliberate practice > blind repetition */
// Author: Belal
// URL: https://codeforces.com/contest/1237/problem/A


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
    vector<int> a(n),b(n);
    ll pos_sum = 0, neg_sum = 0;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        a[i] = x;
        x /= 2;
        if(x < 0) neg_sum += x; 
        if(x > 0) pos_sum += x; 
        b[i] = x;
    }

    int gap = pos_sum + neg_sum;
    if(gap > 0){
        for(int i = 0;gap > 0 && i < n; i++){
            if(a[i] < 0 && abs(a[i]) & 1) {
                b[i] -= 1;
                gap--;
            }
        }
    }else if(gap < 0){
        gap *= -1;
        for(int i = 0;gap > 0 && i < n; i++){
            if(a[i] > 0 && abs(a[i]) & 1) {
                b[i] += 1;
                gap--;
            }
        }
    }
    
    for(int x : b) cout << x << "\n";
    
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