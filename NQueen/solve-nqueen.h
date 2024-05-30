#ifndef SOLVE_NQUEEN_H
#define SOLVE_NQUEEN_H

bool solveNqueen(char board[N][N], int i_line)
{
	if (i_line >= N)
		return true;

	for (int i_col = 0; i_col < N; i_col++)
	{
		if (verifyPosition(board, i_line, i_col))
		{		
			board[i_line][i_col] = QUEEN_CHAR;
					
			if (solveNqueen(board, (i_line + 1)))
			{
				return true;
			}
			else
			{
				board[i_line][i_col] = EMPTY_CHAR;
				N != 6 ? i_col += N/2 : i_col++;
			}
		}
	}

	return false;
}


bool verifyPosition(char board[N][N], int x, int y)
{
	for (int i = 0; i < N; i++)
	{
		if (board[x][i] == QUEEN_CHAR || board[i][y] == QUEEN_CHAR)
			return false;			
	}

	for (int i = 0; i < N; i++)
	{	
		if (i - (x - y) < N && i - (x - y) >= 0)
		{
			if ((board[i][i - (x - y)] == QUEEN_CHAR))
			{
				return false;
			}
		}

		if ((i - (N_MAX - y - x) >= 0) && (i - (N_MAX - y - x) < N))
		{
			if (board[N_MAX - i][i - (N_MAX - y - x)] == QUEEN_CHAR)
			{
				return false;
			}
		}
	}

	return true;
}



#endif