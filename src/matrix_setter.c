/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_setter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe < lkrabbe@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 19:53:52 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/11/26 14:22:23 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/fdf.h"

// change a single value of the matrix
void	set_sinlge_value(struct s_matrix_obj *matrix, unsigned int row, \
unsigned int column, double value)
{
	if (row >= matrix->rows || column >= matrix->columns)
	{
		ft_printf("Try to excess outside scope || target => row %u , column %u" \
		, row, column);
		exit(EXIT_FAILURE);
	}
	matrix->matrix[column][row] = value;
}

//change the target row to the value of the array
void	set_whole_row(struct s_matrix_obj *matrix, \
double *new_values, unsigned int t_row)
{
	unsigned int	i;

	i = 0;
	while (i <= matrix->rows)
	{
		matrix->matrix[t_row][i] = new_values[i];
		i++;
	}	
}

//change the target row to the value of the array
void	set_whole_coloumn(struct s_matrix_obj *matrix, double *new_values, \
unsigned int t_column)
{
	unsigned int	i;

	i = 0;
	while (i <= matrix->rows)
	{
		matrix->matrix[i][t_column] = new_values[i];
		i++;
	}	
}
