<h1 align="center">Rat in a maze</h1>

This Algorithm uses mainly backtracking to solve and its one of the easiest backtracking programns to do.
It is not a scalable program, therefore, it does not have performance analysis.

To execute your own maze, you need to change a bit of the code:

```
4 | #define N ?
5 | #define M ?
```

the maze is declared such as char maze[N][M], so, it depends on the maze you want to solve

You can change the characters on the:

```
 7 | #define START_CHAR ?
 8 | #define END_CHAR ?
 9 | #define EMPTY_CHAR ?
10 | #define BLOCK_CHAR ?
```

Just replace the '?' with the respective character. By default, the constants are:

```
 7| #define START_CHAR 'S'
 8| #define END_CHAR 'E'
 9| #define EMPTY_CHAR ' '
10| #define BLOCK_CHAR '#'
```

And then, change the maze itself, it is declared inside the main function, but feel free to use the functions as you like.

<br/>
<hr>
<h3 align="center">Explaining the <code>struct-pos.h</code> file</h3>

To make the functions more clear and readable, I defined a simple structure:

```
struct Pos 
{
    int x, y;	
};
```

Therefore, I do not need to pass the int ```pos_x``` and int ```pos_y``` to the function, I only pass the structure itself.

Inside the file, there is two functions: ```bool verifyPosRange(int pos_x, int pos_y)``` and ```void defineStartEnd(char maze[N][M], struct Pos *start_pos, struct Pos *end_pos)```. The first function is simple, it only verifies if: 

<p align="center"> $pos_x ∈ [0, N[$ and $pos_y ∈ [0, M[$</p>

The second function is as simple as the first, it only finds the end position and the start position based on the pre-defined characters

<h3 align="center">Explaining the <code>move-rat.h</code> file</h3>

<p>The code on <code>move-rat.h</code>code> is simple, the main idea is to make it easier to manage the different directions that the rat can move, using a clockwise system, starting on 0, as follows: </p>

```
4 | #define	UP    0
5 | #define	RIGHT 1
6 | #define	DOWN  2
7 | #define	LEFT  3
```

• The <code>checkSquareOnDirection(char maze[N][M], struct Pos pos, int direction)</code> function just verify if, given the rat position <code>struct Pos po</code>, the rat can move to ```int direction```.

• The function uses the <code>bool verifyPosRange(int pos_x, int pos_y)</code>, defined in <code>struct-pos.h</code>, to verify if the given position valid and if the rat <b>can</b> move to that direction, returning <code>true</code> if it can and <code>false</code> if not.

• The other function, <code>bool moveRat(char maze[N][M], struct Pos *rat, int direction)</code> get a pointer to the position of the rat, <code>struct Pos *rat</code> and actually moves it to the direction (if is possible)
