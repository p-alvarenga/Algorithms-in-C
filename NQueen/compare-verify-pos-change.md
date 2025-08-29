Testing speed of: 

> ```c 
>	for (int i = 0; i < N; i++)
>	{
>		if (check_range(i - (x - y), 0, y))
>		{
>			if (board[i][i - (x - y)] == QUEEN_CHAR)
>				return false;
>		}
>		if (check_range(i - (NMAX - y - x), y, NMAX))
>		{
>			if (board[NMAX - i][i - (NMAX - y - x)] == QUEEN_CHAR)
>				return false;
>		}
>	}
> ```

versus: 

> ```c 
>	for (int i = 0; i < N; i++) 
>	{
>		if (check_range(i - (x - y), 0, y))
>		{
>			if (board[i][i - (x - y)] == QUEEN_CHAR)
>				return false;
>		}
>	}
>
> 	for (int i = 0; i < N; i++)
> 	{
>		if (check_range(i - (NMAX - y - x), y, NMAX))
>		{
>			if (board[NMAX - i][i - (NMAX - y - x)] == QUEEN_CHAR)
>				return false;
>		}
> 	}
> ```

| N | ALG 1 LOOP | ALG 2 LOOP |
|:-:|:----------:|:----------:|
|45 | 0.6956     | 0.7620     |
|46 | 0.7887     | 0.7195     |
|55 | 7.8334     | 9.5794     |
|56 | 13.5730    | 17.1331    |
|60 | 75.0156    | 86.7043    |


> [!NOTE]
> Obviously, it's cheaper to iterate only one time from 0 to N than two times; The hypothesis was: "is it more probable that the program will catch a `QUEEN_CHAR` in the first loop than in the second?"



