/* Deliberate practice > blind repetition */
// Author: Belal
// URL: 


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
    int rgb[3]; cin >> rgb[0] >> rgb[1] >> rgb[2];
    char colors[] = {'R', 'G', 'B'};
    // last_used stores the index in 'ans' where the color was last seen
    vector<int> last_used(3, -100); 
    string ans = "";
    
    while (true) {
        int best_idx = -1;
        
        for (int i = 0; i < 3; i++) {
            if (rgb[i] > 0) {
                int n = ans.length();
                // Check Rule 1 and Rule 2
                if (n >= 1 && ans[n-1] == colors[i]) continue;
                if (n >= 3 && ans[n-3] == colors[i]) continue;

                if (best_idx == -1) {
                    best_idx = i;
                } else {
                    // Tie-breaker logic:
                    // 1. Higher count wins.
                    // 2. If counts are equal, pick the one used longest ago.
                    if (rgb[i] > rgb[best_idx]) {
                        best_idx = i;
                    } else if (rgb[i] == rgb[best_idx]) {
                        if (last_used[i] < last_used[best_idx]) {
                            best_idx = i;
                        }
                    }
                }
            }
        }

        if (best_idx == -1) break;
        
        ans += colors[best_idx];
        last_used[best_idx] = ans.length(); // Update last used position
        rgb[best_idx]--;
    }
    cout << ans << "\n";
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
