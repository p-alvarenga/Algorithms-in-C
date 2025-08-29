#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define TESTING 1
#include "include/config.h"
#include "include/solve-nqueen.h" 
//#include "include/verify-solution.h"

void printSolution(char (*board)[N]);

void testing(char (*board)[N]);

int main (void)
{
	char board[N][N];
	bool valid_solution = false;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			board[i][j] = EMPTY_CHAR;

#if TESTING == 0
	printf("~ Calculating N Queen for N = %i ~\n\n", N);

	clock_t begin = clock();
	valid_solution = solveNqueen(board, 0);
	clock_t end = clock();

	valid_solution ? printSolution(board) : printf("Solution for [%i x %i] does not exists\n", N, N);
	
	printf("\n> Execution Time...: %f [s]\n", (double)(end - begin)/CLOCKS_PER_SEC);
	 //printf("> Verifier Returned: %i\n\n", verifyNqueenSolution(board));
#else 
	testing(board); 
	printSolution(board);
#endif

	return 0;
}

 // FINDING OPTIMIZED ALGORITHM FOR RIGHT TO LEFT

void testing(char (*board)[N])
{
	int x = N - 20; 
	int y = N - 10; 

	board[x][y] = '@';

	for (int i = 0; i < N; i++)
	{
		int oper_l = i;
		int oper_r = i - y + x; 

		if (oper_l >= 0 && oper_l < y && oper_r >= 0 && oper_r < y)
			board[oper_l][oper_r] = 't';
	}

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
