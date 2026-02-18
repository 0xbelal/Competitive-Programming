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

    int n,k; cin>>n>>k;
    vector<int> prefixsum(n+1,0);
    for(int i=1;i<=n;i++){
        char x; cin>>x;
        if(x == 'W')
         prefixsum[i] =1;

         prefixsum[i] += prefixsum[i-1];
    }

    int min_=n;

    for (int i = 1; i + k-1<= n; i++) {
        min_ = min(min_, prefixsum[i+k-1] - prefixsum[i-1]);
    }
    
    cout<<min_<<"\n";
    
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
