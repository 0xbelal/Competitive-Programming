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


#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define ff first
#define ss second


void solve() {
    int w,h,n; 
    cin >> w >> h >> n;

    vector<vector<int>> diff(w+2, vector<int>(h+2, 0));

    while (n--) {
        int x1,y1,x2,y2; 
        cin >> x1 >> y1 >> x2 >> y2;

        int xl = min(x1, x2);
        int xr = max(x1, x2);
        int yl = min(y1, y2);
        int yr = max(y1, y2);

        diff[xl][yl]     += 1;
        diff[xr+1][yl]   -= 1;
        diff[xl][yr+1]   -= 1;
        diff[xr+1][yr+1] += 1;
    }

    for (int i=1; i<=w; i++) {
        for (int j=1; j<=h; j++) {
            diff[i][j] += diff[i-1][j] + diff[i][j-1] - diff[i-1][j-1];
            // build prefix using one loop (pref[i][j] = a[i][j] + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] // this is to subtract the all left numbers thatwas sum)
        }
    }

    int counter = 0;
    for (int i=1; i<=w; i++) {
        for (int j=1; j<=h; j++) {
            if (diff[i][j] == 0) counter++;
        }
    }

    cout << counter << "\n";
}

int main() {
    fast_io;
    int t; 
    cin >> t;
    while (t--) solve();
    return 0;
}
