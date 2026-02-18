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
void solve() {
    int n; cin>>n;
    
    vector<int> par(n+1);
    vector<vector<int>> children(n+1);
    int root= -1;
    
    for(int i=1;i<=n;i++){
        cin >> par[i];
        if(par[i] == i) root = i;
        else children[par[i]].push_back(i);
    }
    
    vector<vector<int>> paths;
    
    stack<pair<int,int>> st;
    paths.push_back({root});
    st.push({root, 0});
    
    while(!st.empty()){
        auto [u, pidx] = st.top(); st.pop();
        bool first = true;
        for(int child:children[u]){
            if(first){
                paths[pidx].push_back(child);
                st.push({child, pidx});
                first = false;
            } else {
                int newIdx = paths.size();
                paths.push_back({child});
                st.push({child, newIdx});
            }
        }
    }
    
    cout << paths.size() << "\n";
    for(auto& path : paths){
        cout << path.size() << "\n";
        for(int v : path) cout << v << " ";
        cout << "\n";
    }
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
