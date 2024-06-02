#ifndef MOVE_RAT_H
#define MOVE_RAT_H

#define	UP 0
#define	RIGHT 1
#define	DOWN 2
#define	LEFT 3

bool moveRat(char maze[N][M], struct Pos *rat, int direction);
bool checkSquareOnDirection(char maze[N][M], struct Pos pos, int direction);
bool verifyPosRange(int pos_x, int pos_y);

bool moveRat(char maze[N][M], struct Pos *rat, int direction)
{
	switch (direction)
	{
		case UP:
			if (checkSquareOnDirection(maze, *rat, direction))
			{
				rat->x--;
				return true;
			}

			break;

		case RIGHT:
			if (checkSquareOnDirection(maze, *rat, direction))
			{
				rat->y++;
				return true;
			}
	
			break;

		case DOWN: 
			if (checkSquareOnDirection(maze, *rat, direction))
			{
				rat->x++;
				return true;
			}

			break;

		case LEFT: 
			if (checkSquareOnDirection(maze, *rat, direction))
			{
				rat->y--;
				return true;
			}

			break;
	}

	return false;
}

bool checkSquareOnDirection(char maze[N][M], struct Pos pos, int direction)
{
	switch (direction)
	{
		case UP:
			return verifyPosRange(pos.x - 1, pos.y) ? maze[pos.x - 1][pos.y] == EMPTY_CHAR || maze[pos.x - 1][pos.y] == END_CHAR : false;

		case RIGHT: 
			return verifyPosRange(pos.x, pos.y + 1) ? maze[pos.x][pos.y + 1] == EMPTY_CHAR || maze[pos.x][pos.y + 1] == END_CHAR : false;

		case DOWN:
			return verifyPosRange(pos.x + 1, pos.y) ? maze[pos.x + 1][pos.y] == EMPTY_CHAR || maze[pos.x + 1][pos.y] == END_CHAR : false;			

		case LEFT: 
			return verifyPosRange(pos.x, pos.y - 1) ? maze[pos.x][pos.y - 1] == EMPTY_CHAR || maze[pos.x][pos.y - 1] == END_CHAR : false;
	}

	return false;
}

#endif