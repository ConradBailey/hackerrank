#include <bits/stdc++.h>
using namespace std;

long long num_anagram_pairs(const string& s) {
	long long count{0};
	unordered_map<string, long long> prev_seen;
	for (size_t i{0}; i < s.size(); ++i) {
		string sub{""};
		for (size_t j{i}; j < s.size(); ++j) {
			sub.insert(lower_bound(sub.begin(), sub.end(), s[j]), s[j]);
			count += prev_seen[sub];
			prev_seen[sub] += 1;
		}
	}
	return count;
}

int main() {
	int q;
	cin >> q;

	while (q--) {
		string s;
		cin >> s;

		cout << num_anagram_pairs(s) << endl;
	}
}
