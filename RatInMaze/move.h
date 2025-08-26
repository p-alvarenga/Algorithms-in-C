#ifndef MOVE_RAT_H
#define MOVE_RAT_H

//#define	UP    0
//#define	RIGHT 1
//#define	DOWN  2
//#define	LEFT  3

enum MOVE_POS { UP, RIGHT, DOWN, LEFT }; 

bool check_square_on_dir(char maze[N][M], Pos pos, int dir)
{
	switch (dir)
	{
		case UP:
			if (!valid_range(pos.x - 1, pos.y + 1)) return false; 
			return maze[pos.x - 1][pos.y] == EMPTY_CHAR || maze[pos.x - 1][pos.y] == END_CHAR;	

		case RIGHT: 
			if (!valid_range(pos.x, pos.y + 1)) return false;
			return maze[pos.x][pos.y + 1] == EMPTY_CHAR || maze[pos.x][pos.y + 1] == END_CHAR;	

		case DOWN:
			if (!valid_range(pos.x + 1, pos.y)) return false; 
			return maze[pos.x + 1][pos.y] == EMPTY_CHAR || maze[pos.x + 1][pos.y] == END_CHAR;	
	
		case LEFT: 
			if (!valid_range(pos.x, pos.y - 1)) return false; 
			return maze[pos.x][pos.y - 1] == EMPTY_CHAR || maze[pos.x][pos.y - 1] == END_CHAR;
	}


	return false;
}

Pos move_rat(char maze[N][M], Pos rat, int dir)
{
	switch (dir)
	{
		case UP:
			rat.x--;
			break;

		case RIGHT:
			rat.y++;
			break;

		case DOWN: 
			rat.x++;
			break;

		case LEFT: 
			rat.y--;
			break;
	}

	return rat; 
}


/*
 * if (verify()) {
 *		return maze[on_dir] == empty || maze[o_dir] == EOM; 
 * } else {
 *		return false; 
 * }
 * */


#endif
