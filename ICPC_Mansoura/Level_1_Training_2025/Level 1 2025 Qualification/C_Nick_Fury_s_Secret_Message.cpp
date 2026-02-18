// belal_cp_temp
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;


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

    string s;
    cin>>s;

    set<char> Lowervowels = {'a','o','y','e','u','i'};
    set<char>Uppervowe ={'A','O','Y','E','U','I'};
    
    string result="";

    for (char c : s) {
        if (Lowervowels.count(c) == false && Uppervowe.count(c)==false) {
            
            result += '.';
            result += tolower(c);
        }
    }

    cout << result << "\n";
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
