#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	int pot_luck{0};
	priority_queue<int, vector<int>, greater<int>> q;
	while (k--) q.push(0);

	int tmpluck;
	bool important;
	while (n--) {
		cin >> tmpluck >> important;

		if (!important) pot_luck += tmpluck;
		else if (!q.empty() && tmpluck > q.top()) {
			pot_luck -= q.top();
			q.pop();
			q.push(tmpluck);
		}
		else pot_luck -= tmpluck;
	}

	while (!q.empty()) {
		pot_luck += q.top();
		q.pop();
	}

	cout << pot_luck << endl;
}
