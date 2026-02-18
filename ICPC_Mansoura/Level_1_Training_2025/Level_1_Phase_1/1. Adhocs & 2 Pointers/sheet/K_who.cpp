// belal_cp_temp
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;


template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);

using ll = long long;
using ull = unsigned long long;
using ld = long double;


#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define ff first
#define ss second

ll get_quiry(int x1,int y1,int x2,int y2,vector<vector<int>> p){

return p[x2][y2]-p[x1-1][y2]-p[x2][y1-1]+p[x1-1][y1-1];

}
void solve() {

    int n,m; cin>>n>>m;
    vector<vector<int>> prefix_A(n+1,vector<int>(m+1));
    vector<vector<int>> prefix_E(n+1,vector<int>(m+1));
    vector<vector<int>> prefix_C(n+1,vector<int>(m+1));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char c;  cin>>c;
                    
           prefix_A[i][j] = (c=='a');
           prefix_E[i][j] = (c=='e');
           prefix_C[i][j] = (c=='c');

        }
    }

 

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            
           prefix_A[i][j] += prefix_A[i][j-1] + prefix_A[i-1][j] -prefix_A[i-1][j-1];
           prefix_E[i][j] += prefix_E[i][j-1] + prefix_E[i-1][j] -prefix_E[i-1][j-1];
           prefix_C[i][j] += prefix_C[i][j-1] + prefix_C[i-1][j] -prefix_C[i-1][j-1];
            
        }
    }

    int q; cin>>q;

    while(q--){
        int r1,c1,r2,c2; cin>>r1>>c1>>r2>>c2;
        ll a = get_quiry(r1,c1,r2,c2,prefix_A);
        ll e = get_quiry(r1,c1,r2,c2,prefix_E);
        ll c = get_quiry(r1,c1,r2,c2,prefix_C);
       // cout<< min(, get_quiry(r1,c1,r2,c2,prefix_E),get_quiry(r1,c1,r2,c2,prefix_C))<<endl;
       cout<< min (min(a,e),c)<<endl;;
    }
    
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
