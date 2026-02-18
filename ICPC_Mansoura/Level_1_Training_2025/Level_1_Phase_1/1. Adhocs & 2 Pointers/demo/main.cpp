// belal_cp_temp
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;


#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);

using ll = long long;
using ull = unsigned long long;
using ld = long double;


#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define ff first
#define ss second


void solve() {

}


ll get_quiry(int x1,int y1,int x2,int y2,vector<vector<int>> a){
    return a[x2][y2] - a[x1-1][y2] - a[x2][y1-1] + a[x1-1][y1-1];
}

int main() {
    
    fast_io;

    int n,q; cin>>n>>q;

    vector<vector<char>> a(n+1,vector<char>(n+1));  
    vector<vector<int>> p(n+1,vector<int>(n+1)) ;
    


    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            char c;
            cin>>c;
            p[i][j] = ((c=='*') ? 1: 0);
        }
    }


    
    
    for(int i=1;i<=n;i++){

        for(int j=1;j<=n;j++){

            p[i][j] += p[i][j-1];
        }
    }
    
    for(int i=1;i<=n;i++){

        for(int j=1;j<=n;j++){
            p[i][j] += p[i-1][j];
        }
    }

    while(q--){
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;

        cout<<get_quiry(x1,y1,x2,y2,p)<<endl;
    }

    return 0;
}