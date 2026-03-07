/* Deliberate practice > blind repetition */
// Author: Belal
// URL: https://codeforces.com/contest/208/problem/A


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

using namespace std;


template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define all(v)				((v).begin()), ((v).end())
#define sz(v)				((int)((v).size()))
void solve() {

    string s;cin>>s;
    string target="WUB";
    queue<int> vpos; //0 3  9
    // WUBWUBABCWUB
    int pos =s.find(target,0);
    while(pos != string::npos){
        vpos.push(pos);
        if(pos+3 < s.length()) pos=s.find(target,pos+3);
        else break;
    }
    bool flag=false;
    for(int i=0;i<s.length();){
        if(i== vpos.front()){
            vpos.pop();
            i+=3;
            if (flag) {flag=false;cout<<" ";}
        }else{
            cout<< s[i];
            flag=true;
            i++;
        }
    }
}

#define rep(i, v)		for(int i=0;i<sz(v);++i)
#define lp(i, n)		for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)	for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)	for(int i=(j);i>=(int)(n);--i)
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define ff first
#define ss second

const double EPS = (1e-7);


int main() {
    fast_io;

    int t = 1;

    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
