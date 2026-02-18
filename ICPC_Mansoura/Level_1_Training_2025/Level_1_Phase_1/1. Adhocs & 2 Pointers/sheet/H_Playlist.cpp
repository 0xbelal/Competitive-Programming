// belal_cp_temp
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
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


    /*
        - freqecuncy to know if the song is unique or not
        - l,r and loop on r and assume that the song is repeat if repeat increase l to stay on the pos that true
    */

    int n; cin >> n;
    vector<int> playlist(n); cin>>playlist;
    unordered_map<int,int> freq;
    
    int l = 0, long_seq = 0;

    for (int r = 0; r < n; r++) {
        freq[playlist[r]]++;

        while (freq[playlist[r]] > 1) {
            freq[playlist[l]]--;
            l++;
        }

        long_seq = max(long_seq, r - l + 1);
    }

    cout << long_seq << "\n";
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
