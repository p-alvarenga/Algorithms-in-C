#ifndef SOLVE_NQUEEN__H__
#define SOLVE_NQUEEN__H__

#include <stdbool.h>
#include "config.h"

static inline __attribute__((always_inline)) bool check_range(int n, int min, int max) 
{ 
	return n >= min && n <= max; 
}

bool verify_pos_above(char (*board)[N], int x, int y);
bool verify_pos_generic(char (*board)[N], int x, int y); // write it

bool solve_nqueen(char (*board)[N], int queen);

#endif
