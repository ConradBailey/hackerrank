#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	int tmp;
	vector<bool> v(n);
	for (size_t i{0}; i < v.size(); ++i) {
		cin >> tmp;
		v[i] = (tmp == 1);
	}

	size_t count{0};
	size_t p{0};
	while (p != v.size()-1) {
		if ((p + 2 < v.size()) && !v[p+2]) p += 2;
		else p += 1;
		++count;
	}

	cout << count << endl;
}
