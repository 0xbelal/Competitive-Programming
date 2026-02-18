// belal_cp_temp
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <climits>
#include <deque>
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

const int MAXN = 200000;

void solve() {


    /*
    All elements in the subarray must be unique.
    The subarray must have the maximum possible MEX.
    If multiple subarrays have the same maximum MEX, choose the longest subarray. subarray.
    */


    int n; cin>>n;
    vector<int> nums(n); cin>>nums;  
    vector<int> freq(MAXN+1,0);

      int current_mex = 0;
    int best_mex = -1;
    int best_len = 0;

    int l=0;

    for (int r = 0; r < n; r++) {
    
        freq[nums[r]]++;


        while (freq[nums[r]] > 1) {

            if(nums[l] < current_mex && freq[nums[l]] == 1){
                current_mex = nums[l];
            }
            freq[nums[l]]--;
            l++;
        }

        while (freq[current_mex] > 0) current_mex++;
        
        int len = r-l+1;
         if (current_mex > best_mex) {
            best_mex = current_mex;
            best_len = len;
        } else if (current_mex == best_mex) {
            best_len = max(best_len, len);
        }

        
    }



    cout<<best_len<<"\n";
       
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
