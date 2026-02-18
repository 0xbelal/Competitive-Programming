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

const double EPS = (1e-7);

vector<bool> isprime;
vector<ll> primes;
void sieve(ll n)
{
	isprime.resize(n + 1, true);
	isprime[0] = isprime[1] = false;
	for (ll i = 2; i <= n; i++)
	{
		if (isprime[i])
		{
			primes.push_back(i);
			for (ll j = i * i; j <= n; j += i)
				isprime[j] = false;
		}
	}
}
ll primefactorization(ll n)
{
	ll ans = 1;
	for (ll i = 0; i < primes.size() && primes[i]*primes[i] <= n; i++)
	{
		ll counter = 0;
		while (n % primes[i] == 0)
		{
			n /= primes[i];
			counter++;
		}
		ans *= (counter + 1);
	}
	if (n > 1)
		ans *= 2;
	return ans;
}
int main()
{
	fast_io;

	ll a, b, c;
	cin >> a >> b >> c;
	sieve(a * b * c);
	vector<ll> v(1e6+1);
	v[0] = 0;
	v[1] = 1;
	for (ll i = 2; i <= a*b*c; i++)
	{
		v[i] = primefactorization(i);
	}
	ll  ans = 0;
	for (ll i = 1; i <= a; i++)
	{
		for (ll j = 1; j <= b; j++)
		{
			for (ll k = 1; k <= c; k++)
			{
				ans += v[i * j * k];
			}
		}
	}
	cout << ans % 1073741824 << endl;
}