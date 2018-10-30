#include <bits/stdc++.h>
using namespace std;

void matrixRotation(vector<vector<int>>& matrix, int r) {
	int rows{matrix.size()};
	int cols{matrix.front().size()};
	for (int i{0}; i < min(rows, cols) / 2; ++i) {
		int row_len{rows - (i * 2)};
		int col_len{cols - (i * 2)};
		int top_row{i};
		int bot_row{rows - 1 - i};
		int left_col{i};
		int right_col{cols - 1 - i};
		int effective_rotations{r % ((row_len * 2) + (col_len * 2) - 4)};
		for (int count{0}; count < effective_rotations; ++count) {
			// top edge
			for (int col{left_col + 1}; col <= right_col; ++col)
				swap(matrix[top_row][col], matrix[top_row][col-1]);

			// right edge
			for (int row{top_row + 1}; row <= bot_row; ++row)
				swap(matrix[row][right_col], matrix[row - 1][right_col]);

			// bottom edge
			for (int col{right_col - 1}; col >= left_col; --col)
				swap(matrix[bot_row][col], matrix[bot_row][col + 1]);

			// left edge
			for (int row{bot_row - 1}; row > top_row; --row)
				swap(matrix[row][left_col], matrix[row + 1][left_col]);
		}
	}

	for (auto row : matrix) {
		for (auto v : row) cout << v << ' ';
		cout << endl;
	}
}

int main()
{
	int m, n, r;
	cin >> m >> n >> r;

	vector<vector<int>> matrix(m, vector<int>(n));
	for (int row{0}; row < m; ++row)
		for (int col{0}; col < n; ++col)
			cin >> matrix[row][col];

	matrixRotation(matrix, r);
}
