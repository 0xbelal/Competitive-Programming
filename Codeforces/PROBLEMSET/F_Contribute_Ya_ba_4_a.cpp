/* Deliberate practice > blind repetition */
// Author: Belal
// URL: https://codeforces.com/group/reRlOrZJrU/contest/676893/problem/F

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
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    ll ans = 0;
    vector<int> next_greater(n), prev_greater(n);
    vector<int> next_smaller(n), prev_smaller(n);

    stack<int> mono_st;
    for(int i = 0; i < n; i++){

        while(!mono_st.empty() && a[mono_st.top()] <= a[i] )
            mono_st.pop();
        next_greater[i] = mono_st.empty() ? i + 1 : i - mono_st.top();
        mono_st.push(i);

    }
    
    while(!mono_st.empty()) mono_st.pop();
    for(int i = n - 1; i >= 0; i--){
        while(!mono_st.empty() && a[mono_st.top()] < a[i]) mono_st.pop();
        prev_greater[i] = mono_st.empty() ? n - i : mono_st.top() - i;
        mono_st.push(i);
    }

    while(!mono_st.empty()) mono_st.pop();
    for(int i = 0; i < n; i++){
        while(!mono_st.empty() && a[mono_st.top()] >= a[i]) mono_st.pop();
        next_smaller[i] = mono_st.empty() ? i + 1 : i - mono_st.top();
        mono_st.push(i);
    }

    while(!mono_st.empty()) mono_st.pop();
    for(int i = n - 1; i >= 0; i--){
        while(!mono_st.empty() && a[mono_st.top()] > a[i]) mono_st.pop();
        prev_smaller[i] = mono_st.empty() ? n - i : mono_st.top() - i;
        mono_st.push(i);
    }

    for(int i = 0; i < n; i++){
        ans += (ll)a[i] * next_greater[i] * prev_greater[i];
        ans -= (ll)a[i] * next_smaller[i] * prev_smaller[i];
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
