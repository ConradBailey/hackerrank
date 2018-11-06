#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;


	vector<int> p(n);
	while (n--) cin >> p[p.size()-1 - n];

	sort(p.begin(), p.end());
	size_t count;
	for (count = 0; count < p.size() && k - p[count] >= 0; ++count)
		k -= p[count];

	cout << count << endl;
}
