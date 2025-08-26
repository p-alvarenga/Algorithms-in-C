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

bool solve_maze(char maze[N][M], Pos rat, Pos* end_pos);
void print_maze(char maze[N][M]);

int main (void)
{
	Pos init_rat;
	Pos *end_pos;

	//printf("%d", sizeof(Pos*));

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

	defineStartEnd(maze, &init_rat, end_pos);
	solve_maze(maze, init_rat, end_pos);
	print_maze(maze);

	return 0;
}

bool solve_maze(char maze[N][M], Pos rat, Pos* end)
{
	Pos n_rat;

	if (rat.x == end->x && rat.y == end->y) return true;

	for (int dir = 0; dir < 4; dir++)
	{
		if (check_square_on_dir(maze, rat, dir))
		{
			n_rat = rat;

			n_rat = move_rat(maze, n_rat, dir);
			maze[rat.x][rat.y] = '.';

			if (solve_maze(maze, n_rat, end))
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
