/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:36:46 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/11/01 22:57:56 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/fdf.h"

void	print_map(t_map *map)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	y = 0;
	printf("\n");
	printf("Map size\n");
	printf("x = %i\n", map->max_x);
	printf("y = %i\n", map->max_y);
	printf("\n");
	while (map->max_y > y)
	{
		while (map->max_x > x)
		{
			printf("{%4f}", map->position[y][x]->cords[0]);
			x++;
		}
		printf("\n");
		x = 0;
		y++;
	}
}

void	print_screen(t_map *map)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	y = 0;
	printf("\n");
	printf("Map size\n");
	printf("x = %i\n", map->max_x);
	printf("y = %i\n", map->max_y);
	printf("\n");
	while (map->max_y > y)
	{
		while (map->max_x > x)
		{	
			printf("{%4d |", map->position[y][x]->screen[0]);
			printf("%4d", map->position[y][x]->screen[1]);
			printf(" >> %.8x} ", map->position[y][x]->color.color);
			x++;
		}
		printf("\n");
		x = 0;
		y++;
	}
}

void	print_color(t_map *map)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	y = 0;
	printf("\n");
	printf("Map size\n");
	printf("x = %i\n", map->max_x);
	printf("y = %i\n", map->max_y);
	printf("\n");
	while (map->max_y > y)
	{
		while (map->max_x > x)
		{	
			printf("{ %x ", map->position[y][x]->color.color);
			x++;
		}
		printf("\n");
		x = 0;
		y++;
	}
}

void	print_vector(double *vector, int n)
{
	int	i;

	i = 0;
	while (n > i)
	{
		printf("[%3f] ", vector[i]);
		i++;
	}
}

void	print_cords(t_map *map)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	y = 0;
	printf("\n");
	printf("Map size\n");
	printf("x = %i\n", map->max_x);
	printf("y = %i\n", map->max_y);
	printf("\n");
	while (map->max_y > y)
	{
		while (map->max_x > x)
		{
			print_vector(map->position[y][x]->cords, 3);
			printf("\n");
			x++;
		}
		x = 0;
		y++;
	}
}

void	print_data(t_all_structs *a_s)
{
	printf("scale matrix \n");
	a_s->mtx_s->f_print(a_s->mtx_s);
	printf("z rotation matrix \n");
	a_s->mtx_z->f_print(a_s->mtx_z);
	printf("y rotation matrix \n");
	a_s->mtx_y->f_print(a_s->mtx_y);
	printf("x rotation matrix \n");
	a_s->mtx_x->f_print(a_s->mtx_x);
	printf("projection matrix \n");
	a_s->mtx_p->f_print(a_s->mtx_p);
	printf("color per poinr \n");
	printf("screen cords \n");
	print_screen(a_s->map);
}
