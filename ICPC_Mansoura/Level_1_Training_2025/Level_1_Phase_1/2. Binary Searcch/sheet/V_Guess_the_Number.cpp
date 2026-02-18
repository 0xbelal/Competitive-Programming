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


    int l = 1, r = 1e6, mid, ans;
    while (l <= r){
        mid = l + (r - l) / 2;
        cout << mid << '\n';
        cout.flush();
        string response;
        cin >> response;
        if(response == ">="){
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << "! " << ans << "\n";
    cout.flush();
    
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
