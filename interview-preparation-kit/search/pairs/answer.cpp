#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	int count{0};
	int tmp;
	unordered_map<int, int> num2count;
	while (n--) {
		cin >> tmp;
		count += num2count[tmp-k];
		count += num2count[tmp+k];
		num2count[tmp] += 1;
	}

	cout << count << endl;
}
