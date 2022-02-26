//
// Created by AMD on 06.02.2022.
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
#include <bitset>
typedef long long ll;
typedef long double ld;
using namespace std;
mt19937 gen;


bool comp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}


bool check(int m, vector<pair<int, int>>& coord, multiset<int> s) {
    int k1 = 0, k2 = 0;
    while(k2 != coord.size()){
        while (k2 < coord.size() && coord[k1].second + m > coord[k2].second) {
            s.erase(s.find(coord[k2].first));
            k2++;
        }
        if (s.empty()) return true;
        auto p1 = *s.begin(), p2 = *s.rbegin();
        if (p2 - p1 < m) return true;
        int old_k = k1;
        while (k1 < coord.size() && coord[k1].second == coord[old_k].second) {
            s.insert(coord[k1].first);
            k1++;
        }
    }
    return false;
}



void solve() {
    ll w, h;
    int n;
    cin >> w >> h >> n;
    vector<pair<int, int>> coord(n);
    multiset<int> s;
    for (int i = 0; i < n; ++i) {
        cin >> coord[i].first >> coord[i].second;
        s.insert(coord[i].first);
    }
    sort(coord.begin(), coord.end(), comp);
    int l = 0, r = min(w, h);
    while (r - l > 1) {
        int m = (r + l) / 2;
        if (check(m, coord, s)) {
            r = m;
        }
        else {
            l = m;
        }
    }
    cout << r;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    //gen.seed(time(0));
    //cout << fixed;
    //cout.precision(15);
    int t = 1;
    //   cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}