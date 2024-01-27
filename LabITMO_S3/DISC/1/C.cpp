//
// Created by asi1i on 10/21/23.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;


bool ask(int u, int v) {
    cout << "1 " << u + 1 << " " << v + 1 << endl;
    fflush(stdout);
    string ans;
    cin >> ans;
    return ans == "YES";
}

vector<int> merge_path(vector<int> a, vector<int> b) {
    int left = 0;
    int right = 0;
    vector<int> ans;
    while (left < a.size() && right < b.size()) {
        if (ask(a[left], b[right])) {
            ans.push_back(a[left]);
            left++;
        } else {
            ans.push_back(b[right]);
            right++;
        }
    }
    while (left < a.size()) {
        ans.push_back(a[left]);
        left++;
    }

    while(right < b.size()) {
        ans.push_back(b[right]);
        right++;
    }
    return ans;
}

vector<int> merge(int l, int r) {
    if (r - l == 1) {
        return {l};
    }
    vector<int> left = merge(l, (r + l) / 2);
    vector<int> right = merge((r + l) / 2, r);
    return merge_path(left, right);
}

void solve(){
    int n;
    cin >> n;
    vector<int> ans = merge(0, n);
    cout << "0 ";
    for (auto u: ans) {
        cout << u + 1 << " ";
    }
}


signed main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int t = 1;
//  gen.seed(time(0));
//  cout << fixed;
//  cout.precision(15);
//    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}