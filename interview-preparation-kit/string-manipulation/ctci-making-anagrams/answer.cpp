#include <bits/stdc++.h>
using namespace std;

int main() {
	string a, b;
	cin >> a >> b;


	vector<int> afreq(26, 0);
	for (auto i : a) ++afreq[i-'a'];

	vector<int> bfreq(26, 0);
	for (auto i : b) ++bfreq[i-'a'];

	int dels{0};
	for (size_t i{0}; i < 26; ++i)
		dels += abs(afreq[i] - bfreq[i]);

	cout << dels << endl;
}
