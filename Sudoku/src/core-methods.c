#include "../include/core-methods.h"

bool verify_pos_n(short (*sud)[N], short x, short y, short n)
{
	for (int i = 0; i < N; i++)
	{
		if (sud[x][i] == n || sud[i][y] == n)
			return false;
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (sud[i + (x - x % 3)][j + (y - y % 3)] == n)
				return false;			
		}
	}

	return true;
}

bool is_solved(short (*sud)[N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (sud[i][j] == 0)
				return false;
		}
	}

	return true; 
}


bool is_valid_sudoku(short (*sudoku)[N])
{
	short sudoku_analyze[N][N];
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			sudoku_analyze[i][j] = sudoku[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			sudoku_analyze[i][j] = 0;

			if (sudoku[i][j] != 0)
			{
				if (!verify_pos_n(sudoku_analyze, i, j, sudoku[i][j]))
				{
					return false;
				}
			}
		
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					sudoku_analyze[i][j] = sudoku[i][j];
				}
			}
		}
	}

	return true;
}
