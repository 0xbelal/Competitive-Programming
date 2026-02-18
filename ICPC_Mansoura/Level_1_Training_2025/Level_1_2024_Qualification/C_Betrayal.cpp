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


bool isSatisfy(int x1,int x2,int x3){
    return (x3 != 0 && (x3-x2)==(x2-x1));
}

void solve() {

   
    int A,B; cin>>A>>B;

    set<int> possible;

    possible.insert(2*B-A);
    possible.insert(2*A-B);
    if((A+B)%2 == 0) possible.insert((A + B) / 2);

    cout<<possible.size();
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
