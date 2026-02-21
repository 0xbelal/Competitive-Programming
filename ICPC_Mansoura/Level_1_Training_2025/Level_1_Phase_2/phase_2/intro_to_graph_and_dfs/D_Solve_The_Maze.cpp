/* Deliberate practice > blind repetition */
// Author: Belal
// URL: https://codeforces.com/problemset/problem/1365/D


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
#include <cstring>

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
const int N=55;
int n,m;
char maze[N][N];
bool vis[N][N];
bool has_good=false;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};


bool valid(int x,int y){
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];

        if(maze[nx][ny] == 'B')return false;
    }
    return true;
}


void dfs(int x,int y){
    vis[x][y] =1;
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];

        if(((nx >= 1 && nx <= n && ny >= 1 && ny <= m)) && maze[nx][ny]!='#' && !vis[nx][ny])dfs(nx,ny);
    }
}
void solve() {

    cin>>n>>m;
    has_good=false;
    memset(vis, false, sizeof(vis));
    
   for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
        cin>>maze[i][j];
        if(maze[i][j]=='G'){
            has_good=true;
            // if(!valid(i,j)){
            //     cout<<"No\n";return;
            // }
    
        }
    }
   }
   if(!has_good) {cout<<"Yes\n";return;}

//    int falg=0;
//    for(int i=0;i<4;i++){
//         int nx=n+dx[i];
//         int ny=m+dy[i];

//         if(maze[nx][ny] == 'B')falg++;
//     }

//     if(falg==4){cout<<"No\n";return;}

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(maze[i][j]=='B'){
                for(int x=0;x<4;x++){
                    int nx=i+dx[x];
                    int ny=j+dy[x];
                    
                    if( (nx >= 1 && nx <= n && ny >= 1 && ny <= m)) {
                        if(maze[nx][ny] == 'G' ){cout<<"No\n";return;}
                    
                        if(maze[nx][ny]=='.')maze[nx][ny] = '#' ;
                    }
                }
            }
        }
   }

   if(maze[n][m]!='#') dfs(n,m);
   
   for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(maze[i][j]=='G'){
               if(!vis[i][j]){cout<<"No\n";return;}
            }else if(maze[i][j]=='B' && vis[i][j]){cout<<"No\n";return;}
        }
    }
    cout<<"Yes\n";


    
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
