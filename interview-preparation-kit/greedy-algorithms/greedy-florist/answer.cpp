#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	priority_queue<int> costs;
	int tmp;
	while (n--) {
		cin >> tmp;
		costs.push(tmp);
	}

	long long cost{0};
	int count{0};
	while (!costs.empty()) {
		cost += costs.top() * ((count / k) + 1);
		costs.pop();
		++count;
	}

	cout << cost << endl;
}
