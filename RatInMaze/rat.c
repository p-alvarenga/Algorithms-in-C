#include <stdio.h>
#include <stdbool.h>

#include "./maze-config.h"
#include "./pos.h"
#include "./move.h" 

bool solve_maze(char maze[N][M], Pos rat, Pos* end_pos);

void print_maze(char maze[N][M]);
void define_start_end(char maze[N][M], Pos* start, Pos* end);

int main (void)
{
	Pos rat;
	Pos* end;

	//printf("%d", sizeof(Pos*));

	static char maze[N][M] = {
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

	define_start_end(maze, &rat, end);
	solve_maze(maze, rat, end);
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

void define_start_end(char maze[N][M], Pos *start, Pos *end)
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			if (maze[i][j] == START_CHAR)
			{
				start->x = i;
				start->y = j;
			}
			else if (maze[i][j] == END_CHAR)
			{
				end->x = i;
				end->y = j;
			}
		}
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
