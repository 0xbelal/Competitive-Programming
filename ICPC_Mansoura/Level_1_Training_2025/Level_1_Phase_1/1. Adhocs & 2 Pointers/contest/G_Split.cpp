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
    int n; cin >> n;
    if (!n) return;

    vector<ll> nums(n+1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
        nums[i] += nums[i-1]; 
    }

    ll max_sum = 0;
    int l = 0, r = n;  

    while (l <= r) {
        ll sum1 = nums[l];            
        ll sum3 = nums[n] - nums[r];

        if (sum1 == sum3) {
            max_sum = max(max_sum, sum1);
            l++; r--; 
        } else if (sum1 < sum3) {
            l++;
        } else {
            r--;
        }
    }

    cout << max_sum << "\n";
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
