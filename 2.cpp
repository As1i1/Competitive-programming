//
// Created by asi1i on 10/9/23.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> currentState = lists;
        removeEmptyLists(currentState);
        while (currentState.size() != 1) {
            vector<ListNode*> newCurrentState((currentState.size() + 1) / 2);
            for (size_t i = 2; i <= currentState.size(); i += 2) {
                newCurrentState[i / 2 - 1] = mergeLists(currentState[i - 1], currentState[i - 2]);
            }
            if (currentState.size() % 2 == 1) {
                newCurrentState.back() = currentState.back();
            }
            currentState = newCurrentState;
        }
        return currentState[0];
    }

private:
    void removeEmptyLists(vector<ListNode*>& lists) {
        for (int i = 0; i < lists.size();) {
            if (lists[i] == nullptr) {
                swap(lists[i], lists.back());
                lists.pop_back();
            } else {
                i++;
            }
        }
    }

    ListNode* mergeLists(ListNode* first, ListNode* second) {
        ListNode* result = nullptr;
        ListNode* current = nullptr;
        while (first != nullptr && second != nullptr) {
            int minimun = first->val < second->val ? first->val : second->val;
            if (first->val < second->val) {
                first = first->next;
            } else {
                second = second->next;
            }
            if (result == nullptr) {
                result = new ListNode(minimun);
                current = result;
            } else {
                current->next = new ListNode(minimun);
                current = current->next;
            }
        }
        addTail(first, current);
        addTail(second, current);
        return result;
    }

    void addTail(ListNode* src, ListNode* dest) {
        while (src != nullptr) {
            if (dest == nullptr) {
                dest = new ListNode(src->val);
            } else {
                dest->next = new ListNode(src->val);
                dest = dest->next;
            }
            src = src->next;
        }
    }
};


ListNode* getList(vector<int> v) {
    auto *result = new ListNode(v[0]);
    ListNode *current = result;
    for (int i = 1; i < v.size(); ++i) {
        current->next = new ListNode(v[i]);
        current = current->next;
    }
    return result;
}

void solve() {
    Solution s;

    vector<ListNode*> l = {getList({1, 4, 5}), getList({1, 2, 5}), getList({2, 6})};
    ListNode* p = s.mergeKLists(l);
    for (auto* x = p; x != nullptr; x = x->next) {
        cout << x->val << " ";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int t = 1;
//	gen.seed(time(0));
//	cout << fixed;
//	cout.precision(15);
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

