#include <bits/stdc++.h>
using namespace std;

int main() {
	size_t n, d;
	cin >> n >> d;

	vector<int> v(n);
	for (size_t i{0}; i < n; ++i)
		cin >> v[i];

	size_t r{d % n};
	for (size_t i{r}; i < n; ++i) cout << v[i] << ' ';
	for (size_t i{0}; i < r; ++i) cout << v[i] << ' ';
	cout << endl;
}
