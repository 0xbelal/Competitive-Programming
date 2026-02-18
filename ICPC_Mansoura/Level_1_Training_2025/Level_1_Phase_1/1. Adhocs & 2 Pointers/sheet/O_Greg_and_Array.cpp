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


void solve() {

    int n,m,k; cin>>n>>m>>k;
    vector<ll> arr(n); cin>>arr;
    vector<ll> partial(n+2,0); 

    vector<vector<ll>> operations(m+1,vector<ll>(4));
    vector<ll> operations_freq(m+2,0);

    
    for(int i=1;i<=m;i++){
        for (int j = 1; j <=3; j++)
        {
            cin>> operations[i][j];
        }
        
    }

    for (int i = 1; i <= k; i++)
    {
        int x,y; cin>>x>>y;
        operations_freq[x]+=1;
        operations_freq[y+1]-=1;
    }

    for(int i=1;i<=m;i++){
        operations_freq[i] += operations_freq[i-1];
        if (operations_freq[i] == 0) continue;
        partial[operations[i][1]] += operations_freq[i]*operations[i][3];
        partial[operations[i][2]+1] -= operations_freq[i]*operations[i][3];
    }

    for (int i = 1; i <= n; i++)
    {
        partial[i] += partial[i-1];
    }
    
    for (int i = 0; i < n; i++)
    {
        arr[i] += partial[i+1];
        cout<<arr[i]<<" ";
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
