/* Deliberate practice > blind repetition */
// Author: Belal
// URL: https://codeforces.com/group/MEqF8b6wBT/contest/673206/problem/C2


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

    int n;cin>>n;
    map<int,int> a;
    for(int i = 1;i <= n; i++){
        int x;cin>>x;
        a[x] = i;
    }

    set<int> holes;
    holes.insert(a[1]);
    int cost=0;
    for(int i = 2; i <= n; i++){
        int source = i-1, destination = i;

        auto it = holes.lower_bound(a[destination]);
        int min_cost = __INT_MAX__;
        if(it != holes.end()){
          min_cost = min (min_cost,abs (a[destination] - *it) );
        }
        if(it != holes.begin()){
          min_cost = min (min_cost,abs (a[destination] - *prev(it)) );
        }

        cost += min_cost;
        holes.insert(a[destination]);

        // int l = 1,r = n;
        // int mid=0, min_cost = actual_cost;
        // while(l <= r){
        //     mid = l + (r - l)/2;
        //     if(blocks[mid] == true){
        //         min_cost = min(min_cost, abs(a[destination] - a[mid]));
        //     }
        //     if(mid < a[destination]){
        //         l = mid + 1;
        //     }else{
        //         r = mid - 1;
        //     }
        // }
        // cost += min_cost;
        // blocks[destination] = true;
    }

    cout << cost;


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
