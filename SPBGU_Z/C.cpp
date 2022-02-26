#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen(998244353);



void get_ans1(vector<string> a, int n) {
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        vector<bool> t(a[i].size());
        for (int j = 0; j < a[i].size(); ++j) {
            if (a[i][j] - '0' == gen() % 2) {
                cnt++;
                t[j] = true;
            }
            else {
                t[j] = false;
            }

        }
        if (a[i].size() <= 4) {
            if (a[i] == "00") a[i] = "?0";
            else if (a[i] == "10") a[i] = "1?";
            else if (a[i] == "01") a[i] = "0?";
            else if (a[i] == "11") a[i] = "?1";
            else if (a[i] == "000") a[i] = "?00";
            else if (a[i] == "001") a[i] = "0?1";
            else if (a[i] == "010") a[i] = "?1?";
            else if (a[i] == "011") a[i] = "01?";
            else if (a[i] == "100") a[i] = "1?0";
            else if (a[i] == "101") a[i] = "?0?";
            else if (a[i] == "110") a[i] = "11?";
            else if (a[i] == "111") a[i] = "?11";
            else if (a[i] == "0000") a[i] = "??00";
            else if (a[i] == "0001") a[i] = "?0?1";
            else if (a[i] == "0010") a[i] = "?0?0";
            else if (a[i] == "0011") a[i] = "??11";
            else if (a[i] == "0100") a[i] = "?1?0";
            else if (a[i] == "0101") a[i] = "?1?1";
            else if (a[i] == "0110") a[i] = "?11?";
            else if (a[i] == "0111") a[i] = "0???";
            else if (a[i] == "1000") a[i] = "1??0";
            else if (a[i] == "1001") a[i] = "1??1";
            else if (a[i] == "1010") a[i] = "1?1?";
            else if (a[i] == "1011") a[i] = "10??";
            else if (a[i] == "1100") a[i] = "11??";
            else if (a[i] == "1101") a[i] = "1?0?";
            else if (a[i] == "1110") a[i] = "??1?";
            else if (a[i] == "1111") a[i] = "????";
        }
        else if (a[i].size() <= 10){
            int cnt_1 = 0, cnt_0 = 0;
            for (int j = 0; j < a[i].size(); ++j){
                if (a[i][j] == '0') cnt_0++;
                else cnt_1++;
            }
            if (cnt_1 == a[i].size() || cnt_0 == a[i].size()) {
                for (int j = 1; j < a[i].size(); ++j) {
                    a[i][j] = '?';
                }
            }
            else {
                if (cnt_0 == 1){
                    for (int j = 0; j < a[i].size() && cnt_1 != 2; j++){
                        if (a[i][j] == '1') {
                            a[i][j] = '?';
                            cnt_1--;
                        }
                    }
                }
                else if (cnt_1 == 1){
                    for (int j = 0; j < a[i].size() && cnt_0 != 2; j++){
                        if (a[i][j] == '0') {
                            a[i][j] = '?';
                            cnt_0--;
                        }
                    }
                }
                else if (cnt_0 > cnt_1){
                    for (int j = 0; j < a[i].size(); ++j){
                        if (a[i][j] == '0') a[i][j] = '?';
                    }
                }
                else{
                    for (int j = 0; j < a[i].size(); ++j){
                        if (a[i][j] == '1') a[i][j] = '?';
                    }
                }
            }
        }
        else if (cnt > a[i].size() / 2) {
            for (int j = 0; j < a[i].size(); ++j) {
                if (t[j]) a[i][j] = '?';
            }
        }
        else {
            for (int j = 0; j < a[i].size(); ++j) {
                if (!t[j]) a[i][j] = '?';
            }
        }
        cout << a[i] << "\n";
    }
}



void get_ans2(vector<string> a, int n) {
    vector<int> tmp = { '0', '1' };
    for (int i = 0; i < n; ++i) {
        vector<int> m(a[i].size());
        bool flag = true;
        for (int j = 0; j < a[i].size(); ++j) {
            m[j] = gen() % 2;
            if (a[i][j] != '?') {
                if (a[i][j] - '0' == m[j]) {
                    flag = true;
                }
                else {
                    flag = false;
                }
            }
        }
        if (a[i].size() <= 4){
            if (a[i] == "?0") a[i] = "00";
            else if (a[i] == "1?") a[i] = "10";
            else if (a[i] == "0?") a[i] = "01";
            else if (a[i] == "?1") a[i] = "11";
            else if (a[i] == "?00") a[i] = "000";
            else if (a[i] == "0?1") a[i] = "001";
            else if (a[i] == "?1?") a[i] = "010";
            else if (a[i] == "01?") a[i] = "011";
            else if (a[i] == "1?0") a[i] = "100";
            else if (a[i] == "?0?") a[i] = "101";
            else if (a[i] == "11?") a[i] = "110";
            else if (a[i] == "?11") a[i] = "111";
            else if (a[i] == "??00") a[i] = "0000";
            else if (a[i] == "?0?1") a[i] = "0001";
            else if (a[i] == "?0?0") a[i] = "0010";
            else if (a[i] == "??11") a[i] = "0011";
            else if (a[i] == "?1?0") a[i] = "0100";
            else if (a[i] == "?1?1") a[i] = "0101";
            else if (a[i] == "?11?") a[i] = "0110";
            else if (a[i] == "0???") a[i] = "0111";
            else if (a[i] == "1??0") a[i] = "1000";
            else if (a[i] == "1??1") a[i] = "1001";
            else if (a[i] == "1?1?") a[i] = "1010";
            else if (a[i] == "10??") a[i] = "1011";
            else if (a[i] == "11??") a[i] = "1100";
            else if (a[i] == "1?0?") a[i] = "1101";
            else if (a[i] == "??1?") a[i] = "1110";
            else if (a[i] == "????") a[i] = "1111";
        }
        else if (a[i].size() <= 10){
            int cnt_1 = 0, cnt_0 = 0;
            for (int j = 0; j < a[i].size(); ++j){
                if (a[i][j] == '0') cnt_0++;
                else if (a[i][j] == '1') cnt_1++;
            }
            if (cnt_1 == 1 && cnt_0 == 0){
                for (int j = 0; j < a[i].size(); ++j){
                    if (a[i][j] == '?') a[i][j] = '1';
                }
            }
            else if (cnt_1 == 0 && cnt_0 == 1){
                for (int j = 0; j < a[i].size(); ++j){
                    if (a[i][j] == '?') a[i][j] = '0';
                }
            }
            else if (cnt_0 == 1 && cnt_1 == 2){
                for (int j = 0; j < a[i].size(); ++j){
                    if (a[i][j] == '?') a[i][j] = '1';
                }
            }
            else if (cnt_1 == 1 && cnt_0 == 2){
                for (int j = 0; j < a[i].size(); ++j){
                    if (a[i][j] == '?') a[i][j] = '0';
                }
            }
            else if (cnt_1 == 0){
                for (int j = 0; j < a[i].size(); ++j){
                    if (a[i][j] == '?') a[i][j] = '1';
                }
            }
            else if (cnt_0 == 0) {
                for (int j = 0; j < a[i].size(); ++j) {
                    if (a[i][j] == '?') a[i][j] = '0';
                }
            }
        }
        else{
            for (int j = 0; j < a[i].size(); ++j) {
                if (a[i][j] == '?') {
                    if (flag) a[i][j] = tmp[1 - m[j]];
                    else a[i][j] = tmp[m[j]];
                }
            }
        }
        cout << a[i] << "\n";
    }
}


void solve() {
    int n;
    cin >> n;
    vector<string> a(n);
    bool flag = false;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (flag) continue;
        for (int j = 0; j < a[i].size(); ++j) {
            if (a[i][j] == '?') {
                flag = true;
                break;
            }
        }
    }
    if (flag) {
        get_ans2(a, n);
    }
    else {
        get_ans1(a, n);
    }
}


signed main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int t = 1;
    //	cout << fixed;
    //	cout.precision(15);
    //    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}