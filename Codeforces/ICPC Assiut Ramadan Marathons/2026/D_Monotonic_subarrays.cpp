/* Deliberate practice > blind repetition */
// Author: Belal
// URL: https://codeforces.com/group/reRlOrZJrU/contest/676893/problem/D


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

template<class T>
template<class T>
struct SparseTable {
    static const int B = 21;

    vector<array<T,B>> t;
    vector<int> lg;

    SparseTable(int n , vector<T> &v): t(n), lg(n+1){

        for(int i=2;i<=n;i++)
            lg[i] = lg[i/2] + 1;

        for(int i=0;i<n;i++)
            t[i][0] = v[i];

        for(int j=1;j<B;j++)
            for(int i=0;i+(1<<j)<=n;i++)
                t[i][j] = merge(
                    t[i][j-1],
                    t[i + (1<<(j-1))][j-1]
                );
    }

    T merge(const T& l,const T& r){
        return __gcd(l,r);
    }

    T query(int l,int r){
        int j = lg[r-l+1];
        return merge(
            t[l][j],
            t[r-(1<<j)+1][j]
        );
    }
};
void solve() {

    int n;cin>>n;
    vector<int> a(n);cin>>a;
    
    while(q--){
        int x;cin>>x;   
    }
    cout<<pre<<endl<<suff;

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
