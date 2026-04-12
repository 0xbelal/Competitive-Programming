/* Deliberate practice > blind repetition */
// Author: Belal
// URL: https://codeforces.com/problemset/problem/1406/C


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
const int N = 1e5+5;
vector<int> adj[N];
int sz[N], parent[N];
int n, min_max_subtree, cent1, cent2;

// العثور على مراكز الشجرة (Centroids)
void find_centroids(int u, int p) {
    sz[u] = 1;
    parent[u] = p;
    int max_subtree = 0;

    for (int v : adj[u]) {
        if (v == p) continue;
        find_centroids(v, u);
        sz[u] += sz[v];
        max_subtree = max(max_subtree, sz[v]);
    }

    max_subtree = max(max_subtree, n - sz[u]);

    if (max_subtree < min_max_subtree) {
        min_max_subtree = max_subtree;
        cent1 = u;
        cent2 = 0;
    } else if (max_subtree == min_max_subtree) {
        cent2 = u;
    }
}

// العثور على أي ورقة (Leaf) في الشجرة الفرعية
int get_leaf(int u, int p) {
    if (adj[u].size() == 1) return u;
    for (int v : adj[u]) {
        if (v != p) return get_leaf(v, u);
    }
    return u;
}

void solve() {
    cin >> n;
    
    // Reset Data
    for (int i = 1; i <= n; i++) adj[i].clear();
    min_max_subtree = 1e9;
    cent1 = cent2 = 0;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    find_centroids(1, 0);

    // الحالة الأولى: مركز واحد فقط، نحذف ضلع ونعيده كما هو
    if (cent2 == 0) {
        cout << 1 << " " << adj[1][0] << "\n";
        cout << 1 << " " << adj[1][0] << "\n";
    } 
    // الحالة الثانية: مركزان، ننقل ورقة من شجرة المركز الأول لتتصل بالمركز الثاني
    else {
        if (parent[cent1] != cent2) swap(cent1, cent2);
        
        // نبحث عن ورقة في جهة cent1 بعيداً عن cent2
        int leaf = get_leaf(cent1, cent2);
        int leaf_parent = adj[leaf][0]; // الورقة دائماً لها جار واحد

        // 1. قطع الضلع بين الورقة وأبيها
        cout << leaf << " " << leaf_parent << "\n";
        // 2. ربط الورقة بالمركز الثاني مباشرة
        cout << leaf << " " << cent2 << "\n";
    }
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
