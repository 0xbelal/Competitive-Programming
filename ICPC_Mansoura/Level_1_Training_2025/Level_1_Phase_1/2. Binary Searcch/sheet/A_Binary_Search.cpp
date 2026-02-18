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

ll binarySearch(ll x,const vector<ll> &arr){
    ll l=0,r=arr.size()-1,mid;

    while (l<=r)
    {

        mid = l + (r-l)/2;

        if(arr[mid] == x) return mid+1;
        if(arr[mid] > x)  r=mid-1;
        else if(arr[mid] < x)  l = mid + 1;
    }

    return -1;
    
}
void solve() {


    ll n,q; cin>>n>>q;
    vector<ll> arr(n); cin>>arr;

    while(q--){
        int x; cin>>x;
        cout<<binarySearch(x,arr)<<"\n";
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
