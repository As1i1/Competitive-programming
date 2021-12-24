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
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll ll_INF = 1e18;


int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while(t--){
		int xa, ya, xb, yb, xf, yf;
		cin >> xa >> ya >> xb >> yb >> xf >> yf;
		if (xa == xb && xa == xf && min(ya, yb) < yf && max(ya, yb) > yf){
			cout << abs(ya - yb) + 2 << "\n";
		}
		else if (ya == yb && yb == yf && min(xa, xb) < xf && max(xa, xb) > xf){
			cout << abs(xa - xb) + 2 << "\n";
		}
		else{
			cout << abs(xa - xb) + abs(yb - ya) << "\n";
		}
	}
	return 0;
}
