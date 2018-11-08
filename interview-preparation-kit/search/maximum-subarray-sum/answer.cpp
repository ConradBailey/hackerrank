#include <bits/stdc++.h>
using namespace std;

int main() {
	int q;
	cin >> q;

	while (q--) {
		int n;
		cin >> n;

		long long m;
		cin >> m;

		long long tmp;
		long long cur{0};
		long long max{0};
		set<long long> prefs;
		for (int i{0}; i < n; ++i) {
			cin >> tmp;
			cur = (cur + (tmp % m)) % m;
			auto ub = prefs.upper_bound(cur);
			auto sum = (ub != prefs.end()) ? (cur - *ub + m) % m : cur;
			if (sum > max) max = sum;
			prefs.insert(cur);
		}

		cout << max << endl;
	}

}
