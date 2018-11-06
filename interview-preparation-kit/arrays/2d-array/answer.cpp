#include <bits/stdc++.h>
using namespace std;

int hg_sum(const vector<vector<int>>& v, size_t r, size_t c) {
	return
		v[r-1][c-1]+v[r-1][c]+v[r-1][c+1]+
		v[r][c] +
		v[r+1][c-1]+v[r+1][c]+v[r+1][c+1];
}

int main() {
	vector<vector<int>> v{6, vector<int>(6)};
	for (size_t r{0}; r < 6; ++r)
		for (size_t c{0}; c < 6; ++c)
			cin >> v[r][c];

	int max_hg_sum{-9 * 5};
	for (size_t r{1}; r < 5; ++r)
		for (size_t c{1}; c < 5; ++c)
			max_hg_sum = max({hg_sum(v, r, c), max_hg_sum});

	cout << max_hg_sum << endl;
}
