#ifndef STRUCT_POS_H
#define STRUCT_POS_H

struct Pos 
{
	int x, y;	
};


inline bool verifyPosRange(int pos_x, int pos_y)
{	
	if ((pos_x < N && pos_y < M) && (pos_x >= 0 && pos_y >= 0))
	{
		return true;
	}

	return false;
}	

void defineStartEnd(char maze[N][M], struct Pos *start_pos, struct Pos *end_pos)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (maze[i][j] == START_CHAR)
			{
				start_pos->x = i;
				start_pos->y = j;
			}
			else if (maze[i][j] == END_CHAR)
			{
				end_pos->x = i;
				end_pos->y = j;
			}
		}
	}

	return;
}

#endif