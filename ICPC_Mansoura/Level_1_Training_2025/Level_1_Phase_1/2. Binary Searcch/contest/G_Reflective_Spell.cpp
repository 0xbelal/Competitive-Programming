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

    string s;cin>>s;

    vector<int> freq(26, 0);
    for (char c : s) freq[c - 'a']++;
    
    int n = s.size();
    string ans(n, '.');

    int l = 0, r = n - 1;
    lp(i,26){
        while (freq[i] >= 2) {
            ans[l++] = 'a' + i;
            ans[r--] = 'a' + i;
            freq[i] -= 2;
        }
    }
    lp(i,26){
        if (freq[i] == 1) {
                ans[n / 2] = 'a' + i;
                break;
        }
    }

    cout << ans << "\n";
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
