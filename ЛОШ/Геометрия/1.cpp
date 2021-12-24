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

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ll ll_INF = 1e18;


struct Point{
	ll x, y;
	
	bool eq(Point p){
		return (p.x == x && p.y == y);
	}
};

struct Vector{
	ll x, y;
	
	void init(ll x1, ll y1, ll x2, ll y2){
		x = x1 - x2;
		y = y1 - y2;
	}
	
	Vector sum(Vector other){
		Vector a;
		a.init(x, other.x, y, other.y);
		return a;
	}
	
	ll skal(Vector a){
		return x * a.x + y * a.y;
	} 
	
	ll vec(Vector a){
		return x * a.y - y * a.x;
	}
	
	ll len(){
		return sqrt(x * x + y * y);
	}
};


void solve(){
	ll x1, y1, x2, y2;
	Vector a, b, c;
	cin >> x1 >> y1 >> x2 >> y2;
	a.init(x1, y1, x2, y2);
	cin >> x1 >> y1 >> x2 >> y2;
	b.init(x1, y1, x2, y2);
	cout << a.len() << " " << b.len() << "\n";
	c = a.sum(b);
	cout << c.x << " " << c.y << "\n";
	cout << a.skal(b) << " " << a.vec(b) << "\n";
	cout << abs(a.vec(b)) / 2;
}


int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
