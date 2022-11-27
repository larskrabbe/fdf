/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_getter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe < lkrabbe@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:37:40 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/11/26 14:22:16 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/fdf.h"

double	get_single_value(struct s_matrix_obj *matrix, \
unsigned int column, unsigned int row)
{
	return (matrix->matrix[column][row]);
}

//returns a allocated and copied array  of target row
double	*get_single_row(struct s_matrix_obj *matrix, unsigned int t_row)
{
	double			*copy;
	unsigned int	i;

	i = 0;
	copy = malloc(sizeof(double *) * (matrix->rows + 1));
	if (copy == NULL)
	{
		ft_printf("allocation failed for get row");
		return (NULL);
	}
	while (i <= matrix->columns)
	{
		copy[i] = matrix->matrix[t_row][i];
		i++;
	}
	return (copy);
}

//returns a allocated and copied array  of target row
double	*get_single_column(struct s_matrix_obj *matrix, unsigned int t_column)
{
	double			*copy;
	unsigned int	i;

	i = 0;
	copy = malloc(sizeof(double *) * (matrix->columns + 1));
	if (copy == NULL)
	{
		ft_printf("allocation failed for get column");
		return (NULL);
	}
	while (i <= matrix->rows)
	{
		copy[i] = matrix->matrix[i][t_column];
		i++;
	}
	return (copy);
}

//returns a allocated copy of the matrix
double	**get_matrix_copy(struct s_matrix_obj *matrix)
{
	double			**copy;
	unsigned int	i;

	i = 0;
	copy = malloc(sizeof(double *) * (matrix->columns + 1));
	if (copy == NULL)
	{
		ft_printf("allocation failed for copy matrix");
		return (NULL);
	}
	while (matrix->columns <= i)
	{
		copy[i] = get_single_row(matrix, i);
		if (copy[i] == NULL)
		{
			ft_printf("allocation failed for copy matrix");
			return (free_arrays(copy, i));
		}
		i++;
	}
	return (copy);
}
