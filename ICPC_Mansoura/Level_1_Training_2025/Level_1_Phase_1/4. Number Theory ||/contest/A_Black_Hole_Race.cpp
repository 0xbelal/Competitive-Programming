#include <iostream>
#include <algorithm>
#include <numeric>

// نستخدم 'long long' لأن t, a, h تصل إلى 5 * 10^18
typedef long long ll;

// 1. دالة لحساب القاسم المشترك الأكبر (GCD) باستخدام خوارزمية إقليدس
ll gcd(ll x, ll y) {
    while (y) {
        x %= y;
        std::swap(x, y);
    }
    return x;
}

// 2. دالة لحساب المضاعف المشترك الأصغر (LCM)
// يجب الحذر من overflow، لذا نقسم أولاً ثم نضرب
ll lcm(ll x, ll y) {
    if (x == 0 || y == 0) return 0;
    return (x / gcd(x, y)) * y;
}

void solve() {
    ll t, a, h;
    if (!(std::cin >> t >> a >> h)) return;

    if (a == h) {
        std::cout << "1/1\n";
        return;
    }

    ll L_cm = lcm(a, h);
        ll min_ah = std::min(a, h);


    ll N_full = t / L_cm;
    ll total_ties = N_full * min_ah;
    ll K_last = N_full * L_cm; 
        ll steps_remaining = t - K_last;

   
    ll ties_rem;
    if (K_last < t) {
         ties_rem = std::min(steps_remaining, min_ah - 1) + 1;
    } else {
        ties_rem = 0;
    }
    
    ll t_rem = t % L_cm;

    
    ll total_ties_m0 = std::min(t, min_ah - 1); 
    ll M = t / L_cm;

    ll total_ties_final = 0;

    for (ll m = 0; m <= M; ++m) {
        ll K_m = m * L_cm;
        
  
        ll range_end = K_m + min_ah - 1; 

        ll start = std::max(1LL, K_m);
        ll end = std::min(t, range_end);

        if (end >= start) {
            total_ties_final += (end - start + 1);
        }
    }
    
    ll g = gcd(total_ties_final, t);
    ll p = total_ties_final / g;
    ll q = t / g;

    std::cout << p << "/" << q << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll T;
    if (!(std::cin >> T)) return 0;

    while (T--) {
        solve();
    }

    return 0;
}