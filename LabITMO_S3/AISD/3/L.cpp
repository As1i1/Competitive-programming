//
// Created by AMD on 28.12.2021.  332018GTKED
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <random>
#include <ctime>
#include <unordered_map>

using namespace std;
typedef long long ll;
typedef long double ld;


const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> suf_mas(n);
    vector<int> cnt(200, 0);
    for (int i = 0; i < n; i++) {
        cnt[s[i] - 32]++;
    }
    for (int i = 1; i < 200; ++i) cnt[i] += cnt[i - 1];
    for (int i = n - 1; i >= 0; --i) {
        suf_mas[--cnt[s[i] - 32]] = i;
    }
    vector<int> cl(n);
    cl[suf_mas[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; ++i) {
        if (s[suf_mas[i]] != s[suf_mas[i - 1]]) ++classes;
        cl[suf_mas[i]] = classes - 1;
    }
    vector<int> suf_mas2(n), cl2(n);
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
    vector<int> lcp(n, 0), rev_suf_mas(n);
    for (int i = 0; i < n; ++i) {
        rev_suf_mas[suf_mas[i]] = i;
    }
    int lcp_now = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (rev_suf_mas[i] == n - 1) {
            lcp_now = 0;
            continue;
        }
        while (s[lcp_now + i] == s[suf_mas[rev_suf_mas[i] + 1] + lcp_now]) {
            lcp_now++;
        }
        lcp[rev_suf_mas[i]] = lcp_now;
        lcp_now = max(0, lcp_now - 1);
    }
    int q;
    cin >> q;
    for (int i = 0; i < n; ++i) {
        if (cl[i] == q - 1) {
            cout << s.substr(i, s.size() - i) << s.substr(0, i);
            return;
        }
    }
    cout << "IMPOSSIBLE";
}


signed main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int t = 1;
    //  gen.seed(time(0));
    //	cout << fixed;
    //	cout.precision(15);
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}