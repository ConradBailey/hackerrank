#include <bits/stdc++.h>
using namespace std;

int main() {
	size_t n;
	cin >> n;

	long long r;
	cin >> r;

	long long trips{0};
	unordered_map<long long, long long> duplets;
	unordered_map<long long, long long> triplets;
	long long tmp;
	while (n--) {
		cin >> tmp;
		if (triplets.count(tmp)) trips += triplets[tmp];
		if (duplets.count(tmp)) triplets[tmp*r] += duplets[tmp];
		duplets[tmp*r] += 1;
	}

	cout << trips << endl;
}
