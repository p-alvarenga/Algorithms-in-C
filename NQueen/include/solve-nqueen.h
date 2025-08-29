#ifndef SOLVE_NQUEEN__H__
#define SOLVE_NQUEEN__H__

#include <stdbool.h>
#include "config.h"

bool verifyPosition(char (*board)[N], int x, int y);
bool solveNqueen(char (*board)[N], int queen);

#endif
