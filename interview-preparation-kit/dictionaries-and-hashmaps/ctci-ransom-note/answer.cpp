#include <bits/stdc++.h>
using namespace std;

int main() {
	int m, n;
	cin >> m >> n;

	string tmp;
	unordered_map<string, int> magazine;
	while (m--) {
		cin >> tmp;
		magazine[tmp] += 1;
	}

	while (n--) {
		cin >> tmp;
		if (magazine[tmp] == 0) {
			cout << "No" << endl;
			return 0;
		}
		magazine[tmp] -= 1;
	}
	cout << "Yes" << endl;
}
