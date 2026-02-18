// belal_cp_temp
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <climits>
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


    /*
        - sort 
        - apply variable sliding window (the condition is (r-l < 1) if not loop to l++ until to achieve it)
    */
    ll n; cin>>n;
    ll m; cin>>m;
    vector<ll> flowers(n); cin>>flowers;

    sort(all(flowers));

    int l=0;
    ll max_sum = 0;
    ll sum=0;



     for (int r = 0; r < n; r++) {
        sum += flowers[r];
    
        while(l<n && (flowers[r] - flowers[l] > 1 || sum > m)){
            sum-= flowers[l++];
        }

        max_sum = max(max_sum,sum);


    
     }
     cout<< max_sum<<endl;
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
