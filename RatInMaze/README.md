<h1 align="center">Rat in a maze</h1>

This Algorithm uses mainly backtracking to solve and its one of the easiest backtracking programns to do.
It is not a scalable program, therefore, it does not have performance analysis.

> [!IMPORTANT]
> To execute your own custom maze, you need to change the following code snippets in order to match your maze

## Using your own maze 

#### Changing `maze size` in `maze-config.h file` 

```c
// maze-config.h

#define N 10
#define M 20 
```

#### Changing maze characters in file `maze-config.h`

```c
// maze-config.h

#define START_CHAR 'S'
#define END_CHAR   'E'
#define EMPTY_CHAR ' '
#define BLOCK_CHAR '#'
```

And then, change the **maze itself**. It is declared inside the `main()`. feel free to use the functions as you like `:)`

---

## Code explained

#### The `pos.h` file

1. Position is defined as a `struct`, as follows:

```c
typedef struct
{
    int x, y;	
} Pos;
```

2. Inside the file there is two functions: 

```c 
bool valid_range(int, int);
void define_start_end(char (*)[M], Pos*, Pos*);
```
- `valid_range` verifies if a given position is out of bounds; Note: it receives `int, int` as parameters for more flexibility;
- `define_start_end` finds `START_CHAR` and `END_CHAR` in maze; 


#### The `move.h` file

> [!NOTE]
> 
> - The rat moves using a clockwise system, as follows: </p>
>
> ```c
> // maze-config.h file
> 
> #define	UP    0
> #define	RIGHT 1
> #define	DOWN  2
> #define	LEFT  3
> ```

The file defines two functions: 

```c
bool check_square_on_dir(char (*)[M], Pos, int);
Pos move_rat(char (*)[M], Pos, int); 
```


That way, its easier to iterate between directions with

```c
    for (int i = 0; i < 4; i++); // as used in solve_maze function
```

- `check_square_on_dir` verifies if rat can move to a given direction;
- `move_rat` takes direction (as `int`) and moves the rat (`Pos`) using the clockwise system.

> [!IMPORTANT]
>
> The functions does not uses `Pos*` instead of `Pos` because Pos and Pos* occupies the same amount of memory and referencing (`Pos*`) adds a extra layer of operation. 

