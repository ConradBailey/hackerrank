#include <bits/stdc++.h>
using namespace std;

bool too_much(const vector<int>& m, long long days, int goal) {
	long long p{0};
	for (auto i : m) {
		p += days/i;
		if (p >= goal) return true;
	}
	return false;
}

int main() {
	int n;
	long long goal;
	cin >> n >> goal;

	vector<int> machines(n);
	long long fastest{numeric_limits<long long>::max()};
	double recip{0};
	for (auto& i : machines) {
		cin >> i;
		if (i < fastest) fastest = i;
		recip += 1.0/i;
	}

	long long lb{static_cast<long long>(goal / recip)};
	long long ub{min(goal * fastest, lb * 2)};
	long long mid;

	while (lb < ub) {
		mid = (ub + lb) / 2;
		if (too_much(machines, mid, goal))
			ub = mid;
		else
			lb = mid + 1;
	}
	cout << lb << endl;
}
