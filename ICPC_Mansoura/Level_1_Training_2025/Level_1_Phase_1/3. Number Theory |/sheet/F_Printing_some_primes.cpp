// belal_cp_temp
#include<set>
#include<map>
#include<list>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<complex>
#include<sstream>
#include<iostream>
#include<fstream>
#include<algorithm>
#include<assert.h>
#include <bitset>

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
const int N = 100000000;
bitset<N + 1> is_prime;

void sieve_sampled_primes() {
    is_prime.set();
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; 1LL * i * i <= N; ++i) {
        if (is_prime[i]) {
            for (long long j = 1LL * i * i; j <= N; j += i)
                is_prime[j] = false;
        }
    }
}

void solve() {
    sieve_sampled_primes();
    int cntr = 0;
    for (int i = 2; i <= N; ++i) {
        if (is_prime[i]) {
            ++cntr;
            if (cntr % 100 == 1)
                cout << i << '\n';
        }
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
