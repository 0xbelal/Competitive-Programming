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

    int n,target; cin>>n>>target;

     vector<pair<int,int>> nums(n); 
    for(int i=0;i<n;i++){
        cin >> nums[i].first;
        nums[i].second = i + 1; 
    }

    sort(all(nums)); 

    int l = 0, r = n-1;
    while(l < r){
        long long sum = 1LL*nums[l].first + nums[r].first;

        if(sum == target){
            cout << min(nums[l].second,nums[r].second) << " " << max(nums[l].second,nums[r].second) << "\n";
            return;
        }
        else if(sum < target){
            l++;
        }
        else{
            r--;
        }
    }

    cout<<"IMPOSSIBLE\n";

    
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
