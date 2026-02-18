// belal_cp_temp
/*                                         ......  
                                      ..:::^^^^^. 
                                   .::^^^^^^:^^:. 
                                .:^^~~~^^~~~^:^:  
                             .:^~~^^::.:^~~~^~^   
                      .....:^^^^::.     :^~^^:    
                   ::^^^^^~~^^^::.      ^~~^:     
                .:^^:^^^^~^^^^~^^:^.   ^~^^:      
              .:^^^^^^^^~^~~^~~^^^^^:.^~^^.       
             .^^:::^^^^~!!~~~~~~^^:^^^~^:.        
            .^^:^^^^^^~!!^^~~~^^^^^:^^:.          
            :^^^~^^^~~~!^^^~^^^^^^^^^:            
            :^^~^^~~~^~~~~~~~^^^^^^^^:            
           :^~~^^^^~~~~^^^~~~~^^^^:^:.            
         .^~~::^~~~~~^^^^^~~^^^^^^^:.             
        :^~~..^^^^^^^^^^^^^^^^:^:::.              
      .^^~~.  .^^^^:^^^^^^^^^^:::.                
     :^^~^.     .:::::^^^^^^::..                  
    :^^~~:      ..^^^:....:.                      
   :^^~~^^:..:^^~~^^..                            
  .^^^~~~~^^~^~~^:.                               
  :^^^^^^^~~^::.                                  
  :^^^^^^:...                                     
  .:.....                                         
*/
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
#define rep(i, v)		for(int i=0;i<sz(v);++i)
#define lp(i, n)		for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)	for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)	for(int i=(j);i>=(int)(n);--i)
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define ff first
#define ss second

const double EPS = (1e-6);
int n;
double target;
vector<double> a;

bool equal_double(double x, double y) {
    return fabs(x - y) <= EPS;
}

bool can_make_target(vector<double> nums) {
    if (nums.size() == 1)
        return equal_double(nums[0], target);

    // جرّب كل زوج ممكن ندمجه بعملية واحدة
    for (int i = 0; i < (int)nums.size(); ++i) {
        for (int j = 0; j < (int)nums.size(); ++j) {
            if (i == j) continue;
            vector<double> next;
            // انسخ العناصر غير i و j
            for (int k = 0; k < (int)nums.size(); ++k)
                if (k != i && k != j) next.push_back(nums[k]);

            // جرّب 4 عمليات
            vector<double> results;
            results.push_back(nums[i] + nums[j]);
            results.push_back(nums[i] - nums[j]);
            results.push_back(nums[i] * nums[j]);
            if (fabs(nums[j]) > EPS) results.push_back(nums[i] / nums[j]);

            for (double res : results) {
                next.push_back(res);
                if (can_make_target(next)) return true;
                next.pop_back();
            }
        }
    }
    return false;
}

void solve() {
    double m;
    cin >> n >> m;
    target = m;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    sort(a.begin(), a.end());
    bool ok = false;
    do {
        if (can_make_target(a)) {
            ok = true;
            break;
        }
    } while (next_permutation(a.begin(), a.end()));

    cout << (ok ? "YES" : "NO") << "\n";
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
