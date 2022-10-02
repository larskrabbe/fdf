/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:36:46 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/09/21 13:57:42 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/fdf.h"

void	print_map(t_map *map)
{
	unsigned	 x;
	unsigned	 y;

	x = 0;
	y = 0;
	printf("\n");
	printf("Map size\n");
	printf("x = %i\n",map->max_x);
	printf("y = %i\n",map->max_y);
	printf("\n");
	while(map->max_y > y)
	{
		while (map->max_x > x)
		{
			printf("{%4f}",map->position[y][x]->cords[0]);
			x++;
		}
			printf("\n");
		x = 0;
		y++;
	}
}

void	print_screen(t_map *map)
{
	unsigned	 x;
	unsigned	 y;

	x = 0;
	y = 0;
	printf("\n");
	printf("Map size\n");
	printf("x = %i\n",map->max_x);
	printf("y = %i\n",map->max_y);
	printf("\n");
	while(map->max_y > y)
	{
		while (map->max_x > x)
		{	
			printf("{%4d |",map->position[y][x]->screen[0]);
			printf("%4d}",map->position[y][x]->screen[1]);
			//printf("%4f}",map->position[y][x]->screen[2]);
			x++;
		}
			printf("\n");
		x = 0;
		y++;
	}
}


void	print_vector(double *vector,int n)
{
	int	i;
	
	i = 0;
	while(n > i)
	{
		printf("[%3f] ",vector[i]);
		i++;
	}
}
void	print_cords(t_map *map)
{
	unsigned	 x;
	unsigned	 y;

	x = 0;
	y = 0;
	printf("\n");
	printf("Map size\n");
	printf("x = %i\n",map->max_x);
	printf("y = %i\n",map->max_y);
	printf("\n");
	while(map->max_y > y)
	{
		while (map->max_x > x)
		{
			print_vector(map->position[y][x]->cords,3);
			printf("\n");
			x++;
		}
		x = 0;
		y++;
	}
}