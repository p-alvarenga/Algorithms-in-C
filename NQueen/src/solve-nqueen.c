#include "../include/solve-nqueen.h"

bool verify_pos_above(char (*board)[N], int x, int y)
{
	for (int i = 0; i < x; i++) // don't really need to check row due to backtracking technique
		if (board[i][y] == QUEEN_CHAR) return false;
			
	for (int i = 0; i < N; i++) // UPDATE: iterates only from x to above
	{
		if (check_range(i - (x - y), 0, y))
		{
			if (board[i][i - (x - y)] == QUEEN_CHAR)
				return false;
		}
	
		if (check_range(i - (NMAX - y - x), y, NMAX))
		{
			if (board[NMAX - i][i - (NMAX - y - x)] == QUEEN_CHAR)
				return false;
		}
	}

	return true;
}

bool solve_nqueen(char (*board)[N], int queen)
{
	if (queen >= N) return true;

	for (int col = 0; col < N; col++)
	{
		if(verify_pos_above(board, queen, col))
		{		
			board[queen][col] = QUEEN_CHAR;
					
			if (!solve_nqueen(board, queen + 1))
			{
				board[queen][col] = EMPTY_CHAR;
				col += OPT_MV;
			}
			else return true; 
		}
	}

	return false;
}
