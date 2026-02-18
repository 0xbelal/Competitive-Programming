
#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 10 , Mod = 1e9+7;


vector<int> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    vector<int> primes;
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
        for (int p : primes) {
            if (i * p > n) {
                break;
            }
            is_prime[i * p] = false;
            if (i % p == 0) {
                break;
            }
        }
    }
    return primes;
}

void pre_fact(int n, vector<int>& primes, map<int,int> &freq){
    long long ans=1;

    for (int i = 0; i < (int)primes.size(); ++i) {
        if (primes[i] * primes[i] > n) {
            break;
        }
        while (n % primes[i] == 0) {
            n /= primes[i];
            freq[primes[i]] += 1;
        }
    }
    if (n != 1) {
        primes[n]+=1;
    }

}

void solve()
{

    vector <int> primes = sieve(N);
    map<int,int> freq;
   long long ans=1;

       int n; cin >> n;
         vector<int> nums(n);
         for(int &x:nums){
            cin>>x;
            pre_fact(x,primes,freq);
         }
         for(auto &x:freq){
             ans *= (x.second+1);
             ans%=Mod;
         }
    cout<<ans;

}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);


    int testCases = 1;
    //  cin >> testCases;
    for (int testCase = 1 ; testCase <= testCases ; ++testCase){
        solve();
    }
}