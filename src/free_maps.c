/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 18:45:01 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/11/05 18:51:12 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/fdf.h"

void	free_str_array(char **strings)
{
	int	i;

	i = 0;
	while (strings[i] != NULL)
	{
		free(strings[i]);
		i++;
	}
	free(strings);
}

/*
	free the whole map that was allocated
	if the map was correctly allocated  max_x 
	and max_y is the same as the max value inside of the map struct
*/
void	free_map(t_map *map, int max_x, int max_y)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (max_y >= y)
	{
		while (max_x >= x)
		{
			free(map->position[y][x]);
			x++;
		}
		free(map->position[y]);
		y++;
		x = 0;
	}
	free(map->position);
}
