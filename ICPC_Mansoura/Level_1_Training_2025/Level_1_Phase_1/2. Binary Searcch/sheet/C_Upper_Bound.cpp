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

ll UpperBound(ll x,const vector<ll> &arr){

    ll l=0,r=arr.size()-1,mid,ans=-1;
    while (l<=r)
    {

        mid = l + (r-l)/2;

        if(arr[mid] > x){
            ans = mid;
            r=mid-1;
        }else{
            l = mid+1;
        }
    }

    return ((ans==-1)? -1 : ans+1);
    
}
void solve() {


    ll n,q; cin>>n>>q;
    vector<ll> arr(n); cin>>arr;

    while(q--){
        int x; cin>>x;
        cout<<UpperBound(x,arr)<<"\n";
        // auto it = lower_bound(all(arr), x);
        // if (it != arr.end()) cout << (it - arr.begin())+1 << '\n';
        // else cout << "-1\n";
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
