#ifndef STRUCT_CELL_H
#define STRUCT_CELL_H

struct Cell
{
	short x;
	short y;
};

struct Cell getNextEmptyCell(short sudoku[N][N], struct Cell current_cell)
{
	struct Cell cell;

	cell.x = 0;
	cell.y = 0;

	for (short x_ = current_cell.x; x_ < N; x_++)
	{
		for (short y_ = 0 ; y_ < N; y_++)
		{
			if (sudoku[x_][y_] == 0 && y_ != current_cell.y)
			{
				cell.x = x_;
				cell.y = y_;
				
				return cell;
			}
		}
	}

	return cell;
}

#endif