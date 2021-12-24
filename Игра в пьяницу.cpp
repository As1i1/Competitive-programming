#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;



int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	queue<int> first, second;
	for(int i = 0; i < 5; ++i){
		int tmp;
		cin >> tmp;
		first.push(tmp);
	}
	for(int i = 0; i < 5; ++i){
		int tmp;
		cin >> tmp;
		second.push(tmp);
	}
	int i = 0;
	while (i < 1e6 && !first.empty() && !second.empty()){
		int p1 = first.front(), p2 = second.front();
		first.pop();
		second.pop();
		if (p1 == 0 && p2 == 9){
			first.push(p1);
			first.push(p2);
		}
		else if (p2 == 0 && p1 == 9){
			second.push(p1);
			second.push(p2);
		}
		else{
			if (p1 > p2){
				first.push(p1);
				first.push(p2);
			}
			else{
				second.push(p1);
				second.push(p2);
			}
		}
		i += 1;
	}
	if (first.empty()){
		cout << "second " << i;
	}
	else if (second.empty()){
		cout << "first " << i;
	}
	else{
		cout << "botva";
	}
	return 0;
}
