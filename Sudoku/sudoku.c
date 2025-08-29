#include <stdio.h>
#include <stdbool.h>

#include "include/core-methods.h"
#include "include/cell.h"

#include "include/data.h"

#ifndef N 
	#define N 9 
#endif

bool solve_sudoku(short (*sudoku)[N], Cell cur);
void print_sudoku(short (*sudoku)[N]);

int main (void)
{
	int solved, unsolved;
	solved   = 0; 
	unsolved = 0;

	Cell init = { 0, 0 };
	
	for (int i = 0; i < DATA_SET_SIZE; i++)
	{
		print_sudoku(data[i]);
		
		is_valid_sudoku(data[i]) ? solve_sudoku(data[i], init) : unsolved++;

		print_sudoku(data[i]);
		printf("> verify sudoku -> data[%i] = %i\n", i, is_solved(data[i]));
	}

	return 0;
}

bool solve_sudoku(short (*sud)[N], Cell cur)
{
	if (sud[cur.x][cur.y] != 0)
		cur = next_empty_cell(sud, cur);

	if (is_solved(sud)) return true;

	for (int n = 1; n <= 9; n++)
	{
		if (verify_pos_n(sud, cur.x, cur.y, n))
		{
			sud[cur.x][cur.y] = n;

			if (!solve_sudoku(sud, cur))
			{
				sud[cur.x][cur.y] = 0;
			}
			else return true;
		}
	}

	return false;
}

void print_sudoku(short (*sudoku)[N])
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
