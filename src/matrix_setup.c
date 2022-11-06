/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 19:58:43 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/11/06 19:03:46 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/fdf.h"

//create the matrix(double [][])
double	**create_matrix(struct s_matrix_obj *matrix, unsigned int rows, \
unsigned int columns)
{
	unsigned int	cur_column;

	if (rows == 0 || columns == 0)
	{
		perror("ERROR Rows or Columns equal 0");
		ft_putstr_fd("hello", 2);
		exit(0);
	}
	matrix->rows = rows;
	matrix->columns = columns;
	cur_column = 0;
	matrix->matrix = malloc(sizeof(int **) * (columns + 1));
	if (matrix->matrix == NULL)
		return (NULL);
	while (cur_column < columns)
	{
		matrix->matrix[cur_column] = malloc(sizeof(int *) * (rows + 1));
		if (matrix->matrix[cur_column] == NULL)
			return (free_arrays(matrix->matrix, columns));
		cur_column++;
	}
	matrix->f_set_to_null(matrix);
	return (matrix->matrix);
}

void	*free_arrays(double **ptr, unsigned int n)
{
	while (n > 0)
	{
		n--;
		free (ptr[n]);
	}
	free(ptr);
	return (NULL);
}

// frees the whole matrix 
void	delete_matrix(t_matrix_obj *matrix)
{
	free_arrays(matrix->matrix, matrix->columns);
	matrix->columns = 0;
	matrix->rows = 0;
}

//Constructor for my 'Class'
void	construct_matrix_obj(t_matrix_obj *matrix)
{
	matrix->f_create = &create_matrix;
	matrix->f_print = &print_matrix;
	matrix->f_delete_matrix = &delete_matrix;
	matrix->f_set_to_null = &null_matrix;
	matrix->f_set_single = &set_sinlge_value;
	matrix->f_set_row = &set_whole_row;
	matrix->f_set_column = &set_whole_coloumn;
	matrix->f_get_single = &get_single_value;
	matrix->f_get_row = &get_single_row;
	matrix->f_get_column = &get_single_column;
}
