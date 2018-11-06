#include <bits/stdc++.h>
using namespace std;

bool share_sub(const string& s1, const string& s2) {
	unordered_set<char> a(s1.begin(), s1.end());
	for (auto c : s2) if (a.count(c) == 1) return true;
	return false;
}

int main() {
	int p;
	cin >> p;

	while (p--) {
		string s1, s2;
		cin >> s1 >> s2;

		cout << (share_sub(s1, s2) ? "YES" : "NO") << endl;
	}
}
