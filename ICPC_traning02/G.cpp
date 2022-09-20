#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;

bool comp(pair<int, int> a, pair<int, int> b){
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}


void solve(){
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    vector<int> ans;
    for (int i = 0; i < n; ++i){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end(), comp);
    ans.push_back(a.back().second);
    a[n - 1].first--;
    bool ans_b = true;
    while (true){
        sort(a.begin(), a.end(), comp);
  //      for (int i = 0; i < n; ++i){
  //          cout << a[i].first << " " << a[i].second << " || ";
  //      }
  //      cout << "\n";
  //      for (auto elem: ans){
  //          cout << elem << " ";
  //      }
   //     cout << "\n";
        if (a[n - 1].first == 0){
            break;
        }
        if (a[n - 1].second == ans.back()){
            ans_b = false;
            break;
        }
        else{
            ans.push_back(a[n - 1].second);
            a[n - 1].first--;
        }
    }
    if (ans_b){
        for (int i = 0; i < ans.size(); ++i) cout << ans[i] + 1 << " ";
    }
    else{
        cout << -1;
    }
}


signed main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int t = 1;
//	gen.seed(time(0));
//	cout << fixed;
//	cout.precision(15);
//    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
