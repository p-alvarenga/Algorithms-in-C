#ifndef GENERIC_COMPONENTS_H
#define GENERIC_COMPONENTS_H

bool verifySolved(short sudoku[N][N]);
bool verifyNumberPosition(short sudoku[N][N], short x, short y, short n_);
bool verifySudokuFollowRules(short sudoku[N][N]);

bool verifyNumberPosition(short sudoku[N][N], short x, short y, short n_)
{
	if (n_ == 0)
		return true;

	for (short i = 0; i < N; i++)
	{
		if ((sudoku[x][i] == n_ || sudoku[i][y] == n_))
		{
			return false;
		}
	}

	for (short i = 0; i < 3; i++)
	{
		for (short j = 0; j < 3; j++)
		{
			if (sudoku[i + (x - x % 3)][j + (y - y % 3)] == n_)
			{
				return false;			
			}
		}
	}

	return true;
}

bool verifySolved(short sudoku[N][N])
{

	for (short i = 0; i < N; i++)
	{
		for (short j = 0; j < N; j++)
		{
			if (sudoku[i][j] == 0)
				return false;
		}
	}

	return verifySudokuFollowRules(sudoku);
}

bool verifySudokuFollowRules(short sudoku[N][N])
{
	short sudoku_analyze[N][N];
	
	for (short i = 0; i < N; i++)
	{
		for (short j = 0; j < N; j++)
		{
			sudoku_analyze[i][j] = sudoku[i][j];
		}
	}

	for (short i = 0; i < N; i++)
	{
		for (short j = 0; j < N; j++)
		{
			sudoku_analyze[i][j] = 0;

			if (sudoku[i][j] != 0)
			{
				if (!verifyNumberPosition(sudoku_analyze, i, j, sudoku[i][j]))
				{
					return false;
				}
			}
		
			for (short i = 0; i < N; i++)
			{
				for (short j = 0; j < N; j++)
				{
					sudoku_analyze[i][j] = sudoku[i][j];
				}
			}

		}
	}

	return true;
}

#endif