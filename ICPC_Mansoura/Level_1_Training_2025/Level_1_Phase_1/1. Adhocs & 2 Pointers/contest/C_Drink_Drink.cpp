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

    int n , k , l , c , d , p , nl , np; cin>>n >>k>>l>>c>> d >>p>> nl >> np;
    /*
    
    Overall the friends have 4∗5=20
 milliliters of the drink, it is enough to make 20/3=6
 toasts. The limes are enough for 10∗8=80
 toasts and the salt is enough for 100/1=100
 toasts. However, there are 3 friends in the group, so the answer is min(6,80,100)/3=2
.
    
    */

    int ml = (k*l)/nl;
    int limes = c*d;
    int salt = p/np;
    cout<<min(ml,min(limes,salt))/n;
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
