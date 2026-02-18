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

    ll x; cin>>x;
    ll l=1,r=x,mid,ans=0;

    while (l<=r)
    {

        mid = l + (r-l)/2;
        if (mid == x / mid && x % mid == 0) { 
            ans =mid;
            break;
        }
        else if (mid > x / mid) {  
            r = mid - 1;
        } 
        else {
            l = mid + 1;
        }

    }


    if(ans != 0) cout<<"YES" ;
    else cout<<"NO";

    
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
