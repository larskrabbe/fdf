/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe < lkrabbe@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 19:31:18 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/11/26 17:39:03 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/fdf.h"

/*
	takes the information of a string and allocate 
	and stores the information inside of s_points struct
*/
int	a_to_points(t_map *map, unsigned int cur_x, \
char *str, unsigned int cur_y)
{
	char	**info;

	map->position[cur_y][cur_x] = ft_calloc(sizeof(t_points), 1);
	if (map->position[cur_y][cur_x] == NULL)
		return (-1);
	info = ft_split(str, ',');
	if (info == NULL)
		return (-1);
	map->position[cur_y][cur_x]->cords[0] = convert_cords(cur_x, map->max_x);
	map->position[cur_y][cur_x]->cords[1] = convert_cords(cur_y, map->max_y);
	map->position[cur_y][cur_x]->cords[2] = ft_atoi(info[0]);
	map->position[cur_y][cur_x]->cords[3] = 1;
	if (info[1] != NULL)
	{
		map->position[cur_y][cur_x]->color.color = my_hextoi(info[1]);
		if (ft_strlen(info[1]) == 8 || info[1][8] == '\n')
			map->position[cur_y][cur_x]->color.color = \
	(map->position[cur_y][cur_x]->color.color << 8) | 0xff;
		free(info[1]);
	}
	else
	{
		map->position[cur_y][cur_x]->color.color = 0xffffffff;
		map->position[cur_y][cur_x]->color.color -=(map->position[cur_y][cur_x]->cords[2]);
	}
	free(info[0]);
	free(info);
	return (0);
}

/*
	takes the information of a string and stores in the map
*/
int	a_to_map(char *gnl_ptr, t_map *map, unsigned int cur_y)
{
	char	**split_str;
	int		cur_x;

	cur_x = 0;
	if (gnl_ptr == NULL || map == NULL)
		return (-1);
	split_str = ft_split(gnl_ptr, ' ');
	if (split_str == NULL)
		return (-1);
	while (split_str[cur_x] != NULL && cur_x < map->max_x)
	{
		if (a_to_points(map, cur_x, split_str[cur_x], cur_y) != 0)
			return (-1);
		cur_x++;
	}
	free_str_array(split_str);
	if (map->max_x != (cur_x))
		ft_printf("ERROR map size is not uniform \
		{ cur_x = %i max_x = %i cur_y = %i max_y = %i}\n" \
		, cur_x, map->max_x, cur_y, map->max_y);
	return (0);
}

/*
	allocate the whole structur for storing the data of the fdf.file
*/
void	*create_map(t_map *map, int max_x, int max_y)
{
	int	y;

	y = 0;
	map->position = ft_calloc(sizeof(t_points *), (max_y + 1));
	if (map->position == NULL)
		return (NULL);
	while (y <= max_y)
	{
		map->position[y] = ft_calloc(sizeof(t_points), (max_x + 1));
		if (map->position[y] == NULL)
		{
			free_map(map, 0, y);
			return (NULL);
		}
		y++;
	}
	return (NULL);
}

/*
	read a file and stores the information in the map struct
	can also be massivly improve by changing get next 
	line(in a way where we dont malloc the string at all 
	and importing the data dirctly in the structes) 
	and so reducing systemcalls for not using after  get_next_line ft_split
*/
void	*read_map(t_map *map, int fd, char *gnl_ptr)
{
	unsigned int	y;

	y = 0;
	while (gnl_ptr != NULL)
	{
		if (a_to_map(gnl_ptr, map, y) != 0)
			return (NULL);
		free(gnl_ptr);
		gnl_ptr = get_next_line(fd);
		y++;
	}
	return (0);
}

/*
	convets the file into cordinate inside a struct
*/
t_map	*convert_map(char *filename, t_map *map)
{
	char	*gnl_ptr;
	int		fd;

	gnl_ptr = NULL;
	map->max_y = counts_lines_from_file(filename);
	if (map->max_y <= 0)
		return (NULL);
	fd = open(filename, O_RDONLY);
	gnl_ptr = get_next_line(fd);
	map->max_x = count_words_in_str(gnl_ptr);
	create_map(map, map->max_x, map->max_y);
	read_map(map, fd, gnl_ptr);
	return (map);
}
