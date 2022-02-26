#include <bits/stdc++.h>

using namespace std;


bool check(long long n){
	set<long long> s;
	long long i = 1;
	while(i * i <= n){
		if (n % i == 0){
			long long t = n / i;
			if (t % 2 == 1){
				s.insert(t);
			}
			if (i % 2 == 1){
				s.insert(i);
			}
		}
		i++;
		if (s.size() > 5) return false;
	}
	if (s.size() == 5){
		return true;
	}
	return false;
}


int main() {
	vector<long long> ans;
	for (long long x = 45000000; x <= 50000000; x++){
		if (check(x)){
			ans.push_back(x);
		}
		cout << x << " " << ans.size() << "\n";
	}
	for (auto elem: ans){
		cout << elem << " ";
	}
    return 0;
}
