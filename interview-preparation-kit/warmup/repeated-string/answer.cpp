#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;

	size_t n;
	cin >> n;

	size_t a_count{0};
	for (auto i : s)
		if (i == 'a') ++a_count;

	size_t total_a{ (n / s.size()) * a_count };
	for (size_t i{0}; i < (n % s.size()); ++i)
		if (s[i] == 'a')
			++total_a;

	cout << total_a << endl;
}
