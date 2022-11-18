#include <bits/stdc++.h>

#include <random>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;


void printC(vector<int> c, int n){
    for (int i = 0; i < c.size(); i++){
        if (i != 0){
            cout << "&";
        }
        if (c[i] >= n) {
            cout << "~" << c[i] - n + 1;
        } else {
            cout  << c[i] + 1;
        }
    }
}


void solve(){
    int n;
    cin >> n;
    vector<bitset<33>> numbers(2 * n);
    for (int i = 0; i < n; ++i) {
        ll tmp;
        cin >> tmp;
        numbers[i] = bitset<33>(tmp);
        numbers[i + n] = numbers[i];
        numbers[i + n].flip();
    }
    ll s;
    cin >> s;
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
    for (int i = 0; i < 10000; i++) {
        vector<int> r(allC.size());
        for (int j = 0; j < allC.size(); j++) {
            r[j] = j;
        }
        shuffle(r.begin(), r.end(), std::mt19937(std::random_device()()));
//        for (int i = 0; i < r.size(); i++) {
//            cout << r[i] << " ";
//        }
//        cout << "\n";
        bitset<33> ans(0);
        int count;
        if (allC.size() < 4) {
            count = gen() % 3 + 1;
        }
        else if (allC.size() < 32) {
            count = gen() % 5 + 1;
        } else {
            count = gen() % 10 + 1;
        }
        for (int j = 0; j < count; j++) {
            ans |= allC[r[j]];
        }
        if (ans == s) {
            for (int j = 0; j < count; ++j) {
                if (j != 0) {
                    cout << "|";
                }
                printC(index[r[j]], n / 2);
            }
            return;
        }
    }
    cout << "Impossible";
}


signed main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int t = 1;
	gen.seed(time(0));
//	cout << fixed;
//	cout.precision(15);
//    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
