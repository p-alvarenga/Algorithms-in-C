#include <stdio.h>
#include <stdbool.h>

#define N 9

#include "./generic-components.h"
#include "./struct-cell.h"
#include "./data.h"

void printSudoku(short sudoku[N][N]);
bool solveSudoku(short sudoku[N][N], struct Cell emptyCell);

int main (void)
{
	bool solveReturn = false;

	short solved = 0, unsolved = 0;
	short i_sudoku = (27);

	struct Cell init_cell;

	init_cell.x = 0;
	init_cell.y = 0;

	for (i_sudoku = 0; i_sudoku < DATA_SET_SIZE; i_sudoku++)
	{
		printSudoku(data[i_sudoku]);
		
		verifySudokuFollowRules(data[i_sudoku]) ? solveSudoku(data[i_sudoku], init_cell) : unsolved++;

		printSudoku(data[i_sudoku]);
		printf("> verify sudoku -> data[%i] = %i\n", i_sudoku, verifySolved(data[i_sudoku]));
	}

	return 0;
}

bool solveSudoku(short sudoku[N][N], struct Cell current_cell)
{
	struct Cell it_cell = getNextEmptyCell(sudoku, current_cell);

	if (sudoku[current_cell.x][current_cell.y] != 0)
		current_cell = it_cell;

	if (verifySolved(sudoku))
		return true;

	for (short n = 1; n <= 9; n++)
	{
		if (verifyNumberPosition(sudoku, current_cell.x, current_cell.y, n) && (sudoku[current_cell.x][current_cell.y] == 0 || sudoku[it_cell.x][it_cell.y] == 0) )
		{
			if (sudoku[current_cell.x][current_cell.y] == 0)
			{
				sudoku[current_cell.x][current_cell.y] = n;
			}

			if (solveSudoku(sudoku, it_cell))
			{
				return true;
			}
			else
			{
				sudoku[current_cell.x][current_cell.y] = 0;
			}
		}
	}

	sudoku[it_cell.x][it_cell.y] = 0;
	return false;
}

void printSudoku(short sudoku[N][N])
{
	printf("\n");

	for (short i = 0; i < N; i++)
	{
		for (short j = 0; j < N; j++)
		{
			if (j % 3 == 0)
				printf("  ");
			
			sudoku[i][j] != 0 ? printf("%i ", sudoku[i][j]) : printf(". ");
		}
	
		(i + 1) % 3 == 0 ? printf("\n\n") : printf("\n");
	}

	printf("\n\n");

	return; 
}
