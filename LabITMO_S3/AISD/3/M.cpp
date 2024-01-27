//
// Created by Dubinin Dmitrii on 12/18/23.
//

#include <bits/stdc++.h>

using namespace std;

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
    avt[cur].link = -1;
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

void solve() {
    string s, t;
    cin >> s >> t;
    sa_init();
    for (char c: s) {
        sa_extend(c);
    }
    int v = 0, l = 0, best = 0;
    vector<int> bestpos;
    for (int i = 0; i < (int) t.length(); ++i) {
        while (v != 0 && avt[v].next.find(t[i]) == avt[v].next.end()) {
            v = avt[v].link;
            l = avt[v].len;
        }
        if (avt[v].next.find(t[i]) != avt[v].next.end()) {
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
    cout << suf_mas_impl(t, bestpos, best);
}


signed main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
//    freopen("1", "r", stdin);
//    freopen("2", "w", stdout);
    int t = 1;
//	cout << fixed;
//	cout.precision(15);
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
