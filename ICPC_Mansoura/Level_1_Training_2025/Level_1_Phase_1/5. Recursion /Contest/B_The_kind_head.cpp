// belal_cp_temp
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
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
const ll MOD = 1e9 + 7;
ll fast_pow(ll base, ll exp, ll mod) {
    ll result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2== 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

ll modInv(ll a,ll mod) {
    return fast_pow(a, mod - 2, mod);
}

void solve() {
    int n;cin>>n;
    vector<int> a(n);cin>>a;
    int cnt_zeros = 0,zero_idx = -1;
    
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            cnt_zeros++;
            zero_idx = i;
        }
    }
    
    if (cnt_zeros >= 2) {
        for (int i = 0; i < n; i++) {
            cout << "0 ";
        }
        cout << "\n";
    } else if (cnt_zeros == 1) {
        long long product = 1;
        for (int i = 0; i < n; i++) {
            if (i != zero_idx) {
                product = (product * a[i]) % MOD;
            }
        }
        
        for (int i = 0; i < n; i++) {
            cout << (i == zero_idx ? product : 0) << " ";
        }
        cout << "\n";
    } else {
        for (int i = 0; i < n; i++) {
            long long product = 1;
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    product = (product * a[j]) % MOD;
                }
            }
            cout << product << " ";
        }
        cout << "\n";
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