#include <bits/stdc++.h>
using namespace std;

int main() {
	int q;
	cin >> q;

	while (q--) {
		string s;
		cin >> s;

		int dels{0};
		for (auto i = s.begin()+1; i != s.end(); ++i)
			if (*i == *(i-1)) ++dels;

		cout << dels << endl;
	}
}
