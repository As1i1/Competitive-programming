//
// Created by AMD on 26.02.2022.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;


bool check_queue(vector<pair<int, int>> op){
    queue<int> q;
    for (int i = 0; i < op.size(); ++i){
        if (op[i].first == 1){
            if (q.front() != op[i].second) return false;
            q.pop();
        }
        else{
            q.push(op[i].second);
        }
    }
    return true;
}


bool check_stack(vector<pair<int, int>> op){
    stack<int> q;
    for (int i = 0; i < op.size(); ++i){
        if (op[i].first == 1){
            if (q.top() != op[i].second) return false;
            q.pop();
        }
        else{
            q.push(op[i].second);
        }
    }
    return true;
}


void solve(){
    int n;
    cin >> n;
    vector<pair<int, int>> op(n);
    for (int i = 0; i < n; ++i){
        string s; int c = 0;
        cin >> s;
        if (s == "pop"){
            c = 1;
        }
        cin >> op[i].second;
        op[i].first = c;
    }
    bool ans1 = check_queue(op), ans2 = check_stack(op);
    if (ans1 && ans2) cout << "both\n";
    else if (ans1) cout << "queue\n";
    else if (ans2) cout << "stack\n";
    else cout << "none\n";
}


signed main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int t = 1;
//	gen.seed(time(0));
//	cout << fixed;
//	cout.precision(15);
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
