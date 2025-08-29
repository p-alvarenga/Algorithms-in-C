#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#include "include/config.h"
#include "include/solve-nqueen.h" 
//#include "include/verify-solution.h"

void print_solution(char (*board)[N], double time);

int main (void)
{
	char board[N][N];
	bool solve = false;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			board[i][j] = EMPTY_CHAR;

	printf("~ Calculating N Queen for N = %i...\n\n", N);

	clock_t begin = clock();
	solve = solve_nqueen(board, 0);
	clock_t end = clock();

	if (solve) 
	{
		print_solution(board, (double)(end - begin)/CLOCKS_PER_SEC);
	}
	else 
	{
		printf("Solution for N = %i does not exist\n", N);
	}

	 //printf("> Verifier Returned: %i\n\n", verifyNqueenSolution(board));

	return 0;
}

void print_solution(char (*board)[N], double time)
{
	printf("> Solution for N = %i\n", N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			printf("%c ", board[i][j]);
	
		printf("\n");
	}

	printf("> Execution time for N = %i: %.4f seconds\n\n", N, time);
}
