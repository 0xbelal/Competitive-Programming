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
const int N=50;
vector<int> temp;
vector<vector<int>> comp_1;
vector<vector<int>> comp_2;
vector<vector<int>> comp_3;

vector<int>  adj[N];
bool vis[N];
int cnt;
int n,m;
int ones_comp,tows_comp;

void dfs(int u){
    vis[u]=true;

    for(int x:adj[u]){
        if(!vis[x]){
            dfs(x);
        }
    }
    temp.push_back(u);
}
void solve() {

    cin>>n>>m;
    if(m==0){
        for(int i=1;i<=n;i++){
            cout<<i<<" ";
            if(i%3==0) cout<<"\n";
        }
        return;
    }
    while (m--)
    {
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
            cnt++;
            if(temp.size()>=4){
                cout<<-1;
                return;
            }else if(temp.size()==3) comp_3.push_back(temp);
            else if(temp.size()==2){tows_comp++; comp_2.push_back(temp);}
            else { ones_comp++; comp_1.push_back(temp);}

            temp.clear();
        }
    }

    if(cnt==n){
        for(int i=1;i<=n;i++){
            cout<<i<<" ";
            if(i%3==0) cout<<"\n";
        }
        return;
    }

    if((tows_comp > ones_comp) || (ones_comp-tows_comp)%3 !=0 ){
        cout<<-1;return;
    }

    for(vector<int> x:comp_3){
        for(int i : x){
            cout<< i<<" ";
        }
        cout<<"\n";
    }
    
    int ptr1=0;
    for(int i=0;i<comp_2.size();i++){
        for(int x:comp_2[i])cout<<x<<" ";
        cout<<comp_1[i]<<"\n";
        ptr1++;
    }



    for(int i=ptr1;i<comp_1.size();i++){
        cout<<comp_1[i]<<" ";
        if(i%3==0) cout<<"\n";
    }
    return;


    
    
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
