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
#include <ctime> 
#include <random>  
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;


struct Point {
	ld x, y;

	void init(ld x1, ld y1) {
		x = x1;
		y = y1;
	}

	bool eq(Point b) {
		return x == b.x && y == b.y;
	}
};

struct Vector {
	ld x, y;

	void init(ld x1, ld y1, ld x2, ld y2) {
		x = x2 - x1;
		y = y2 - y1;
	}

	void init(Point a, Point b) {
		x = b.x - a.x;
		y = b.y - a.y;
	}

	ld len() {
		return sqrt(x * x + y * y);
	}
};

ld skal(Vector a, Vector b) {
	return a.x * b.x + a.y * b.y;
}

ld vec(Vector a, Vector b) {
	return a.x * b.y - a.y * b.x;
}


struct Line {
	ld A, B, C;
	ld k, b;

	void init(ld A1, ld B1, ld C1) {
		A = A1;
		B = B1;
		C = C1;
		if (B == 0) {
			k = b = 0;
		}
		else {
			k = -A / B;
			b = -C / B;
		}
	}

	void init(ld k1, ld b1) {
		k = k1;
		b = b1;
	}

	ld get_y(ld x) {
		return k * x + b;
	}

	Vector napr() {
		Vector a;
		a.x = B;
		a.y = -A;
		return a;
	}

	bool check(Point a) {
		return A * a.x + B * a.y + C == 0;
	}
};

Point ins_lines(Line p, Line q) {
	Point c;
	if (p.B == 0) {
		c.x = -p.C / p.A; c.y = q.get_y(-p.C / p.A);
	}
	else if (q.B == 0) {
		c.x = -q.C / q.A; c.y = p.get_y(-q.C / q.A);
	}
	else {
		c.x = (q.b - p.b) / (p.k - q.k);
		c.y = p.get_y(c.x);
	}
	return c;
}

bool paral_lines(Line a, Line b) {
	Vector v1 = a.napr(), v2 = b.napr();
	return (vec(v1, v2) == 0.0);
}

ld dist_point_line(Line l, Point a) {
	//	Point p, q;
	//	p.x = 1;
	//	q.x = 0;
	//	p.y = l.get_y(1);
	//	q.y = l.get_y(0);
	//	Vector v1, v2;
	//	v1.init(p, q);
	//	v2.init(p, a);
	//	return abs(vec(v2, v1)) / v1.len();
	return abs(l.A * a.x + l.B * a.y + l.C) / sqrt(l.A * l.A + l.B * l.B);
}

void polozh_lines(Line q, Line p) {
	if (paral_lines(q, p)) {
		if (p.B == 0 && q.B == 0) {
			cout << abs(p.C / p.A - q.C / q.A);
		}
		else {
			Point a;
			a.x = 1;
			a.y = q.get_y(1);
			cout << dist_point_line(p, a) << " ";
		}
	}
	else {
		if (p.B == 0) {
			cout << -p.C / p.A << " " << q.get_y(-p.C / p.A);
		}
		else if (q.B == 0) {
			cout << -q.C / q.A << " " << p.get_y(-q.C / q.A);
		}
		else {
			Point ans = ins_lines(p, q);
			cout << ans.x << " " << ans.y;
		}
	}
}


struct Segment {
	Point a, b;

	void init(Point a1, Point b1) {
		a = a1;
		b = b1;
	}

	Line get_line() {
		Line l;
		l.init(a.y - b.y, b.x - a.x, a.x * b.y - a.y * b.x);
		return l;
	}
};


bool ins_segment_point(Segment s, Point c) {
	Vector ac, ab, bc, ba;
	ac.init(s.a, c);
	ab.init(s.a, s.b);
	ba.init(s.b, s.a);
	bc.init(s.b, c);
	return vec(ac, ab) == 0 && vec(ba, bc) == 0 && skal(ac, ab) >= 0 && skal(ba, bc) >= 0;
}


bool ins_segment_line(Segment s, Line l) {
	Point c, d;
	if (l.B != 0) {
		c.x = 0;
		c.y = l.get_y(0);
		d.x = 2;
		d.y = l.get_y(2);
	}
	else {
		c.x = l.C / l.A;
		c.y = 0;
		d.x = l.C / l.A;
		d.y = 2;
	}
	Vector ca, cb, cd;
	ca.init(c, s.a);
	cb.init(c, s.b);
	cd.init(c, d);
	ld a = vec(cd, ca), b = vec(cd, cb);
	return a * b <= 0;
}


struct Polygon {
	vector<Point> vertex;
	int n;

	void init(vector<Point> v) {
		vertex = v;
		n = v.size();
	}

	ld s() {
		ld ans = 0;
		for (int i = 1; i < n; ++i) {
			Vector a, b;
			a.init(vertex[i - 1], vertex[i]);
			b.init(vertex[i], vertex[(i + 1) % n]);
			ans += vec(a, b);
		}
		return abs(ans) / 2;
	}

	bool is_convex() {
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			Vector v1, v2;
			v1.init(vertex[i - 1], vertex[i % n]);
			v2.init(vertex[i % n], vertex[(i + 1) % n]);
			ld tmp = vec(v1, v2);
			if (ans == 0) {
				if (tmp < 0) {
					ans = -1;
				}
				else if (tmp > 0) {
					ans = 1;
				}
			}
			else if ((tmp < 0 && ans == 1) || (tmp > 0 && ans == -1)) {
				return false;
			}
		}
		return (ans != 0);
	}

	bool point_inside(Point a) {
		for (int i = 0; i < n; ++i) {
			if (vertex[i].eq(a)) {
				return true;
			}
		}
		bool flag = true;
		int cnt = 0;
		while (flag) {
			flag = false;
			Segment s;
			Point b;
			b.init(gen() % MOD, gen() % MOD);
			s.init(a, b);
			Line l = s.get_line();
			cnt = 0;
			for (int i = 0; i <= n; ++i) {
				Segment d;
				d.init(vertex[i % n], vertex[(i + 1) % n]);
				if (ins_segment_line(d, l)) {
					Line l_d = d.get_line();
					Point ans = ins_lines(l_d, l);
					if (ans.eq(vertex[i % n]) || ans.eq(vertex[(i + 1) % n])) {
						flag = true;
						break;
					}
					if (ans.x >= a.x) {
						cnt++;
					}
				}
			}
		}
		if (cnt % 2 == 1) {
			return true;
		}
		return false;
	}

};


void solve() {
	int n, x, y;
	Point c;
	cin >> n >> x >> y;
	c.init(x, y);
	vector<Point> v(n);
	for (int i = 0; i < n; ++i) {
		Point a;
		ld x, y;
		cin >> x >> y;
		a.init(x, y);
		v[i] = a;
	}
	Polygon p, p2;
	p.init(v);
	if (p.point_inside(c)) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}


int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	int t;
	//	cin >> t;
	gen.seed(time(0));
	t = 1;
	while (t--) {
		cout << fixed;
		cout.precision(15);
		solve();
	}
	return 0;
}
