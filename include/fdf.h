/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe < lkrabbe@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 19:32:01 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/09/06 10:39:29 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH 256 * 20
# define HEIGHT 256 * 20

//*************************LIBARYS*********************************************

#include	"libft.h"
#include	"MLX42.h"
//#include	"MLX42_Int.h"
#include	"MLX42_Input.h"
#include	<fcntl.h>
#include	"count_stuff.h"
#include	"math.h"
#include	"matrix_o.h"
//*************************STRUCTURE*******************************************


/*
		s_points		=>	stores the  information of each cordinate coresponding to the file
	int cords[4]		=>	stors the  x y z cords /THE LAST VALUE IS ONLY THERE TO USE A 4 X 4 MATRIX								//maybe change in 3 diffrent int , but a array works better for  my matrix solver// lets see for now
	int colour			=>	stors the colour if any given from the map-file 	//maybe need to change the type
	int screen[4]		=>	stors the cords after translating it through the matrix,the z position shold be irrelevant
*/
typedef struct s_points{
	double	cords[4];
	int	colour;
	double screen[4];
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

typedef struct s_input
{
	int input0;
	int input1;
	int input2;
	int input3;
	int input4;
	int input5;
	int input6;
	int input7;
	int input8;
	int input9;
	int input10;
	int input11;
	int input12;
	int input13;
	int input14;
	int input15;
} t_input;

typedef	struct s_tmp_struct
{
	mlx_t	*mlx;
	//t_input	*input;
	t_map	*map;
	t_matrix_obj *mat;
}t_tmp_struct;


mlx_image_t	*g_img;


//turn the file in 'usefull' dataformat
void	hook(void *param);
void	draw_on_screen(t_map *map,mlx_image_t *img);
void	convert_map(char *filename, t_map *map);
void	free_map(t_map *map);
void 	*create_map(t_map *map, int max_x, int max_y);
void 	default_input(t_input *input);
void	set_the_matrix(t_matrix_obj *mat,t_map *map);

//------utiles.c
void	print_map(t_map *map);
void	print_cords(t_map *map);
void	print_vector(int *vector,int n);
void	drawline(t_points *point_a,t_points *point_b, mlx_image_t *img);

void	convert_test(t_map *map,t_matrix_obj *mat,int cur_y, int cur_x);


#endif