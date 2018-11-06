#include <bits/stdc++.h>
using namespace std;

template <typename T>
int merge(vector<T>& v, size_t p, size_t q, size_t r) {
	vector<T> L(v.begin()+p, v.begin()+q+1);
	vector<T> R(v.begin()+q+1, v.begin()+r+1);
	for (auto a : {&L, &R}) a->push_back(numeric_limits<T>::max());

	int swap_count{0};
	size_t i{0}, j{0};
	for (size_t k{p}; k <= r; ++k) {
		if (L[i] <= R[j]) v[k] = L[i++];
		else {
			swap_count += L.size() - i - 1;
			v[k] = R[j++];
		}
	}
	return swap_count;
}

template <typename T>
int mergesort(vector<T>& v, size_t p, size_t r) {
	if (p < r) {
		size_t q{(p+r) / 2};
		return
			mergesort(v, p, q) +
			mergesort(v, q+1, r) +
			merge(v, p, q, r);
	}
	return 0;
}

int main() {
	int n;
	cin >> n;

	vector<int> v(n);
	while (n--) cin >> v[v.size()-1-n];

	cout << "Array is sorted in " << mergesort(v, 0, v.size()-1) << " swaps.\n";
	cout << "First Element: " << v.front() << '\n'
			 << "Last Element: " << v.back() << '\n';
}
