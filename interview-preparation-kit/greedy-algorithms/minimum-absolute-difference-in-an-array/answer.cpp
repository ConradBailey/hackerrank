#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> v(n);
	while (n--) cin >> v[v.size()-1 - n];
	sort(v.begin(), v.end());

	int min_diff{abs(v[0]-v[1])};
	for (int i{2}; i < v.size(); ++i)
		min_diff = min(abs(v[i]-v[i-1]), min_diff);
	cout << min_diff << endl;
}
