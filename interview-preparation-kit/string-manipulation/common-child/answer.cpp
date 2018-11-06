#include <bits/stdc++.h>
using namespace std;

/***** RECURSIVE VERSION *****/
// int lcss(const string &A, size_t i, const string &B, size_t j, int len=0) {
// 	if (i == A.size() || j == B.size()) return len;
// 	if (A[i] == B[j]) return lcss(A, i+1, B, j+1, len+1);

// 	return max(lcss(A, i+1, B, j, len),
// 						 lcss(A, i, B, j+1, len));
// }

int lcss(const string &A, const string &B) {
 	vector<vector<int>> dp(A.size()+1, vector<int>(B.size()+1, 0));

	for (int i{A.size()-1}; i >= 0; --i)
		for (int j{B.size()-1}; j >= 0; --j)
			dp[i][j] = (A[i] == B[j]) ? 1+dp[i+1][j+1] : max(dp[i+1][j], dp[i][j+1]);

	return dp[0][0];
}

int main() {
	string s1, s2;
	cin >> s1 >> s2;

	cout << lcss(s1, s2) << endl;
}
