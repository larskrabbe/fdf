
#include	"matrix_o.h"

// int	**matrix_multiply(struct s_matrix_obj *matrixa, struct s_matrix_obj *matrixb)
// {
// 	return (NULL);
// }

int	vector_add_up(int *vec_a,int *vec_b,unsigned vec_len)
{
	int add_up;
	unsigned i;

	i = 0;
	add_up = 0;
	while (i < vec_len)
	{
		add_up = add_up + (vec_a[i] * vec_b[i]);
		i++;
	}
	return(add_up);
}

int	*matrix_multiply_vector(struct s_matrix_obj *matrix, int *vector, unsigned vec_len)
{
	int			*result;
	unsigned	i;

	if(vec_len != matrix->rows)
	{
		ft_printf("vector has a not a valid size");
		return(NULL);
	}
	i = 0;
	result = malloc(sizeof(matrix->matrix) * (matrix->rows + 1));
	while (i < matrix->rows)
	{
		result[i] = vector_add_up(matrix->matrix[i],vector,vec_len);
		i++;
	}
	return(result);
}
