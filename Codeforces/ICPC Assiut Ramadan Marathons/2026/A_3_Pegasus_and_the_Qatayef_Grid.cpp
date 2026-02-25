/* Deliberate practice > blind repetition */
// Author: Belal
// URL: https://codeforces.com/group/MEqF8b6wBT/contest/673206/problem/A3



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
    vector<vector<int>> grid(n,vector<int>(m));
    int i=0,j=0;
    lp(i,n){
        j=0;
        lp(j,m){
            cin>>grid[i][j];
        }
    }
    ll max_prod=-1e18;
    vector<pair<int,int>> idxs;
    int dx[] = {0, 1, 1, 1}; 
    int dy[] = {1, 0, 1, -1};
    i=0,j=0;
    lp(i,n) {
       lp(j,m) {
            int d=0;
           lp(d,4) {
                int nr2 = i + dx[d]*3;
                int nc2 = j + dy[d]*3;
                if (nr2 >= 0 && nr2 < n && nc2 >= 0 && nc2 < m) {
                    ll current= 1;
                    vector<pair<int, int>> vcurrent;
                    int idx=0;
                    lp (idx,4) {
                        int curr_r= i+ dx[d]*idx;
                        int curr_c = j+ dy[d] * idx;
                        current*= grid[curr_r][curr_c];
                        vcurrent.push_back({curr_r + 1, curr_c + 1}); 
                    }

                    if (current > max_prod) {
                        max_prod = current;
                        idxs = vcurrent;
                    }
                }
            }
        }
    }
    cout << max_prod << endl;
    for (int i = 0; i < 4; i++) {
        cout << idxs[i].first << " " << idxs[i].second << " ";
    }
    cout << endl;

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
