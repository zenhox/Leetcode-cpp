class Solution {

public:
	bool dfs(int i, int j,
		vector<vector<char>>& board,
		vector<unordered_map<int, bool>> &blk_mark,
		vector<unordered_map<int, bool>> &row_mark,
		vector<unordered_map<int, bool>> &col_mark)
	{
		// 找到一个可选的i,j
		while (board[i][j] != '.') {
			if (i == 8 && j == 8)
				return true;
			if (j < 8)
				j++;
			else {
				i += 1;
				j = 0;
			}
		}
		// 尝试添加一个合适的值
		int blk_id = (i / 3) * 3 + j / 3;
		for (int num = 1; num <= 9; num++) {
			if (row_mark[i][num] != true && col_mark[j][num] != true && blk_mark[blk_id][num] != true) {
				row_mark[i][num] = true;
				col_mark[j][num] = true;
				blk_mark[blk_id][num] = true;
				board[i][j] = num + '0';
				if (i == 8 && j == 8) {
					return true;
				}
				int next_i = i, next_j = j + 1;
				if (next_j == 9) {
					next_i++; next_j = 0;
				}
				if (dfs(next_i, next_j, board, blk_mark, row_mark, col_mark) == true) {
					return true;
				}
				else {
					row_mark[i][num] = false; col_mark[j][num] = false; blk_mark[blk_id][num] = false;
					board[i][j] = '.';
				}
			}
		}
		return false;
	}

	void solveSudoku(vector<vector<char>>& board) {
		unordered_map<int, bool> all_false;
		for (int i = 1; i <= 9; i++) {
			all_false[i] = false;
		}
		vector<unordered_map<int, bool>> blk_mark(9, all_false);
		vector<unordered_map<int, bool>> row_mark(9, all_false);
		vector<unordered_map<int, bool>> col_mark(9, all_false);
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				int blk_id = (i / 3) * 3 + j / 3;
				if (board[i][j] != '.') {
					row_mark[i][board[i][j] - '0'] = true;
					blk_mark[blk_id][board[i][j] - '0'] = true;
				}
				if (board[j][i] != '.')
					col_mark[i][board[j][i] - '0'] = true;
			}
		}
		dfs(0, 0, board, blk_mark, row_mark, col_mark);
	}
};