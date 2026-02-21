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
const int N=500+5;
int n,m,k,s,ke;
vector<vector<char>> a(N,vector<char>(N));
bool vis[N][N];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

bool valid(int nx,int ny){
    return (nx>=1 && nx<=n && ny>=1 && ny<=m && a[nx][ny]=='.' && !vis[nx][ny]);
}
void dfs(int x,int y){
    if(ke<=0) return;
    vis[x][y]=true;
    ke--;
    a[x][y]='v';

    for(int i=0;i<4;i++){
        int n_x=x+dx[i];
        int n_y=y+dy[i];
        if(valid(n_x,n_y)){ if(ke>0) dfs(n_x,n_y);}
    }

}

void solve() {  

    cin>>n>>m>>k;
    int pos_x=-1,pos_y=-1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            if(a[i][j]=='.'){
                s++;
                if(pos_x==-1 && pos_y==-1){pos_x=i; pos_y=j;}
            }
        }   
    }
    ke=s-k;
    if(pos_x!=-1){
        dfs(pos_x,pos_y);
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]=='.'){
                cout<<'X';
            }else if(a[i][j]=='v') cout<<'.';
            else cout<<a[i][j];
        }   
        cout<<"\n";
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
