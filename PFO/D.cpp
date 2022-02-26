#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

#define speedio ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
#define forn(i, s, n) for (int i = (s); i < int(n); ++i)
#define pb push_back
#define eb emplace_back
#define graph(n, g) for (int i = 0; i < (n); ++i) {int u, v; cin >> u >> v; --u; --v; (g)[u].pb(v); (g)[v].pb(u);}
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define vc vector
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int, int>
#define pl pair<ll, ll>


constexpr auto nl = '\n';
const ld PI = acos(-1.0);
const int INF = int(2e9);
const ll ll_INF = ll(2e18);
const int MOD = int(1e9) + 7;

mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());

template<typename A, typename B> ostream& operator<<(ostream& os, const pair<A, B>& p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream& os, const T_container& v) { os << '{'; string sep; for (const T& x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef ONPC
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

template<class T>
void cout_vc(vc<T> a, char sep = ' ') {
    for (auto x : a) cout << x << sep;
    cout << nl;
}

template<class T>
T bin_pow(T a, T b) {
    if (b == 0) return 1;
    if (b % 2 == 1) return bin_pow(a, b - 1) * a;
    else {
        T t = bin_pow(a, b / 2);
        return t * t;
    }
}

ll dist(pair<ll, ll> a, pair<ll, ll> b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

void solve() {
    ll x, y;
    cin >> x >> y;
    int n; cin >> n;
    vector<ll> dists(n);
    vc<pair<ll, pi>> d;
    for (int i = 0; i < n; ++i) {
        ll x1, y1;
        cin >> x1 >> y1;
        dists[i] = dist({ x, y }, { x1, y1 });
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            d.push_back({ dists[i] * dists[j], {i + 1, j + 1} });
        }
    }
    sort(all(d));
    int t = 0;
    while (t < d.size() - 1) {
        ll di = d[t].first;
        auto [i, j] = d[t].second;
        int g = 1;
        while (t + g < d.size() && di == d[t + g].first) {
            auto [i2, j2] = d[t + g].second;
            if (i != i2 && i != j2 && j != i2 && j != j2) {
                cout << "YES\n";
                cout << i << ' ' << j << ' ' << i2 << ' ' << j2;
                return;
            }
            g++;
        }
        t++;
    }
    cout << "NO";
}

int main() {
    speedio;
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

//vc<string> a = {"a"};
//int i = 1;
//vc<char> b;
//forn(i, 0, 26) {
//    b.push_back('a' + i);
//}
//while (a.back().size() < 5000) {
//    a.push_back(a.back() + b[i] + a.back());
//    i++;
//}
//ll ans = 0;
//int mod = 998244353;