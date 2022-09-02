/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 19:32:01 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/09/01 20:58:59 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

//*************************LIBARYS*********************************************

#include	"libft.h"
#include	"MLX42.h"
//#include	"MLX42_Int.h"
#include	"MLX42_Input.h"
#include	<fcntl.h>
#include	"count_stuff.h"
#include	"math.h"
//*************************STRUCTURE*******************************************


/*
		s_points		=>	stores the  information of each cordinate coresponding to the file
	int cords[3]		=>	stors the  x y z cords 								//maybe change in 3 diffrent int , but a array works better for  my matrix solver// lets see for now
	int colour			=>	stors the colour if any given from the map-file 	//maybe need to change the type
*/
typedef struct s_points{
	int	cords[3];
	int	colour;
	int screen[2];
}t_points;

/*
		s_map			=> stores the  information from the file in a struct 
	unsigned int max_x	=> max x size for the map
	unsigned int max_y;	=> max y size for the map
	t_points **position => x * y size array of points 
*/
typedef struct s_map{
	unsigned int max_x;
	unsigned int max_y;	
	t_points ***position;
}t_map;
	
mlx_image_t	*g_img;


//turn the file in 'usefull' dataformat

void	convert_map(char *filename, t_map *map);
void	free_map(t_map *map);
void *create_map(t_map *map, int max_x, int max_y);

//------utiles.c
void	print_map(t_map *map);
void	print_cords(t_map *map);
void	print_vector(int *vector,int n);
void	drawline(t_points *point_a,t_points *point_b, mlx_image_t *img);

void	convert_test(t_map *map,int cur_y, int cur_x);


#endif