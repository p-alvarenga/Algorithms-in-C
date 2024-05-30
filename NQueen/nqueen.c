#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define N 45
#define N_MAX (N - 1)
#define QUEEN_CHAR 'Q'
#define EMPTY_CHAR '.'

bool solveNqueen(char board[N][N], int i_line);
bool verifyPosition(char board[N][N], int x, int y); 
int verifyNqueenSolution(char board[N][N]);

#include "./solve-nqueen.h" // def of selveNqueen() and verifyPosition()
#include "./verify_solution.h" // def of verifyNqueenSolution

void printSolution(char board[N][N]);

int main (void)
{
	char board[N][N];
	bool solution_exists = false;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			board[i][j] = EMPTY_CHAR;
		}		
	}

	printf("Calculating N Queen for N = %i...\n\n", N);

	clock_t begin = clock();

	solution_exists = solveNqueen(board, 0);

	clock_t end = clock();


	solution_exists ? printSolution(board) : printf("Solution for [%i x %i] does not exists\n", N, N);
	printf("\n> Execution Time...: %f [s]\n", (double)(end - begin)/CLOCKS_PER_SEC);

	printf("> Verifier Returned: %i\n\n", verifyNqueenSolution(board));

	return 0;
}

void printSolution(char board[N][N])
{
	printf(" Solution for [%i x %i] board ", N, N);

	printf("\n");

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%c ", board[i][j]);
		}
	
		printf("\n");
	}

	return; 
}