#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#include "config.h"

#include "solve-nqueen.h" // def of selveNqueen() and verifyPosition()
#include "verify-solution.h" // def of verifyNqueenSolution

void printSolution(char (*board)[N]);

int main (void)
{
	char board[N][N];
	bool valid_solution = false;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			board[i][j] = EMPTY_CHAR;
	
	printf("~ Calculating N Queen for N = %i ~\n\n", N);

	clock_t begin = clock();
	valid_solution = solveNqueen(board, 0);
	clock_t end = clock();

	solution_exists ? printSolution(board) : printf("Solution for [%i x %i] does not exists\n", N, N);
	
	printf("\n> Execution Time...: %f [s]\n", (double)(end - begin)/CLOCKS_PER_SEC);
	printf("> Verifier Returned: %i\n\n", verifyNqueenSolution(board));

	return 0;
}

void printSolution(char (*board)[N])
{
	printf("> Solution for [%i x %i] board \n", N, N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			printf("%c ", board[i][j]);
	
		printf("\n");
	}
}
