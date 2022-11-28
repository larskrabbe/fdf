/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_order.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:59:27 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/11/28 14:00:34 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/fdf.h"

static void	left_up(t_map *map, mlx_image_t *img)
{
	int	c_y;
	int	c_x;

	c_y = map->max_y -1;
	c_x = map->max_x -1;
	while (0 <= c_y)
	{
		while (0 <= c_x)
		{
			if (c_x > 0)
				drawline(map->position[c_y][c_x], \
				map->position[c_y][c_x - 1], img);
			if (c_y > 0)
				drawline(map->position[c_y][c_x], \
				map->position[c_y - 1][c_x], img);
			c_x--;
		}
		c_x = map->max_x -1;
		c_y--;
	}
}

static void	right_down(t_map *map, mlx_image_t *img)
{
	int	c_y;
	int	c_x;

	c_y = 0;
	c_x = 0;
	while (map->max_y > c_y)
	{
		while (map->max_x > c_x)
		{
			if (c_x + 1 < map->max_x)
				drawline(map->position[c_y][c_x], \
				map->position[c_y][c_x + 1], img);
			if (c_y + 1 < map->max_y)
				drawline(map->position[c_y][c_x], \
				map->position[c_y + 1][c_x], img);
			c_x++;
		}
		c_x = 0;
		c_y++;
	}
}

static void	right_up(t_map *map, mlx_image_t *img)
{
	int	c_y;
	int	c_x;

	c_y = map->max_y -1;
	c_x = 0;
	while (0 <= c_y)
	{
		while (map->max_x > c_x)
		{
			if (c_x + 1 < map->max_x)
				drawline(map->position[c_y][c_x], \
				map->position[c_y][c_x + 1], img);
			if (c_y > 0)
				drawline(map->position[c_y][c_x], \
				map->position[c_y - 1][c_x], img);
			c_x++;
		}
		c_x = 0;
		c_y--;
	}
}

/*
	draws line betwenn cords
*/
static void	left_down(t_map *map, mlx_image_t *img)
{
	int	c_y;
	int	c_x;

	c_y = 0;
	c_x = map->max_x -1 ;
	while (map->max_y > c_y)
	{
		while (0 <= c_x)
		{
			if (c_x > 0)
				drawline(map->position[c_y][c_x], \
				map->position[c_y][c_x - 1], img);
			if (c_y + 1 < map->max_y)
				drawline(map->position[c_y][c_x], \
				map->position[c_y + 1][c_x], img);
			c_x--;
		}
		c_x = map->max_x - 1;
		c_y++;
	}
}

void	draw_on_screen(t_map *map, mlx_image_t *img)
{
	if (map->position[0][0]->screen[0] > \
	map->position[0][map->max_x - 1]->screen[0])
	{
		if (map->position[0][0]->screen[1] < \
		map->position[map->max_y - 1][0]->screen[1])
			left_down(map, img);
		else
			left_up(map, img);
	}
	else
	{
		if (map->position[0][0]->screen[1] < \
		map->position[map->max_y - 1][0]->screen[1])
			right_down(map, img);
		else
			right_up(map, img);
	}
}
