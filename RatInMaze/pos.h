#ifndef STRUCT_POS__H__
#define STRUCT_POS__H__

typedef struct 
{
	int x, y;	
} Pos;

bool valid_range(int x, int y)
{	
	return (x < N && y < M) && (x >= 0 && y >= 0);
}	


#endif
