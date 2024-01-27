//
// Created by Dubinin Dmitrii on 12/19/23.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

struct state {
    state() {}

    state(const state& s) {
        len = s.len;
        link = s.link;
        next = s.next;
    }

    int len, link;
    map<char, int> next;
};
vector<state> avt;
int last;

void sa_init() {
    avt.clear();
    avt.push_back({});
    avt[0].len = 0;
    avt[0].link = -1;
    last = 0;
}

void sa_extend(char c) {
    avt.push_back({});
    int cur = avt.size() - 1;
    avt[cur].len = avt[last].len + 1;
    int p = last;
    while (p >= 0 && avt[p].next.find(c) == avt[p].next.end()) {
        avt[p].next[c] = cur;
        p = avt[p].link;
    }

    if (p != -1) {
        int q = avt[p].next[c];
        if (avt[p].len + 1 == avt[q].len) {
            avt[cur].link = q;
        } else {
            avt.push_back(avt[q]);
            avt.back().len = avt[p].len + 1;
            avt[q].link = avt[cur].link = avt.size() - 1;
            while (p >= 0 && avt[p].next[c] == q) {
                avt[p].next[c] = avt.size() - 1;
                p = avt[p].link;
            }
        }
    }
    last = cur;
}


string suf_mas_impl(string s, vector<int> pos, int k) {
    s += '#';
    int n = s.size();
    vector<int> suf_mas(n);
    vector<int> cnt(27, 0);
    for (int i = 0; i < n; i++) {
        cnt[s[i] == '#' ? 0 : s[i] - 'a' + 1]++;
    }
    for (int i = 1; i < 27; ++i) cnt[i] += cnt[i - 1];
    for (int i = n - 1; i >= 0; --i) {
        suf_mas[--cnt[s[i] == '#' ? 0 : s[i] - 'a' + 1]] = i;
    }
    vector<int> cl(n);
    cl[suf_mas[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; ++i) {
        if (s[suf_mas[i]] != s[suf_mas[i - 1]]) ++classes;
        cl[suf_mas[i]] = classes - 1;
    }
    vector<int> suf_mas2(2 * n), cl2(2 * n);
    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; ++i) {
            suf_mas2[i] = suf_mas[i] - (1 << h);
            if (suf_mas2[i] < 0) suf_mas2[i] += n;
        }
        cnt = vector<int>(classes, 0);
        for (int i = 0; i < n; ++i)
            ++cnt[cl[suf_mas2[i]]];
        for (int i = 1; i < classes; ++i)
            cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; --i)
            suf_mas[--cnt[cl[suf_mas2[i]]]] = suf_mas2[i];
        cl2[suf_mas[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; ++i) {
            int mid1 = (suf_mas[i] + (1 << h)) % n, mid2 = (suf_mas[i - 1] + (1 << h)) % n;
            if (cl[suf_mas[i]] != cl[suf_mas[i - 1]] || cl[mid1] != cl[mid2])
                ++classes;
            cl2[suf_mas[i]] = classes - 1;
        }
        cl = cl2;
    }
    vector<int> rev_suf_mas(n);
    for (int i = 0; i < n; ++i) {
        rev_suf_mas[suf_mas[i]] = i;
    }
    int ans = pos[0];
    for (int p: pos) {
        if (rev_suf_mas[p] < rev_suf_mas[ans]) {
            ans = p;
        }
    }
    return s.substr(ans, k);
}

#define forn(i, s, n) for (int i = (s); i < int(n); ++i)
#define vc vector
#define vi vector<int>
#define vll vector<ll>

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

string solve_d(string s, string t) {
    k = 2;
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
        return "";
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

string solve(string s, string t) {
    sa_init();
    for (char c: s) {
        sa_extend(c);
    }
    int v = 0, l = 0, best = 0;
    vector<int> bestpos;
    for (int i = 0; i < (int) t.length(); ++i) {
        while (v && !avt[v].next.count(t[i])) {
            v = avt[v].link;
            l = avt[v].len;
        }
        if (avt[v].next.count(t[i])) {
            v = avt[v].next[t[i]];
            ++l;
        }
        if (l > best) {
            best = l;
            bestpos = {i - best + 1};
        } else if (l == best) {
            bestpos.push_back(i - best + 1);
        }
    }
    return suf_mas_impl(t, bestpos, best);
}

mt19937 gen;

signed main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int t = 10;
    int n = 20;
	gen.seed(time(0));
//	cout << fixed;
//	cout.precision(15);
//    cin >> t;
    while (t--) {
        string s1;
        string s2;
        for (int i = 0; i < n; ++i) {
//            char c = ;
            s1 += 'a' + gen() % 26;
            s2 += 'a' + gen() % 26;
        }
        if (solve(s1, s2) != solve_d(s1, s2)) {
            cout << solve(s1, s2) << " " << solve_d(s1, s2) << "\n" << s1 << " " << s2 << "\n\n";
        }
    }
    return 0;
}
