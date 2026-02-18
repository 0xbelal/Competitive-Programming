// belal_cp_temp
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <climits>
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

int calculateTime(const string& s) {
    if (s.empty()) return 0;
    int time = 2;
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == s[i-1]) {
            time += 1;
        } else {
            time += 2;
        }
    }
    return time;
}

void solve() {
    string s;
    cin >> s;
    
    int maxTime = 0;
    string res = s;
    
    // Try inserting at each position
    for (int pos = 0; pos <= s.size(); pos++) {
        // For each position, find the best character to insert
        char bestChar = 'a';
        
        // We want a character different from neighbors
        if (pos == 0) {
            // At the beginning: different from first character
            if (s.size() > 0) {
                bestChar = (s[0] == 'a') ? 'b' : 'a';
            }
        } else if (pos == s.size()) {
            // At the end: different from last character
            bestChar = (s[pos-1] == 'a') ? 'b' : 'a';
        } else {
            char left = s[pos-1];
            char right = s[pos];
            
            for (char c = 'a'; c <= 'z'; c++) {
                if (c != left && c != right) {
                    bestChar = c;
                    break;
                }
            }
            if (left == right) {
                bestChar = (left == 'a') ? 'b' : 'a';
            }
        }
        
        string temp = s.substr(0, pos) + bestChar + s.substr(pos);
        int time = calculateTime(temp);
        
        if (time > maxTime) {
            maxTime = time;
            res = temp;
        }
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