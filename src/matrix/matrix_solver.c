
#include	"matrix_o.h"
#include	<stdio.h>

// int	**matrix_multiply(struct s_matrix_obj *matrixa, struct s_matrix_obj *matrixb)
// {
// 	return (NULL);
// }

int	vector_add_up(double *vec_a,double *vec_b,int vec_len)
{
	int add_up;
	int i;

	i = 0;
	add_up = 0;
	while (i < vec_len)
	{
		add_up = add_up + (vec_a[i] * vec_b[i]);
		i++;
	}
	return(add_up);
}

void	matrix_multiply_vector(struct s_matrix_obj *matrix, double *vector, unsigned vec_len, double *result)
{
	unsigned	i;

	//ft_printf("rows -> %i ",matrix->rows);
	if(vec_len < matrix->rows)
	{
		printf("vector has a not a valid size >> rows =>%i vector %i\n",matrix->rows, vec_len);
		return;
	}
	i = 0;
	while (i < matrix->rows)
	{
		//matrix->f_print(matrix);
		result[i] = vector_add_up(matrix->matrix[i],vector,vec_len);
		//printf(">>>>>result {%i}",result[i]);
		i++;
	}
}
