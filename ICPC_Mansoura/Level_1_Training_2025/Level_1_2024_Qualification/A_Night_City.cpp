#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

// Fast IO
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);

// Type shortcuts
using ll = long long;
using ull = unsigned long long;
using ld = long double;

// Constants
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

// Debug (only active in local builds)
#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x << " = " << x << "\n";
#else
    #define debug(x)
#endif

// Utility macros
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define ff first
#define ss second

// Custom functions
ll mod_add(ll a, ll b, ll m = MOD) { return (a % m + b % m) % m; }
ll mod_mul(ll a, ll b, ll m = MOD) { return (a % m * b % m) % m; }
ll mod_pow(ll a, ll b, ll m = MOD) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = mod_mul(res, a, m);
        a = mod_mul(a, a, m);
        b >>= 1;
    }
    return res;
}

void solve() {

    cout<<"Kareem Elgoker now has no authority, Adham is the new head and Samer is his vice.";
}

int main() {
    fast_io;

    solve();

    return 0;
}
