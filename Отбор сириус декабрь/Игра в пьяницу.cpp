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


void solve(){
	queue<int> first, second;
	for(int i = 0; i < 5; ++i){
		int x;
		cin >> x;
		first.push(x);
	}
	for(int i = 0; i < 5; ++i){
		int x;
		cin >> x;
		second.push(x);
	}
	for(int i = 0; i < (int)1e6; ++i){
		if (first.empty()){
			cout << "second " << i;
			return;
		}
		if (second.empty()){
			cout << "first " << i;
			return;
		}
		int f = first.front(), s = second.front();
		first.pop();
		second.pop();
		if (f == 0 && s == 9){
			first.push(f);
			first.push(s);
		}
		else if (f == 9 && s == 0){
			second.push(f);
			second.push(s);
		}
		else if (f > s){
			first.push(f);
			first.push(s);
		}
		else{
			second.push(f);
			second.push(s);
		}
	}
	cout << "botva";
}


signed main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	int t = 1;
//	gen.seed(time(0));
//	cout << fixed;
//	cout.precision(15);
//	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
