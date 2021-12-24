#include <iostream>
#include <vector>
using namespace std;


signed main(){
	long long a, sm = 0, cnt = 0, i = 1;
	cin >> a;
	while(i * i <= a){
		if (a % i == 0){
			if (i * i == a){
				sm += i;
				cnt++;
			}
			else{
				sm += i;
				sm += (a / i);
				cnt += 2;
			}
		}
		i += 1;
	}
	cout << cnt << " " << sm;
	return 0;
}
