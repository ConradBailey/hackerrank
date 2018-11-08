#define ull unsigned long long
#include <bits/stdc++.h>
using namespace std;

ull calc_passes(ull c, ull m, ull w, ull n) {
	auto prod = m*w;
	return (prod + (n-c) - 1) / prod;
}

void enact_greed(ull &c, ull &m, ull &w, const ull &p) {
	if (m > w) return enact_greed(c,w,m,p);

	auto cost = p * (w - m);
	if (cost > c) {
		m += c / p;
		c %= p;
	}
	else {
		m = w;
		c -= cost;
	}

	if (c >= 2*p) {
		auto max_purchases = c / (2*p);
		m += max_purchases;
		w += max_purchases;
		c %= (2*p);
	}

	if (c >= p) {
		++w;
		c -= p;
	}
}

bool make_purchase(const ull &n, ull c, ull m, ull w, const ull &p) {
	auto ratebk = calc_passes(c, m, w, n);
	enact_greed(c, m, w, p);
	c += m*w;
	auto rate = calc_passes(c, m, w, n);
	return (rate < ratebk);
}


int main() {
	ull m, w, p, n;
	cin >> m >> w >> p >> n;

	if (n / m <= w) {
		cout << 1 << endl;
		return 0;
	}

	if (p > n) {
		cout << calc_passes(0ull, m, w, n) << endl;
		return 0;
	}

	ull passes{0};
	ull c{0};
	while (c < n) {
		if (c < p) {
			auto next_passes = calc_passes(c, m, w, p);
			c += next_passes*m*w;
			passes += next_passes;
		}
		else if (make_purchase(n, c, m, w, p)) {
			enact_greed(c,m,w,p);
			c += m*w;
			++passes;
		}
		else {
			cout << passes+calc_passes(c, m, w, n) << endl;
			return 0;
		}
	}
	cout << passes << endl;
}
