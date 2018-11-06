#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	int count{0};
	int altitude{0};
	char c;
	while (n--) {
		cin >> c;

		altitude += ((c == 'U') ? 1 : -1);
		if (altitude == 0 && c == 'U')
			++count;
	}

	cout << count << endl;
}
