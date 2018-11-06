#include <bits/stdc++.h>
using namespace std;

int min_swaps(vector<size_t>& v) {
	int swaps{0};
	for (size_t i{0}; i < v.size()-1; ++i) {
		if (v[i] == i+1)
			continue;

		size_t j{i+1};
		while (v[j] != i+1) ++j;
		swap(v[i], v[j]);
		++swaps;
	}
	return swaps;
}


int main() {
	size_t n;
	cin >> n;

	vector<size_t> v(n);
	for (auto i = v.begin(); i != v.end(); ++i)
		cin >> *i;
	cout << min_swaps(v) << endl;
}
