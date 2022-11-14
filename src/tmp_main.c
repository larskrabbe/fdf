/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:30:24 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/11/06 19:56:27 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/*
	draws line betwenn cords
*/
void	draw_on_screen(t_map *map, mlx_image_t *img)
{
	unsigned int	c_y;
	unsigned int	c_x;

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

/*
	uses f vector_transform on each cordinate// maybe change it to funktion pointer
*/
void	map_to_screen(t_all_structs *a_s)
{
	unsigned int	cur_x;
	unsigned int	cur_y;

	cur_x = 0;
	cur_y = 0;
	while (cur_y < a_s->map->max_y)
	{
		while (cur_x < a_s->map->max_x)
		{
			vector_transform(a_s, cur_x, cur_y);
			cur_x++;
		}
		cur_x = 0;
		cur_y++;
	}
}

/*
	Creat the main Struct that contain all other structs and frees them at the end
	small input protection
	gives the main struct to the mlx_main
*/
int	main(int argc, char **argv)
{
	mlx_t			mlx;
	t_map			map;
	t_input			input;
	t_all_structs	a_s;

	if (argc <= 1)
		return (0);
	a_s.mlx = &mlx;
	a_s.input = default_input(&input);
	a_s.map = convert_map(argv[1], &map);
	a_s.mtx_s = matrix_setup(NULL);
	a_s.mtx_x = matrix_setup(NULL);
	a_s.mtx_y = matrix_setup(NULL);
	a_s.mtx_z = matrix_setup(NULL);
	a_s.mtx_p = matrix_setup(NULL);
	mlx_main(&a_s);
	free_before_end(&a_s);
	return (0);
}
