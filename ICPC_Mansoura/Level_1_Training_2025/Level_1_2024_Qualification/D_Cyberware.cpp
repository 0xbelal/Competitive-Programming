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

    int n,k,s; cin>>n>>k>>s;
 
    vector<int> digits;

    while(s != 0){
        int digit = s%10; 
        s/=10;

        digits.emplace_back(digit);
            
    }
    sort(all(digits));

    int ans = 0;
    for(int i=0;i<n-k;i++){
        ans *= 10;
        ans += digits[i];
    }

    cout<<ans;
}

int main() {
    fast_io;

    int t = 1;

    //cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
