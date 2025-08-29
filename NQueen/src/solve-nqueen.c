#include "../include/solve-nqueen.h"

bool hardlyOptimizedVerifyPos(char (*board)[N], int x, int y)
{
	for (int i = 0; i < N; i++) // don't really need to check row due to backtracking technique
		if (board[i][y] == QUEEN_CHAR) return false;
			
	for (int i = 0; i < N; i++)
	{
		if (i - (x - y) >= 0 && i - (x - y) < y)
		{
			if (board[i][i - (x - y)] == QUEEN_CHAR)
				return false;
		}
		if (i - (NMAX - y - x) >= 0 && i - (NMAX - y - x) < N)
		{
			if (board[NMAX - i][i - (NMAX- y - x)] == QUEEN_CHAR)
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
		if (hardlyOptimizedVerifyPos(board, queen, col))
		{		
			board[queen][col] = QUEEN_CHAR;
					
			if (!solveNqueen(board, queen + 1))
			{
				board[queen][col] = EMPTY_CHAR;
				col += OPT_MV;
			}
			else return true; 
		}
	}

	return false;
}
