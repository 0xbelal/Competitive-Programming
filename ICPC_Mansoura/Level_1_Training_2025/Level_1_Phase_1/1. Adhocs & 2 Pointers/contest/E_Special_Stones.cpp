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
    int n;
    cin >> n;
    vector<vector<int>> LR(n,vector<int>(2));
    for (int i=0;i<n;i++) {
        cin >> LR[i][0]>>LR[i][1];
    }

    int MAX_SIZE= 2*n + 5;
    vector<int> Partial(MAX_SIZE,0), done(MAX_SIZE,0);
    for (vector<int>& v: LR) {
        Partial[v[0]] += 1;
        Partial[v[1]+1] -= 1;  
    }

  
    for (int i=1;i<MAX_SIZE;i++) {
        done[i] = done[i-1] + Partial[i];
    }
    string res;
    for (vector<int>& v: LR) {
        bool ok = true;
        for (int x=v[0]; x<=v[1]; x++) {
            if (done[x] == 1) {
                ok = false; 
                break;
            }
        }
        if(ok)
        res.push_back('1');
        else res.push_back('0');
    }
    cout << res << "\n";
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
