// #pragma GCC optimize("Ofast,unroll-loops")

#define speedio ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
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
constexpr int INF = static_cast<int>(2e9);
constexpr ll ll_INF = static_cast<ll>(2e18);
constexpr int MOD = static_cast<int>(1e9) + 7;


template <class T>
T bin_pow(T a, T b, int md) {
    if (b == 0) {
        return 1;
    }
    if (b % 2 == 1) {
        return bin_pow(a, b - 1, md) * a % md;
    } else {
        T t = bin_pow(a, b / 2, md);
        return t * t % md;
    }
}

int ord(char s) {
    return (s == '#' ? 0 : s - 'a' + 1);
}

constexpr ll MULT = 31;
constexpr ll MULT2 = 41;
constexpr ll MOD2 = int(1e9) + 9;
vll powers;
vll powersrev;
vll powers2;
vll powers2rev;
vc<vll> hashes;
vc<vll> hashes2;
vc<string> strs;
int k;

ll reverse(ll x, ll md) {
    return bin_pow<ll>(x, md - 2, md);
}

void check(int len, set<pair<ll, ll>>& buf) {
    buf.clear();
    set<pair<ll, ll>> iter;
    for (int i = 0; i + len <= strs[0].size(); ++i) {
        ll hh = (hashes[0][i + len] - hashes[0][i] + MOD) % MOD;      // * powers[i]
        ll hh2 = (hashes2[0][i + len] - hashes2[0][i] + MOD2) % MOD2; // * powers[i]
        iter.emplace(hh * powersrev[i] % MOD, hh2 * powers2rev[i] % MOD2);
    }
    for (int i = 0; i + len <= strs[1].size(); ++i) {
        ll hh = (hashes[1][i + len] - hashes[1][i] + MOD) % MOD;      // * powers[i]
        ll hh2 = (hashes2[1][i + len] - hashes2[1][i] + MOD2) % MOD2; // * powers[i]
        pair<ll, ll> r = {hh * powersrev[i] % MOD, hh2 * powers2rev[i] % MOD2};
        if (iter.contains(r)) {
            buf.insert(std::move(r));
        }
    }
}

void solve_d() {
    k = 2;
    string s, t;
    cin >> s >> t;
    strs = {s, t};

    int n = s.size();
    s += '#';
    n++;
    vi suf_mas(n);
    vi cnt(n + 27, 0);
    for (auto x : s) {
        cnt[ord(x)]++;
    }
    forn(i, 1, 27) {
        cnt[i] += cnt[i - 1];
    }
    for (int i = n - 1; i > -1; --i) {
        suf_mas[--cnt[ord(s[i])]] = i;
    }
    cnt.clear();
    cnt.push_back(0);
    vi equiv(n);
    forn(i, 1, n) {
        equiv[suf_mas[i]] = equiv[suf_mas[i - 1]];
        if (s[suf_mas[i - 1]] != s[suf_mas[i]]) {
            equiv[suf_mas[i]]++, cnt.push_back(i);
        };
    }

    int k1 = 1;

    while (k1 < n) {
        vi newsf = suf_mas;

        forn(i, 0, n) {
            newsf[cnt[equiv[(suf_mas[i] - k1 + n) % n]]++] = (suf_mas[i] - k1 + n) % n;
        }
        suf_mas = newsf;

        vi newequiv(n);
        cnt.clear();
        cnt.push_back(0);
        forn(i, 1, n) {
            newequiv[suf_mas[i]] = newequiv[suf_mas[i - 1]];
            if (equiv[suf_mas[i - 1]] != equiv[suf_mas[i]] or
                equiv[(suf_mas[i] + k1 + n) % n] != equiv[(suf_mas[i - 1] + k1 + n) % n]) {
                newequiv[suf_mas[i]]++;
                cnt.push_back(i);
            }
        }
        equiv = newequiv;

        k1 *= 2;
    }

    vi anti_mas(n);
    forn(i, 0, n) {
        anti_mas[suf_mas[i]] = i;
    }

    ranges::sort(strs, [](string a, string b) { return a.size() < b.size(); });

    powers.assign(strs.back().size(), 1);
    powers2.assign(strs.back().size(), 1);
    powers2rev.assign(strs.back().size(), 1);
    powersrev.assign(strs.back().size(), 1);
    hashes.assign(k, vll(strs.back().size() + 1, 0));
    hashes2.assign(k, vll(strs.back().size() + 1, 0));

    forn(i, 1, strs.back().size()) {
        powers[i] = (powers[i - 1] * MULT) % MOD;
        powersrev[i] = reverse(powers[i], MOD);
        powers2[i] = (powers2[i - 1] * MULT2) % MOD2;
        powers2rev[i] = reverse(powers2[i], MOD2);
    }

    forn(j, 0, k) {
        forn(i, 0, strs[j].size()) {
            hashes[j][i + 1] = (hashes[j][i] + (strs[j][i]) * powers[i]) % MOD;
            hashes2[j][i + 1] = (hashes2[j][i] + (strs[j][i]) * powers2[i]) % MOD2;
        }
    }

    int l = 0, r = strs[0].size() + 1;
    set<pair<ll, ll>> ind_;
    set<pair<ll, ll>> ind;
    while (r - l > 1) {
        int m = (r + l) / 2;
        check(m, ind_);
        if (!ind_.empty()) {
            l = m;
            swap(ind, ind_);
        } else {
            r = m;
        }
    }

    if (ind.empty()) {
        return;
    }

    int ans = INF;
    int ans_pos = INF;
    for (auto [x, y] : ind) {
        for (int i = 0; i + l <= strs[0].size(); ++i) {
            ll hh = (hashes[0][i + l] - hashes[0][i] + MOD) % MOD;      // * powers[i]
            ll hh2 = (hashes2[0][i + l] - hashes2[0][i] + MOD2) % MOD2; // * powers[i]
            if (hh * powersrev[i] % MOD == x && hh2 * powers2rev[i] % MOD2 == y) {
                if (anti_mas[i] < ans_pos) {
                    ans_pos = anti_mas[i];
                    ans = i;
                }
            }
        }
    }

    return strs[0].substr(ans, l);
}