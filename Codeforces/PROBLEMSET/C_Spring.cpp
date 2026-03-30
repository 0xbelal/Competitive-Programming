/* Deliberate practice > blind repetition */
// Author: Belal
// URL: https://codeforces.com/contest/2204/problem/C


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
#include <numeric>
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

 /*  a = 3 + 3 + 2 + 3 + 3 = 1
        1     b 
        2  a  b
        3     b  c
        4  a  b 
        5     b
        6  a  b  c
        7     b  
        8  a  b
        9     b  c
        10 a  b  
*/ 
/*

    a + 2a + 3a + ... = x * a = y * b = z
    z = y * b >> b  = z/y
    x = z/a
    x = y*b/a

    a, b, c, m = 2 4 5  16
        1  
        2   a
        3  
        4   a  b
        5         c
        6   a
        7    
        8   a  b
        9  
        10  a     c
        11
        12  a  b
        13
        14  a
        15        c
        16  a  b
*/

ll LCM(ll a, ll b){
    return (a / std::gcd(a,b)) * b;
}
void solve() {

    ll a,b,c,m; cin >> a >> b >> c >> m;
    ll aa = m/a, bb = m/b, cc = m/c;
    
    ll abc = (m / LCM(a,LCM(b,c)));
    ll ab  = (m / LCM(a,b)) - abc;
    ll ac  = (m / LCM(a,c)) - abc;
    ll bc  = (m / LCM(b,c)) - abc;
    
    ll aans = 6*(aa - (abc + ab + ac)) + 3*ab + 3*ac + 2*abc;
    ll bans = 6*(bb - (abc + ab + bc)) + 3*ab + 3*bc + 2*abc;
    ll cans = 6*(cc - (abc + bc + ac)) + 3*bc + 3*ac + 2*abc;

    cout << aans << " " << bans << " " << cans << "\n"; 

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
