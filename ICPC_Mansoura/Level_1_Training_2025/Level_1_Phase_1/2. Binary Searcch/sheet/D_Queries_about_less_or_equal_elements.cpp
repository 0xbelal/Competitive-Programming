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

ll ans(ll x,const vector<ll> &arr){

    ll l=0,r=arr.size()-1,mid,cntr=-1;
    while (l<=r)
    {

        mid = l + (r-l)/2;

        if(arr[mid] <= x){
            cntr = mid;
            l=mid+1;
        }else{
            r = mid-1;
        }
    }

    return cntr+1;;
    
}
void solve() {


    ll n,k; cin>>n>>k;
    vector<ll> arr(n),q(k); cin>>arr>>q;
    sort(all(arr));

    for(ll & x: q){
        cout<<ans(x,arr)<<" ";
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
