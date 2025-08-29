#include "../include/cell.h"

Cell next_empty_cell(short (*sud)[N], Cell cur)
{
	static Cell cell;

	cell.x = 0;
	cell.y = 0;

	for (int x = cur.x; x < N; x++)
	{
		for (int y = 0 ; y < N; y++)
		{
			if (sud[x][y] == 0 && y != cur.y)
			{
				cell.x = x;
				cell.y = y;
				
				return cell;
			}
		}
	}

	return cell;
}
