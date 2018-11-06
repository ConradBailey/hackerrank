#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	string s;
	cin >> s;

	int count{0};
	int i{0};
	while  (i < n) {
		int same_count{1};
		while (i+same_count < n && s[i+same_count] == s[i]) ++same_count;
		count += (same_count*(same_count+1)) / 2;

		int max_same{same_count};
		i += same_count;
		same_count = 1;
		while (i+same_count < n && s[i+same_count] == s[i-1] &&
					 same_count <= max_same) ++same_count;
		count += same_count - 1;
	}

	cout << count << endl;
}
