#ifndef STRUCT_CELL_H
#define STRUCT_CELL_H

#ifndef N
	#define N 9 
#endif 

typedef struct
{
	short x;
	short y;
} Cell;

Cell next_empty_cell(short (*sud)[N], Cell cur);
#endif
