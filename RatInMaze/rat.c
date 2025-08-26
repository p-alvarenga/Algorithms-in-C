#include <stdio.h>
#include <stdbool.h>

#define N 10
#define M 20

#define START_CHAR 'S'
#define END_CHAR   'E'
#define EMPTY_CHAR ' '
#define BLOCK_CHAR '#'

#include "./pos.h"
#include "./move.h"

bool solve_maze(char maze[N][M], struct Pos rat, struct Pos end_pos);
void print_maze(char maze[N][M]);

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
	solve_maze(maze, init_rat, end_pos);
	print_maze(maze);

	return 0;
}

bool solve_maze(char maze[N][M], struct Pos rat, struct Pos end_pos)
{
	struct Pos next_step;

	if (rat.x == end_pos.x && rat.y == end_pos.y)
		return true;

	for (int dir = 0; dir <= 3; dir++)
	{
		if (checkSquareOnDirection(maze, rat, dir))
		{
			next_step = rat;

			move_rat(maze, &next_step, dir);

			maze[rat.x][rat.y] = '.';

			if (solve_maze(maze, next_step, end_pos))
			{
				return true;
			}
			else maze[rat.x][rat.y] = ' ';
		}
	}

	return false;
}


void print_maze(char maze[N][M]) 
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			printf("%c ", maze[i][j]);

		printf("\n");
	}
}

/**
 *	0 - up
 * 	1 - right
 *	2 - down
 *	3 - left
 *
 *	(clockwise, from 0 to 3);
**/
