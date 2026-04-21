/* Deliberate practice > blind repetition */
// Author: Belal
// URL: https://codeforces.com/gym/100883/problem/I


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
/*
XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
*/
ll get_dis(pair<int,int> p, int x, int y){ return sqrt(pow(p.first - x ,2) + pow(p.second - y ,2)); }
void solve() {
    int n; cin >> n;
    vector<pair<int,pair<int,int>>> p(n);
    for(int i = 0; i < n; i++) cin >> p[i].second.first >> p[i].second.second >> p[i].first;  
    int Xs, Ys, Xe, Ye; cin >> Xs >> Ys >> Xe >> Ye;

    sort(all(p), [](const auto& a, const auto& b) {
        ll distA = 1LL * a.second.first * a.second.first + 
                   1LL * a.second.second * a.second.second;
        ll distB = 1LL * b.second.first * b.second.first + 
                   1LL * b.second.second * b.second.second;
        return distA < distB; 
    });


    ll sidx = -1,min_sdisc = 4e18, eidx = -1, min_edisc = 4e18;
    for(int i = 0; i < n; i++){
        ll start_diff = get_dis(p[i].second, Xs,Ys);
        ll end_diff = get_dis(p[i].second, Xe,Ye);
        if (start_diff < min_sdisc) {
            min_sdisc = start_diff;
            sidx = i;
        }
        if (end_diff < min_edisc) {
            min_edisc = end_diff;
            eidx = i; 
        }
    }

    ll ans = min_sdisc + min_edisc + abs(eidx - sidx);
    ll direct_dist = (ll)ceil(sqrt(get_dis({Xs, Ys}, Xe, Ye)));
    cout << min(ans,direct_dist);
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
