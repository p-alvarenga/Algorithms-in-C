#ifndef STRUCT_POS_H
#define STRUCT_POS_H

typedef struct 
{
	int x, y;	
} Pos;

bool valid_range(int x, int y)
{	
	return (x < N && y < M) && (x >= 0 && y >= 0);
}	

void defineStartEnd(char maze[N][M], Pos *start_pos, Pos *end_pos)
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
}

#endif
