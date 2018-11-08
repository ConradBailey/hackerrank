#include <bits/stdc++.h>
using namespace std;

int main() {
	int na, nb, nc;
	cin >> na >> nb >> nc;

	int tmp;
	set<int> as, bs, cs;
	for (auto p : {make_pair(&as, na), {&bs, nb}, {&cs, nc}}) {
		while (p.second--) {
			cin >> tmp;
			p.first->insert(tmp);
		}
	}

	vector<int> av(as.begin(), as.end());
	vector<int> cv(cs.begin(), cs.end());

	auto count = distance(av.begin(), av.begin());
	auto abeg = av.begin();
	auto cbeg = cv.begin();
	for (auto q : bs) {
		abeg = upper_bound(abeg, av.end(), q);
		cbeg = upper_bound(cbeg, cv.end(), q);
		count += distance(av.begin(), abeg) * distance(cv.begin(), cbeg);
	}

	cout << count << endl;

}
