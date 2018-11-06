#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> v(n);
	while (n--) cin >> v[v.size()-1 - n];
	sort(v.begin(), v.end());

	int min_unfairness{v[k-1]-v[0]};
	for (int i{k}; i < v.size(); ++i)
		min_unfairness = min(v[i] - v[i - (k-1)], min_unfairness);

	cout << min_unfairness << endl;
}
