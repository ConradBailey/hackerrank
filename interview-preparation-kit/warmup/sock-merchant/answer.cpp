#include <bits/stdc++.h>
using namespace std;

int main() {
	size_t n;
	cin >> n;

	int count{0};
	vector<bool> v(100, false);
	int tmp;
	while (n--) {
		cin >> tmp;
		if (v[tmp-1]) ++count;
		v[tmp-1] = !v[tmp-1];
	}

	cout << count << endl;
}
