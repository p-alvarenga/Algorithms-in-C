<h1 align="center">Sudoku Solver</h1>

> This Sudoku Solver was one of my hardest challenges when I was 13y, so, I decided to remake it

<br/>

## Code Explain

<hr>

The Solver has 2 function/struct define files and a <code>data.h</code> file, which has 30+ sudoku puzzles to test the algorithm

### <code>struct-cell.h</code>:

The <code>struct-cell</code> is the definition of <code>struct Cell</code>, which, same as <code>struct Pos</code> in <code>RatInMaze/struct-pos.h</code>, has the coordinates: 

```
struct Cell
{
  int x, y;  
}
```

and another function on the same file: <code>struct Cell getNextEmptyCell(short sudoku[N][N], struct Cell current_cell)</code> which, based on the sudoku (passed as argument) and the current analysing cell, 
will return the next empty cell (as <code>struct Cell</code>), from left to right and from up to bottom (reading system). This function was designed to make it easier to understand the iteration on the backtracking
function.

### <code>generic-components.h</code>:

The <code>generic-components.h</code> has three function definitions, that verifies the 
