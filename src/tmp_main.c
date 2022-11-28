/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:30:24 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/11/28 14:10:55 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/*
	uses f vector_transform on each cordinate// maybe change it to funktion pointer
*/
void	map_to_screen(t_all_structs *a_s)
{
	int	cur_x;
	int	cur_y;

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
	a_s.map = convert_map(argv[1], &map);
	if (a_s.map == NULL)
		return (0);
	a_s.input = default_input(&input, &a_s);
	a_s.mtx_s = matrix_setup(NULL);
	a_s.mtx_x = matrix_setup(NULL);
	a_s.mtx_y = matrix_setup(NULL);
	a_s.mtx_z = matrix_setup(NULL);
	a_s.mtx_p = matrix_setup(NULL);
	mlx_main(&a_s);
	free_before_end(&a_s);
	return (0);
}
