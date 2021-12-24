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
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;
vector<int> a;


void f(int i){
	if (a[i] > a[i + 1]){
		swap(a[i], a[i + 1]);
	}
}


bool check(){
	for(int i = 0; i < a.size() - 1; ++i){
		if (a[i] > a[i + 1]){
			return false;
		}
	}	
	return true;
}


void solve(){
	int n;
	cin >> n;
	a.resize(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	int cnt = 1;
	while(!check()){
		int start;
		if (cnt % 2 == 0){
			start = 1;
		}
		else{
			start = 0;
		}
		for(int i = start; i < n - 1; i += 2){
			f(i);
		}
		cnt++;
	}
	cout << cnt - 1 << "\n";
}


int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	int t;
//	gen.seed(time(0));
//	cout << fixed;
//	cout.precision(15);
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
