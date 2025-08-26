#ifndef SOLVE_NQUEEN__H__
#define SOLVE_NQUEEN__H__

bool verifyPosition(char (*board)[N], int x, int y)
{
	for (int i = 0; i < N; i++)
		if (board[x][i] == QUEEN_CHAR || board[i][y] == QUEEN_CHAR)
			return false;

	for (int i = 0; i < N; i++)
	{
		if ((i - (x - y) < N) && (i - (x - y) >= 0))
		{
			if ((board[i][i - (x - y)] == QUEEN_CHAR))
				return false;
		}

		if ((i - (N_MAX - y - x) >= 0) && (i - (N_MAX - y - x) < N))
		{
			if (board[N_MAX - i][i - (N_MAX - y - x)] == QUEEN_CHAR)
				return false;
		}
	}

	return true;
}

bool solveNqueen(char (*board)[N], int queen)
{
	if (queen >= N) return true;

	for (int col = 0; col < N; col++)
	{
		if (verifyPosition(board, queen, col))
		{		
			board[queen][col] = QUEEN_CHAR;
					
			if (!solveNqueen(board, (queen + 1)))
			{
				board[queen][col] = EMPTY_CHAR;
				col += OPT_MV;
			}
			else return true; 
		}
	}

	return false;
}

#endif
