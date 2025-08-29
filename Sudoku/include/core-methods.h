#ifndef GENERIC_COMPONENTS_H
#define GENERIC_COMPONENTS_H

#include <stdbool.h>

#ifndef N
	#define N 9
#endif

bool verify_pos_n(short (*sudoku)[N], short x, short y, short n);
bool is_solved(short (*sudoku)[N]);
bool is_valid_sudoku(short (*sudoku)[N]);

#endif
