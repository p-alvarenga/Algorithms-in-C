<h1 align="center">Sudoku Solver</h1>

<br/>

> This Sudoku Solver was one of my hardest challenges when I was 13, so I decided to remake it.

<h3 align="center">Introducing the Code</h3>

<hr>

The Solver has two function/struct definition files and a `data.h` file, which contains 30+ sudoku puzzles to test the algorithm.

### `struct-cell.h`:

The `struct-cell.h` file defines the `struct Cell`, which, similar to `struct Pos` in `RatInMaze/struct-pos.h`, has the coordinates:

```c
struct Cell
{
  int x, y;
};
```

Additionally, it contains a function:

<code>struct Cell getNextEmptyCell(short sudoku[N][N], struct Cell current_cell);</code>

Based on the sudoku (passed as an argument) and the currently analyzed cell, this function returns the next empty cell (as a <code>struct Cell</code>), from left to right and top to bottom (reading order). This function was designed to make it easier to understand the iteration in the backtracking function.

### `generic-components.h`:

The `generic-components.h` file contains three function definitions:

1. `bool verifyNumberPosition(short sudoku[N][N], short x, short y, short n_)`: As the name implies, verifies if the number $n$ can be placed in $(x, y)$.
2. `bool verifySolved(short sudoku[N][N])`: Verifies if there are **any** zeros in the sudoku. If not, it returns `true` and stops the backtracking.
3. `bool verifySudokuFollowRules(short sudoku[N][N])`: Verifies if the sudoku follows the rules and is valid.

All of these functions return `bool` values, which do not exist by default in the C language. Therefore, in the main file (`sudoku.c`), it was necessary to include the `stdbool.h` library.
