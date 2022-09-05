
#include	"matrix_o.h"

void	print_matrix(t_matrix_obj *matrix)
{
	unsigned x;
	unsigned y;

	printf("rows = %u \n",matrix->rows);
	printf("columns = %u \n\n",matrix->columns);

	x = 0;
	y = 0;
	while (y < matrix->columns)
	{
		while(x < matrix->rows)
		{
			printf("| %3i ",matrix->matrix[y][x]);
			x++;
		}
		x = 0;
		printf("|\n\n");
		y++;
	}
}

// set every value inside the matrix to 0 // will be change later to a value form the parameter
void 	null_matrix(struct s_matrix_obj *matrix)
{
	unsigned x;
	unsigned y;

	x = 0;
	y = 0;
	while (y < matrix->columns)
	{
		while(x < matrix->rows)
		{
				matrix->matrix[y][x] = 0;
			x++;
		}
		x = 0;
		y++;
	}

}
