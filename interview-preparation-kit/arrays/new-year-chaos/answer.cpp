#include <bits/stdc++.h>
using namespace std;

string min_swaps(const vector<int>& v) {
	size_t count{0};
	for (int i{v.size()-1}; i >= 0; --i) {
		if (v[i] - (i+1) > 2) return "Too chaotic";
		for (int j{max(0, v[i]-2)}; j < i; ++j) if (v[j] > v[i]) ++count;
	}

	return to_string(count);
}

int main() {
	size_t t;
	cin >> t;

	while (t--) {
		size_t n;
		cin >> n;

		vector<int> v(n);
		for (size_t i{0}; i < n; ++i) cin >> v[i];
		cout << min_swaps(v) << endl;
	}
}
