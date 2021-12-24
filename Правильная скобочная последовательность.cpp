#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <queue>
#include <stack>
using namespace std;



int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	string s;
	cin >> s;
	stack<char> st;
	for(int i = 0; i < s.size(); ++i){
		if (s[i] == '(' || s[i] == '{' || s[i] == '['){
			st.push(s[i]);
		}
		else{
			if (st.empty()){
				cout << "no";
				return 0;
			}
			else if (st.top() == '(' && s[i] == ')'){
				st.pop();
			}
			else if (st.top() == '{' && s[i] == '}'){
				st.pop();
			}
			else if (st.top() == '[' && s[i] == ']'){
				st.pop();
			}
			else{
				cout << "no";
				return 0;
			}
		}
	}
	if (st.empty()){
		cout << "yes";
		return 0;
	}
	else{
		cout << "no";
		return 0;
	}
	return 0;
}
