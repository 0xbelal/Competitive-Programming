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



void solve() {
    int n, m;
    cin >> n >> m;

    vector<ll> add(m + 2, 0), diff(m + 2, 0);

    for (int i = 0;i<n; i++) {
        int l, r;
        ll p;
        cin>>l>>r>> p;
        add[l] += p;
        add[r + 1] -= p;

        diff[l] += -p*(l - 1);
        diff[r + 1] -=-p*(l - 1);
    }
    for (int i = 1; i <= m; i++) {
        add[i] += add[i - 1];
        diff[i] += diff[i - 1];
        cout << add[i] * i + diff[i] << " ";
    }

    cout << "\n";
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