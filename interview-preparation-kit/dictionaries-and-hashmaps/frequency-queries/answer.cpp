#include <bits/stdc++.h>
using namespace std;

int main() {
	int q;
	cin >> q;

	unordered_map<int, int> freq2count;
	unordered_map<int, int> elem2count;
	while (q--) {
		int op, val;
		cin >> op >> val;
		if (op == 3) cout << (freq2count[val] ? '1' : '0') << '\n';
		else if (op == 1 || elem2count[val]) {
			freq2count[elem2count[val]] -= 1;
			elem2count[val] += (op == 1) ? 1 : -1;
			freq2count[elem2count[val]] += 1;
		}
	}
}
