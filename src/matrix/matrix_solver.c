
#include	"matrix_o.h"
#include	<stdio.h>

// int	**matrix_multiply(struct s_matrix_obj *matrixa, struct s_matrix_obj *matrixb)
// {
// 	return (NULL);
// }

int	vector_add_up(int *vec_a,int *vec_b,int vec_len)
{
	int add_up;
	int i;

	i = 0;
	add_up = 0;
	while (i < vec_len)
	{
		//printf("%i = %i + %i * %i \n\n",add_up + (vec_a[i] * vec_b[i]),add_up,vec_a[i],vec_b[i]);
		// printf("Here >>>%d\n",add_up);
		// printf("vecta: %d\n", vec_a[i]);
		// printf("vectb: %d\n", vec_b[i]);
		// printf("A*B: %d\n", (vec_a[i] * vec_b[i]));
		add_up = add_up + (vec_a[i] * vec_b[i]);
		// printf("Here >>>%d\n",add_up);
		i++;
	}
	return(add_up);
}

void	matrix_multiply_vector(struct s_matrix_obj *matrix, int *vector, unsigned vec_len, int *result)
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
