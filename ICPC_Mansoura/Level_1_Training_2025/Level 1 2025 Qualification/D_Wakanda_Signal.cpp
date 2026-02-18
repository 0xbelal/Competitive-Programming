// belal_cp_temp
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
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

ll getTotalSteps(int n){
    return 1LL*n*(n+1)/2;
}

void solve() {


    int n;cin >> n;
    ll tsteps = 0;

    for (int i = 0; i < n; ++i) {
        int ai;cin >> ai;
        tsteps += getTotalSteps(ai);
    }
    cout << tsteps / n << "\n";

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
