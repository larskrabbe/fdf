/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe < lkrabbe@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 19:31:18 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/09/06 10:38:14 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/fdf.h"

/*----------------------------------------------------------------------------*\
|																			   |
|		need to care about freeing in the end								   |
|																			   |
\*----------------------------------------------------------------------------*/

#define EXPENT * 10

// takes the information of a string and allocate and stores the information inside of s_points struct
int	a_to_points(t_map *map,unsigned cur_x, char *str ,unsigned cur_y)
{
	char		**info;

	//ft_printf("\n [%i] [%i]",cur_y,cur_x);
	map->position[cur_y][cur_x] = ft_calloc(sizeof(t_points),1);
	if (map->position[cur_y][cur_x] == NULL)
	{
		ft_printf("\n tmp == NULL");//safe free exit
		return(-1);
	}
	
	info = ft_split(str,',');
	if (info == NULL)
	{
		ft_printf("\n info == NULL");//safe free exit
		return(-1);
	}
	map->position[cur_y][cur_x]->cords[0] = cur_y;//include inline test
	map->position[cur_y][cur_x]->cords[1] = cur_x;//include inline test
	map->position[cur_y][cur_x]->cords[2] = atoi(info[0]);
	map->position[cur_y][cur_x]->cords[3] =	0;
	//ft_printf(" >> %i",	map->position[cur_y][cur_x]->cords[2]);
	if (info[1] != NULL)
	{
		map->position[cur_y][cur_x]->colour = atoi(info[1]);
		free(info[1]);
	}
	free(info[0]);
	free(info);
	return(0);
}

// takes the information of a string and stores in the map
int	a_to_map(char *gnl_ptr,t_map *map, unsigned cur_y)
{
	char		**split_str;
	unsigned	cur_x;

	cur_x = 0;
	if (gnl_ptr == NULL || map == NULL)
		return(-1);
	split_str = ft_split(gnl_ptr,' ');
	if (split_str == NULL)
		return(-1);
	while (split_str[cur_x] != NULL && cur_x < map->max_x)// there should be no need to protect for this (cur_x < map->max_x) case
	{
		if(a_to_points(map, cur_x, split_str[cur_x],cur_y) != 0)
			return(-1);
		cur_x++;

	}
	int	i;
	i = 0;
	while(split_str[i] != NULL)
	{
		free(split_str[i]);
		i++;
	}
	free(split_str);
	if ( map->max_x != (cur_x))
		ft_printf("ERROR map size is not uniform { cur_x = %i max_x = %i cur_y = %i max_x = %i}\n",cur_x,map->max_x, cur_y, map->max_y);// need safe exit
	return(0);
}


void *create_map(t_map *map, int max_x, int max_y)
{
	int	y;

	y = 0;
	map->position = ft_calloc(sizeof(t_points *) , (max_y + 1));
	if (map->position == NULL)
		return(NULL);//safe exit free the rest// look into matrix to  get the free ing funktion
	while (y <= max_y)
	{
		map->position[y] = ft_calloc(sizeof(t_points ), (max_x + 1));
		y++;
	}
	
	return(NULL);
}

// read a file and stores the information in the map struct
// can also be massivly improve by changing get next line(in a way where we dont malloc the string at all 
// and importing the data dirctly in the structes) and so reducing systemcalls for not using after  get_next_line ft_split
void	*read_map(t_map *map, int fd,char *gnl_ptr)
{
	unsigned	y;

	y = 0;
	while (gnl_ptr != NULL)
	{
		if(a_to_map(gnl_ptr, map, y) != 0)
			return(NULL);//error case
		free(gnl_ptr);
		gnl_ptr = get_next_line(fd);
		y++;
	}
	return (0);
}


//convets the file into cordinate inside a struct
void	convert_map(char *filename, t_map *map)
{
	char	*gnl_ptr;
	int		fd;

	gnl_ptr = NULL;
	map->max_y = counts_lines_from_file(filename);
	fd = open(filename,O_RDONLY);
	gnl_ptr = get_next_line(fd);
	map->max_x = count_words_in_str(gnl_ptr,' ');
	create_map(map,map->max_x,map->max_y);
	read_map(map,fd,gnl_ptr);	
}

void	free_map(t_map *map)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	y = 0;
	while(map->max_y >= y)
	{
		while(map->max_x >= x)
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