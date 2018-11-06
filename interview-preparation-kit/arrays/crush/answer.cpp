#include <bits/stdc++.h>
using namespace std;

int main() {
	size_t n, m;
	cin >> n >> m;

	vector<long long> v(n, 0);
	for (size_t i{0}; i < m; ++i) {
		size_t a, b;
		long long k;
		cin >> a >> b >> k;

		v[a-1] += k;
		if (b < n) v[b] -= k;
	}

	long long max_elem{0};
	long long sum{0};
	for (auto i : v) {
		sum += i;
		max_elem = max(sum, max_elem);
	}
	cout << max_elem << endl;
}
