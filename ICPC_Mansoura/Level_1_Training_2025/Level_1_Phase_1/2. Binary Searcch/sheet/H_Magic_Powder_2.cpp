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
bool can(ll x, const vector<ll>& a, const vector<ll>& b, ll k) {
    ll need = 0;
    for (int i = 0; i < (int)a.size(); i++) {
        ll required = a[i] * x;
        if (required > b[i]) {
            need += (required - b[i]);
            if (need > k) return false; 
        }
    }
    return need <= k;
}

void solve() {

    ll n,k; cin>>n>>k;
    vector<ll> grames(n),actual_grames(n); cin>>grames>>actual_grames;


    ll l=0,r=2e9,mid,ans;
    while (l<=r)
    {

        mid = l + (r-l)/2;
        if(can(mid,grames,actual_grames,k)){
            l = mid+1;
            ans=mid;
        }else{
            r = mid-1;
        }
    }


    cout<<ans;
    

    
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
