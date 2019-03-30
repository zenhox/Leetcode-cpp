void recu_rotate(vector<vector<int>> & matrix, int i,int j,int n) {
	if (n <= 1)
		return;
	int for_count = 3 * (n - 1);
	int old_row = i, old_col = j;
	int base_row = i, base_col = j;
	for (int i = 0; i < for_count; ++i) {
		int new_row = old_col, new_col = matrix.size() - 1 - old_row;
		if (new_row == base_row && new_col == base_col) {
			old_row = base_row, old_col = base_col+1;
			base_row = base_row, base_col = base_col + 1;
			new_row = old_col, new_col = matrix.size() - 1 - old_row;
		}
		swap(matrix[base_row][base_col], matrix[new_row][new_col]);
		old_row = new_row, old_col = new_col;
	}
	recu_rotate(matrix, i + 1, j + 1, n - 2);
}
void rotate(vector<vector<int>>& matrix) {
	if (matrix.size() <= 1)
		return;
	recu_rotate(matrix, 0, 0, matrix.size());
}