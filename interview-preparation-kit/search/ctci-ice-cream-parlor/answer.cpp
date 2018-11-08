#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int money, n;
		cin >> money >> n;

		int cost;
		unordered_map<int, int> costs2id;
		for (int id{1}; id <= n; ++id) {
			cin >> cost;
			if (costs2id.count(money - cost))
				cout << costs2id[money - cost] << ' ' << id << endl;
			costs2id[cost] = id;
		}
	}
}
