
#include	"matrix_o.h"

// change a single value of the matrix
void	set_sinlge_value(struct s_matrix_obj *matrix, unsigned row,unsigned column,int value)
{
	if (row >= matrix->rows || column >= matrix->columns)
		{
			ft_printf("Try to excess outside scope || target => row %u , column %u",row , column);
			exit(EXIT_FAILURE);
		}	
	matrix->matrix[column][row] = value;
}

//change the target row to the value of the array
void	set_whole_row(struct s_matrix_obj *matrix, int *new_values, unsigned t_row)
{
	unsigned	i;

	i = 0;
	while(i <= matrix->rows )
	{
		matrix->matrix[t_row][i] = new_values[i];
		i++;
	}	
}

//change the target row to the value of the array
void	set_whole_coloumn(struct s_matrix_obj *matrix, int *new_values, unsigned t_column)
{
	unsigned	i;

	i = 0;
	while(i <= matrix->rows )
	{
		matrix->matrix[i][t_column] = new_values[i];
		i++;
	}	
}
