// belal_cp_temp
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;


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
    vector<int> arr(n);
    unordered_map<int, int> freq;

    int max_freq= 0;

    for (int &x : arr) {
        cin >> x;
        freq[x]++;
        if (freq[x] > max_freq)max_freq = freq[x];
    }

    cout << max_freq << "\n";

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
