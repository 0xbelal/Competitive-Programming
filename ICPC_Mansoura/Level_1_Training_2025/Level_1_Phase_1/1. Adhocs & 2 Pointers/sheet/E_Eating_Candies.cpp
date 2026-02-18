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


    int n; 
    cin >> n;
    vector<int> candies(n);
    for (int i = 0; i < n; i++) cin >> candies[i];

    int l = 0, r = n - 1;
    ll sumL = 0, sumR = 0;
    int max_candies = 0;

    while (l <= r) {
        if (sumL < sumR) {
            sumL += candies[l++];
        } else {
            sumR += candies[r--];
        }

        if (sumL == sumR) {
            int total = l + (n - 1 - r);
            max_candies = max(max_candies, total);
        }
    }

    cout << max_candies << "\n";
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
