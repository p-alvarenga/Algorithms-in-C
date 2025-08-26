<h1 align="center">Rat in a maze</h1>

This Algorithm uses mainly backtracking to solve and its one of the easiest backtracking programns to do.
It is not a scalable program, therefore, it does not have performance analysis.

> [!IMPORTANT]
> To execute your own custom maze, you need to change the following code snippets in order to match your maze

<br>

#### To Change `char maze[N][M]` size in file `maze-config/`:

```c
#define N 10
#define M 20 
```

#### To Change describe characters in file `maze-config/`: 

```c
#define START_CHAR 'S'
#define END_CHAR   'E'
#define EMPTY_CHAR ' '
#define BLOCK_CHAR '#'
```

And then, change the **maze itself**. It is declared inside the `main()`. feel free to use the functions as you like `:)`

<br/>

<h3 align="center">Explaining the <code>struct-pos.h</code> file</h3>

To make the functions more clear and readable, I defined a simple structure:

```cxx
typedef struct
{
    int x, y;	
} Pos;
```

Inside the file there is two functions: `bool verifyPosRange(int pos_x, int pos_y)` and `void defineStartEnd(char maze[N][M], struct Pos *start_pos, struct Pos *end_pos)`. The first function is simple, it only verifies if: 

<p align="center"> $pos_x ∈ [0, N[$ and $pos_y ∈ [0, M[$</p>

The second function is as simple as the first, it only finds the end position and the start position based on the pre-defined characters

<br/>

<h3 align="center">Explaining the <code>move-rat.h</code> file</h3>

<p>The code on <code>move-rat.h</code>code> is simple, the main idea is to make it easier to manage the different directions that the rat can move, using a clockwise system, starting on 0, as follows: </p>

```c
#define	UP    0
#define	RIGHT 1
#define	DOWN  2
#define	LEFT  3
```

- The `check_square_on_dir(char (*)[M], Pos, int)` verifies if rat can move to `maze[x][y]`;
- The function uses the `bool valid_range(int, int)`, defined in `pos.h` to verify if `x` or `y` is out of bounds

- The other function, `bool move_rat(char (*)[M], Pos, int)` takes direction (as `int`) and moves the rat (`Pos`) using the clockwise system.
