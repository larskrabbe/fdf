/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 19:32:01 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/11/27 13:07:50 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH 1000
# define HEIGHT 1000
# define COLOUR 0x5B5BFF8F 

//*************************LIBARYS*********************************************

# include	"libft.h"
# include	"../MLX42/include/MLX42/MLX42.h"
# include	"../MLX42/include/MLX42/MLX42_Input.h"
# include	<fcntl.h>
# include	"libft_plus.h"
# include	"math.h"
# include	"matrix_o.h"
//*************************STRUCTURE*******************************************

/**
 * @brief union to cheat out the diffrent colours
 * 
 */
typedef union u_color{
	struct{
		uint8_t	opaqe;
		uint8_t	blue;
		uint8_t	green;
		uint8_t	red;
	};
	uint32_t	color;
}t_color;

typedef struct s_points{
	double	cords[4];
	t_color	color;
	int		screen[4];
}t_points;

/*
		s_map			=> stores the  information from the file in a struct 
	unsigned int max_x	=> max x size for the map
	unsigned int max_y;	=> max y size for the map
	t_points **position => x * y size array of points 
*/
typedef struct s_map{
	int	max_x;
	int	max_y;	
	t_points		***position;
}t_map;

/*
	stores the values for the matrices that can be change user inputs
*/
typedef struct s_input
{
	int32_t	*heigt;
	int32_t	*width;
	double	input[16];
}t_input;

typedef struct s_all_structs
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_input			*input;
	t_map			*map;
	t_matrix_obj	*mtx_s;
	t_matrix_obj	*mtx_x;
	t_matrix_obj	*mtx_y;
	t_matrix_obj	*mtx_z;
	t_matrix_obj	*mtx_p;
}t_all_structs;

typedef struct s_bresenham
{
	int		dx;
	int		sx;
	int		dy;
	int		sy;
	int		error;
	int		x;
	int		y;
	int		e2;
	t_color	pixel_color;
	float	start;
	float	end;
}t_breseham;

//*************************ENUMS*******************************************

typedef enum e_enput{
	x_scale = 0,
	y_scale = 1,
	z_scale = 2,
	w_scale = 3,
	x_rotation = 4,
	y_rotation = 5,
	z_rotation = 6,
	x_translation = 7,
	y_translation = 8,
	red = 9,
	green = 10,
	blue = 11,
	opacity = 12,
	zoom = 13,
}t_enput;

void			_matrices(t_all_structs *a_s);
void			screen(t_all_structs *a_s);
void			transform(t_all_structs *a_s, int cur_x, int cur_y);

//turn the file in 'usefull' dataformat
void			hook(void *param);
void			draw_on_screen(t_map *map, mlx_image_t *img);
t_map			*convert_map(char *filename, t_map *map);
void			free_map(t_map *map, int max_x, int max_y);
void			*create_map(t_map *map, int max_x, int max_y);
t_input			*default_input(t_input *input, t_all_structs *a_s);
void			set_the_matrix(t_matrix_obj *mat, t_map *map, t_input *input);
void			free_str_array(char **strings);
double			convert_cords(unsigned int cur_p, double max);
int				pixel_put_plus(mlx_image_t *img, double x, double y, int color);

//------utiles.c
void			print_screen(t_map *map);
void			print_map(t_map *map);
void			print_cords(t_map *map);
void			print_vector(double *vector, int n);
void			drawline(t_points *point_a, \
t_points *point_b, mlx_image_t *img);
void			print_color(t_map *map);
void			print_data(t_all_structs *a_s);
//------mlx-stuff.c
int32_t			mlx_main(t_all_structs *a_s);
//------matrix_stuff.c
void			free_before_end(t_all_structs *a_s);
void			vector_transform(t_all_structs *a_s, int cur_x, int cur_y);
t_matrix_obj	*matrix_setup(t_matrix_obj *mtx);
//-----hooks.c
void			color_hook(t_all_structs *a_s, int caps_check);
void			rotation_hook(t_all_structs *a_s, int caps_check);
void			translation_hook(t_all_structs *a_s);
void			set_the_s_matrix(double **matrix, t_input *input);
void			set_the_p_matrix(double **matrix, t_input *input);
void			set_the_x_matrix(double **matrix, double value);
void			set_the_y_matrix(double **matrix, double value);
void			set_the_z_matrix(double **matrix, double value);
int				count_chr_from_str(const char *str, const char chr);
int				counts_lines_from_file(char *file);
int				count_words_in_str(char *str);
int				is_white_space(int a);
int				my_abs(int num);
int				my_hextoi(const char *str);
void			set_the_matrices(t_all_structs *a_s);
void			map_to_screen(t_all_structs *a_s);
void			draw_on_screen(t_map *map, mlx_image_t *img);

#endif