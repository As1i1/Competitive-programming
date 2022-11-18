#include <bits/stdc++.h>

#include <random>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned uint;
typedef unsigned long long ull;
#define speedio ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
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
const int INF = int(2e9);
const ll ll_INF = ll(2e18);
const int MOD = int(1e9) + 7;

mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());

//template<typename A, typename B> ostream& operator<<(ostream& os, const pair<A, B>& p) { return os << '(' << p.first << ", " << p.second << ')'; }
//template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream& os, const T_container& v) { os << '{'; string sep; for (const T& x : v) os << sep << x, sep = ", "; return os << '}'; }

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
    for (auto &i: v) --i;
    return v;
}

template<typename T>
vector<T> &operator++(vector<T> &v) {
    for (auto &i: v) ++i;
    return v;
}

template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for (auto &i: v) is >> i;
    return is;
}

template<typename T>
ostream &operator<<(ostream &os, vector<T> v) {
    for (auto &i: v) os << i << ' ';
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
T max(pair<T, T> x) {
    return max(x.first, x.second);
}

template<class T>
T min(pair<T, T> x) {
    return min(x.first, x.second);
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

ll n, s;
vll a;
unordered_map<ll, tuple<ll, ll, ll>> paths;

string recover(ll x) {
    if (get<0>(paths[x]) == 0) {
        return to_string(get<1>(paths[x]));
    }
    if (get<0>(paths[x]) == -1) {
        return "~" + to_string(get<1>(paths[x]));
    }
    if (get<0>(paths[x]) == 1) {
        return "(" + recover(get<1>(paths[x])) + "|"+ recover(get<2>(paths[x])) + ")";
    }
    if (get<0>(paths[x]) == 2) {
        return "(" + recover(get<1>(paths[x])) + "&"+ recover(get<2>(paths[x])) + ")";
    }
    return "";
}

string solve2(vector<ll> f) {
    a.resize(n);
    copy(f.begin(), f.end(), a.begin());
    const int K = 9;
    vc<unordered_set<ll>> dp(K);
    forn(i, 0, n) {
        dp[0].insert(a[i]);
        dp[0].insert(~a[i]);
        paths[a[i]] = make_tuple(0, i + 1, 0);
        paths[~a[i]] = make_tuple(-1, i + 1, 0);
    }
    forn(i, 0, K) {
        forn(j, 0, K) {
            if (i + j + 1 < K)
                for (ll x1: dp[i])
                    for (ll x2: dp[j]) {
                        if (paths.find(x1 | x2) == paths.end()) {
                            dp[i + j + 1].insert(x1 | x2);
                            paths[x1 | x2] = make_tuple(1, x1, x2);
                        }
                        if (paths.find(x1 & x2) == paths.end()) {
                            dp[i + j + 1].insert(x1 & x2);
                            paths[x1 & x2] = make_tuple(2, x1, x2);
                        }
                    }

        }
    }
    if (paths.find(s) == paths.end()) {
        return "Impossible";
    } else {
        return recover(s);
    }
}


string printC(vector<int> c, int n){
    string ans = "";
    for (int i = 0; i < c.size(); i++){
        if (i != 0){
            ans += "&";
        }
        if (c[i] >= n) {
            ans +=  "~";
            ans += to_string(c[i] - n + 1);
        } else {
            ans += to_string(c[i] + 1);
        }
    }
    return ans;
}


string solve1(vector<ll> f){
    vector<bitset<33>> numbers(2 * n);
    for (int i = 0; i < n; ++i) {
        ll tmp = f[i];
        numbers[i] = bitset<33>(tmp);
        numbers[i + n] = numbers[i];
        numbers[i + n].flip();
    }
    n *= 2;
    vector<bitset<33>> allC;
    vector<vector<int>> index;
    for (int i = 1; i < (1 << n); i++) {
        bitset<33> tmp;
        tmp.reset();
        tmp.flip();
        vector<int> tmp2;
        for (int j = 0; j < n; ++j){
            if (i & (1 << j)) {
                tmp &= numbers[j];
                tmp2.push_back(j);
            }
        }
        allC.push_back(tmp);
        index.push_back(tmp2);
    }
    for (int i = 0; i < 1000; i++) {
        vector<int> r(allC.size());
        for (int j = 0; j < allC.size(); j++) {
            r[j] = j;
        }
        shuffle(r.begin(), r.end(), std::mt19937(std::random_device()()));
        bitset<33> ans = 0;
        int count = gen() % (allC.size() - 1) + 1;
        for (int j = 0; j < count; j++) {
            ans |= allC[r[j]];
        }
        if (ans == s) {
            string sans = "";
            for (int j = 0; j < count; ++j) {
                if (j != 0) {
                    sans += "|";
                }
                sans += printC(index[r[j]], n / 2);
            }
            n /= 2;
            return sans;
        }
    }
    n /= 2;
    return "Impossible";
}



ll make_s(vector<ll> f) {
    vector<ll> a (2 * n);
    for (int i = 0; i < n; i++){
        a[i] = f[i];
        a[i + n] = ~f[i];
    }
    for (int i = 0; i < f.size(); i++) {
        a.push_back(~f[i]);
    }
    while (true) {
        int m = gen() % a.size() + 1;
        shuffle(a.begin(), a.end(), std::mt19937(std::random_device()()));
        ll ans = a[0];
        for (int i = 1; i < m; i++) {
            if (gen() % 2 == 0) {
                ans |= a[i];
            } else {
                ans &= a[i];
            }
        }
        if (ans >= 0) {
            return ans;
        }
    }
}



int main() {
    //freopen("next.in", "r", stdin);
    //freopen("next.out", "w", stdout);
    //cout.precision(9);
    speedio;
    int t = 1;
    cin >> t;
    while (t--) {
        n = gen() % 2 + 3;
        vector<ll> v(n);
        for (int i = 0; i < n; ++i){
            v[i] = gen() % (1ll << 32);
        }
        s = make_s(v);
        string ans1 = solve1(v);
        string ans2 = solve2(v);
        if (ans1 == "Impossible" && ans2 != "Impossible" || ans1 != "Impossible" && ans2 == "Impossible") {
            cout << ans1 << "\n" << ans2 << "\n";
            cout << n << "\n";
            cout << v << "\n";
            cout << s << endl;
            return 0;
        }
    }
    return 0;
}
