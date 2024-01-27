#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long
struct edge {
    int from, to, cost;
};
const int INF = static_cast<const long long>(1e18);

signed main() {
    int n;
    cin >> n;
    vector <edge> E;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            if (x != 0 && x != 100000) {
                E.push_back({ i,j,x });
            }
        }
    }
    int x;
    vector<int> d(n, INF), p(n, -1);
    d[0] = 0;
    for (int i = 0; i < n; i++) {
        x = -1;
        for (int j = 0; j < E.size(); j++) {
            int from = E[j].from;
            int to = E[j].to;
            int cost = E[j].cost;
            if (d[to] > d[from] + cost) {
                d[to] = max(d[from] + cost, -INF);
                p[to] = from;
                x = to;
            }
        }
    }
    if (x == -1) {
        cout << "NO" << endl;
    }
    else {
        int y = x;
        for (int i = 0; i < n; i++) {
            y = p[y];
        }
        vector <int> answer;
        int pr = y;
        while (pr != y || answer.size() <= 1) {
            answer.push_back(pr);
            pr = p[pr];
        }
        cout << "YES" << endl;
        cout << answer.size() << endl;
        for (int i = answer.size() - 1; i > -1; --i) {
            cout << answer[i] + 1 << " ";
        }
    }
}