#include <stdio.h>
#include <stdbool.h>

#define N 10
#define M 20

#define START_CHAR 'S'
#define END_CHAR 'E'
#define EMPTY_CHAR ' '
#define BLOCK_CHAR '#'

inline bool verifyPosRange(int pos_x, int pos_y);

#include "./struct-pos.h"
#include "./move-rat.h"

bool solveMaze(char maze[N][M], struct Pos rat, struct Pos end_pos);
void printMaze(char maze[N][M]);

int main (void)
{
	struct Pos init_rat;
	struct Pos end_pos;

	char maze[N][M] = 
	{
    	{'S', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    	{'#', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    	{'#', ' ', '#', ' ', '#', '#', '#', '#', '#', '#', ' ', '#', '#', '#', ' ', '#', '#', '#', ' ', '#'},
    	{'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#'},
    	{'#', '#', '#', ' ', '#', ' ', '#', '#', ' ', '#', ' ', '#', '#', '#', '#', '#', ' ', '#', ' ', '#'},
    	{'#', 'E', '#', ' ', '#', ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', '#'},
    	{'#', ' ', '#', '#', '#', '#', ' ', '#', ' ', '#', '#', '#', '#', '#', ' ', '#', ' ', '#', ' ', '#'},
    	{'#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', '#'},
    	{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', ' ', '#', '#', '#', '#', '#', ' ', '#'},
    	{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'}
	};

	defineStartEnd(maze, &init_rat, &end_pos);
	solveMaze(maze, init_rat, end_pos);
	printMaze(maze);

	return 0;
}

bool solveMaze(char maze[N][M], struct Pos rat, struct Pos end_pos)
{
	struct Pos next_step;

	if (rat.x == end_pos.x && rat.y == end_pos.y)
		return true;

	for (int dir = 0; dir <= 3; dir++)
	{
		if (checkSquareOnDirection(maze, rat, dir))
		{
			next_step = rat;

			moveRat(maze, &next_step, dir);

			maze[rat.x][rat.y] = '.';

			if (solveMaze(maze, next_step, end_pos))
			{
				return true;
			}
			else 
			{
				maze[rat.x][rat.y] = ' ';
			}
		}
	}

	return false;
}


void printMaze(char maze[N][M]) 
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			printf("%c ", maze[i][j]);
		}

		printf("\n");
	}

	return;
}

/**
 *	0 - up
 * 	1 - right
 *	2 - down
 *	3 - left
 *
 *	(clockwise, from 0 to 3);
**/
