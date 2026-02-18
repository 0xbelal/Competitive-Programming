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

    // 1 1 2 3 
    // two pointer (variable)
    /*
        - sort all books 
        - define l=0 , loop r from 0 to n 
            - check if the sum of books that he read < t
            - l++ , decrease the sum 
    */


    int n,t; cin>>n>>t;
    vector<ll> books_time(n); cin>>books_time;


    ll sum_books =0;
    int l=0,r;
    int counter=0,ans=0;

    for (r = 0; r < n; r++){

        sum_books += books_time[r];
        counter++;

        while (l<n && (sum_books > t) )
        {
            sum_books -= books_time[l];
            l++;
            counter--;
        }


        if(sum_books <= t){
            ans = max(ans,counter);
        }

        // 6  8  14  9  4  11  10  2  6  5 10
        //                               ^    ^
        // sum 10
        // cntr 1
        // ans  3

        

    }

    
    
    cout<<ans;
    
    
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
