#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;

	vector<int> freq(26, 0);
	for (auto c : s) ++freq[c-'a'];

	int max{0};
	int max_count{0};
	int min{s.size()};
	for (auto f : freq) {
		if (f == 0) continue;
		if (f < min) min = f;
		if (f > max) {
			max = f;
			max_count = 1;
		}
		else if (f == max) ++max_count;
	}

	cout << ((max == min) ||
					 (max-1 == min && max_count == 1) ||
					 (max_count*max == s.size()-1 && min == 1) ? "YES" : "NO") << endl;
}
