/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe < lkrabbe@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:36:46 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/08/31 17:00:53 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/fdf.h"

void	print_map(t_map *map)
{
	unsigned	 x;
	unsigned	 y;

	x = 0;
	y = 0;
	ft_printf("\n");
	ft_printf("Map size\n");
	ft_printf("x = %i\n",map->max_x);
	ft_printf("y = %i\n",map->max_y);
	ft_printf("\n");
	while(map->max_y > y)
	{
		while (map->max_x > x)
		{
			ft_printf("%4i",map->position[y][x]->cords[2]);
			x++;
		}
			ft_printf("\n");
		x = 0;
		y++;
	}
}

void	print_cords(t_map *map)
{
	unsigned	 x;
	unsigned	 y;

	x = 0;
	y = 0;
	ft_printf("\n");
	ft_printf("Map size\n");
	ft_printf("x = %i\n",map->max_x);
	ft_printf("y = %i\n",map->max_y);
	ft_printf("\n");
	while(map->max_y > y)
	{
		while (map->max_x > x)
		{
			print_vector(map->position[y][x]->cords,3);
			ft_printf("\n");
			x++;
		}
		x = 0;
		y++;
	}
}

void	print_vector(int *vector,int n)
{
	int	i;
	
	i = 0;
	while(n > i)
	{
		ft_printf("[%3i] ",vector[i]);
		i++;
	}
}