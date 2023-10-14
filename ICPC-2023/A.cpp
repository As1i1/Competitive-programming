#include <bits/stdc++.h>

// #pragma GCC optimize("Ofast,unroll-loops")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned uint;
typedef unsigned long long ull;

#define speedio                                                                \
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define forn(i, s, n) for (int i = (s); i < int(n); ++i)
#define nfor(i, s, n) for (int i = (s); i > int(n); --i)
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define vc vector
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define mp make_pair

constexpr auto nl = '\n';
const ld PI = acos(-1.0);
constexpr int INF = int(2e9);
constexpr ll ll_INF = ll(2e18);
constexpr int MOD = int(1e9) + 7;

mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());

// template<typename A, typename B> ostream& operator<<(ostream& os, const
// pair<A, B>& p) { return os << '(' << p.first << ", " << p.second << ')'; }
// template<typename T_container, typename T = typename
// enable_if<!is_same<T_container, string>::value, typename
// T_container::value_type>::type> ostream& operator<<(ostream& os, const
// T_container& v) { os << '{'; string sep; for (const T& x : v) os << sep << x,
// sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }

template<typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
    cerr << ' ' << H;
    dbg_out(T...);
}

#ifdef ONPC
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

template<typename T>
vector<T> &operator--(vector<T> &v) {
    for (auto &i: v)
        --i;
    return v;
}

template<typename T>
vector<T> &operator++(vector<T> &v) {
    for (auto &i: v)
        ++i;
    return v;
}

template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for (auto &i: v)
        is >> i;
    return is;
}

template<typename T>
ostream &operator<<(ostream &os, vector<T> v) {
    for (auto &i: v)
        os << i << ' ';
    return os;
}

template<typename T, typename U>
pair<T, U> &operator--(pair<T, U> &p) {
    --p.first;
    --p.second;
    return p;
}

template<typename T, typename U>
pair<T, U> &operator++(pair<T, U> &p) {
    ++p.first;
    ++p.second;
    return p;
}

template<typename T, typename U>
istream &operator>>(istream &is, pair<T, U> &p) {
    is >> p.first >> p.second;
    return is;
}

template<typename T, typename U>
ostream &operator<<(ostream &os, pair<T, U> p) {
    os << p.first << ' ' << p.second;
    return os;
}

template<class T>
T max(pair<T, T> x) { return max(x.first, x.second); }

template<class T>
T min(pair<T, T> x) { return min(x.first, x.second); }

template<class T>
T bin_pow(T a, T b) {
    if (b == 0)
        return 1;
    if (b % 2 == 1)
        return bin_pow(a, b - 1) * a;
    else {
        T t = bin_pow(a, b / 2);
        return t * t;
    }
}

void solve() {
    int A, B;
    cin >> A >> B;
    if (A % 2 != B % 2) {
        cout << "Error\n";
    } else {
        if (B == 0) {
            cout << A / 2 << "\n0\n0";
        } else if (A == 0) {
            cout << "0\n" << B / 2 << "\n0";
        } else if (B == 1) {
            cout << A / 2 << "\n0\n1";
        } else if (A == 1) {
            cout << "0\n" << B / 2 << "\n1";
        } else {
            cout << "Undefined\n";
        }
    }
}

int main() {
    //        freopen("fastminimization.in", "r", stdin);
    //        freopen("fastminimization.out", "w", stdout);
    cout.precision(9);
    speedio;
    int t = 1;
    //    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}