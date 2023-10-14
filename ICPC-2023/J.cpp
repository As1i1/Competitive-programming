#include <bits/stdc++.h>
#include <cassert>

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define IOS ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pb push_back
#define vc vector
#define vi vector<int>
#define vll vector<long long>
#define forn(i, s, n) for(int i = (s); i < (n); ++i)
#define fornr(i, s, n) for(int i = (s); i >= (n); --i)
#define fi first
#define se second
using namespace std;

template<typename T>
basic_ostream<char> &operator<<(basic_ostream<char> &out, vc<T> &a) {
    forn(i, 0, a.size()) {
        out << a[i] << ' ';
    }
    return out;
}

template<typename T>
basic_istream<char> &operator>>(basic_istream<char> &in, vc<T> &a) {
    forn(i, 0, a.size()) {
        in >> a[i];
    }
    return in;
}

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;
typedef pair<ld, ld> pld;
typedef vector<vector<int>> matrix;

const int MAXN = 1e6;
const int INF = 2e9;
const ll INFL = 1e16;
const int MOD = 1e9 + 7;
const int P = 17;
const ld PI = acosl(-1.0);

#ifndef NDEBUG
#define MYASSERT(msg, expr) if (!(expr)) {cerr << (msg); while(1) {cout<<1;}}
#else
#define MYASSERT(expr)
#endif

vi l;
int n;

//int dfs(int v) {
//    if (v + 6 >= n - 1) return 1;
//    if (l[v + 6] > l[v]) return dfs(l[v + 6]);
//    int ans = INF;
//    forn(i, 1, 6) {
//        if (l[v + i] > l[v]) {
//            ans = min(ans, dfs(l[v + i]));
//        }
//    }
//    return 1 + ans;
//}

int main() {
    cin >> n;
    vi a(n, 0);
    l.assign(n, INF);
    forn(i, 1, n - 1)cin >> a[i];
    l[0] = 0;
    forn(i, 1, n) {
        l[i] = (a[i] == 0 ? i : l[i - a[i]]);
    }
    vi dp(n, INF);
    dp[0] = 1;
    forn(i, 0, n) {
        int v = l[i];
        dp[l[min(n - 1, v + 6)]] = min(dp[l[min(n - 1, v + 6)]], dp[v]);
        forn(j, 0, 6) {
            dp[l[min(n - 1, v + j)]] = min(dp[l[min(n - 1, v + j)]], dp[v] + 1);
        }
    }
    cout << (dp[n - 1] == INF ? -1 : dp[n - 1]);
}