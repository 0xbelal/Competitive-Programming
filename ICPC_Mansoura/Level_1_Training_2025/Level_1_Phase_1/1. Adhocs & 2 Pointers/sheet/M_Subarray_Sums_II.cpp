// belal_cp_temp

/*
    url : https://vjudge.net/contest/751410#problem/M
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <cstdint>
#include <chrono>

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

    int n,target; cin>>n>>target;
    vector<ll> nums(n); cin>>nums;

    map<ll,int> freq;
    freq[0] = 1; 
    ll no_subarr=0;
    ll sum=0;
    for (int i = 0;i<n; i++)
    {
        sum += nums[i];

        if(freq.find(sum-target) != freq.end()){
            no_subarr += freq[sum-target];
        }

        freq[sum]++;

    }
    
   
    cout<<no_subarr;
    
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
