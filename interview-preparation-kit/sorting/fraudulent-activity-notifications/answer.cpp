#include <bits/stdc++.h>
using namespace std;

double get_med(const vector<int>& counts, int d) {
	int medi{(d/2) + ((d % 2 == 1) ? 0 : -1)};
	int sum{0};
	double l, r;
	int i{0};
	while (sum <= medi) sum += counts[i++];
	l = i-1;

	if (d % 2 == 1) return l;

	while (sum <= medi+1) sum += counts[i++];
	r = i-1;

	return (l+r)/2;
}

int main() {
	size_t n, d;
	cin >> n >> d;

	vector<int> v(n);
	while (n--) cin >> v[v.size()-1 - n];

	vector<int> counts(201, 0);
	for (size_t i{0}; i < d; ++i) ++counts[v[i]];

	int alerts{0};
	double med;
	for (size_t i{d}; i < v.size(); ++i) {
		med = get_med(counts, d);

		if (v[i] >= 2 * med) ++alerts;

		--counts[v[i-d]];
		++counts[v[i]];
	}

	cout << alerts << endl;
}
