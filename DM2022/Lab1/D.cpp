#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;


int binpow(int a, int n){
    int ans = 1;
    for (int i = 0; i < n; ++i){
        ans *= a;
    }
    return ans;
}


void solve(){
    int n;
    cin >> n;
    int rows = binpow(2, n);
    vector<int> number_clos;
    vector<vector<int>> ans;
    for (int i = 0; i < n; ++i){
        ans.push_back({1, i + 1});
    }
    bool isAllZero = true;
    for(int i = 0; i < rows; ++i){
        string cur, res;
        cin >> cur >> res;
        if (res == "1") {
            int last = ans.size() + n + 1;
            isAllZero = false;
            if (cur[0] == '0' && cur[1] == '0') {
                ans.push_back({2, n + 1, n + 2});
            } else if (cur[0] == '0' && cur[1] == '1') {
                ans.push_back({2, n + 1, 2});
            } else if (cur[0] == '1' && cur[1] == '0') {
                ans.push_back({2, 1, n + 2});
            } else {
                ans.push_back({2, 1, 2});
            }
            for (int j = 2; j < n; j++) {
                if (cur[j] == '0') {
                    ans.push_back({2, last, n + j + 1});
                } else {
                    ans.push_back({2, last, j + 1});
                }
                last++;
            }
            number_clos.push_back(last);
        }
    }
    if (isAllZero) {
        cout << n + 2 << "\n";
        cout << "1 1\n";
        cout << "2 1 " << n + 1;
    } else {
        if (number_clos.size() > 1) {
            ans.push_back({3, number_clos[0], number_clos[1]});
        }
        int last = ans.size() + n;
        for (int i = 2; i < number_clos.size(); i++) {
            ans.push_back({3, number_clos[i], last});
            last++;
        }
        cout << ans.size() + n << "\n";
        for (auto vec: ans){
            for (int i = 0; i < vec.size(); i++){
                cout << vec[i] << " ";
            }
            cout << "\n";
        }
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
