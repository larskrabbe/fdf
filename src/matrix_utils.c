/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe < lkrabbe@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 19:58:21 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/11/26 14:23:31 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/fdf.h"

void	print_matrix(t_matrix_obj *matrix)
{
	unsigned int	x;
	unsigned int	y;

	ft_printf("rows = %u \n", matrix->rows);
	ft_printf("columns = %u \n\n", matrix->columns);
	x = 0;
	y = 0;
	while (y < matrix->columns)
	{
		while (x < matrix->rows)
		{
			ft_printf("| %3f ", matrix->matrix[y][x]);
			x++;
		}
		x = 0;
		ft_printf("|\n\n");
		y++;
	}
}

void	null_matrix(struct s_matrix_obj *matrix)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	y = 0;
	while (y < matrix->columns)
	{
		while (x < matrix->rows)
		{		
			if (x == y)
				matrix->matrix[y][x] = 1;
			else
				matrix->matrix[y][x] = 0;
			x++;
		}
		x = 0;
		y++;
	}
}
