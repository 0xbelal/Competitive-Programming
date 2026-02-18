// belal_cp_temp
//
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

    int n;cin>>n;
    string s; cin>>s;

    vector<int> dtask(26,0);
    
    for (char task : s) {
        dtask[task - 'A']++;
    }

    int tasks=0;

    int currentTaskTime =0;
    for(int i=0;i<26;i++){
        currentTaskTime=i+1;

        tasks += (dtask[i]>=currentTaskTime)? 1 : 0;
    
    }

    cout<<tasks<<endl;
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
