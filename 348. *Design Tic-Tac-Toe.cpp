class TicTacToe {
public:
	/** Initialize your data structure here. */
	TicTacToe(int n) {
		board.resize(n, vector<int>(n, 0));
	}

	/** Player {player} makes a move at ({row}, {col}).
	@param row The row of the board.
	@param col The column of the board.
	@param player The player, can be either 1 or 2.
	@return The current winning condition, can be either:
	0: No one wins.
	1: Player 1 wins.
	2: Player 2 wins. */
	int move(int row, int col, int player) {
		board[row][col] = player;
		int i = 0, j = 0, N = board.size();
		for (i = 0; i < N; ++i) {
			if (board[i][0] != 0) {
				for (j = 1; j < N; ++j) {
					if (board[i][j] != board[i][j - 1]) break;
				}
				if (j == N) return board[i][0];
			}
		}
		for (j = 0; j < N; ++j) {
			if (board[0][j] != 0) {
				for (i = 1; i < N; ++i) {
					if (board[i][j] != board[i - 1][j]) break;
				}
				if (i == N) return board[0][j];
			}
		}
		if (board[0][0] != 0) {
			for (i = 1; i < N; ++i) {
				if (board[i][i] != board[i - 1][i - 1]) break;
			}
			if (i == N) return board[0][0];
		}
		if (board[N - 1][0] != 0) {
			for (i = 1; i < N; ++i) {
				if (board[N - i - 1][i] != board[N - i][i - 1]) break;
			}
			if (i == N) return board[N - 1][0];
		}
		return 0;
	}

	vector<vector<int>> board;
};
