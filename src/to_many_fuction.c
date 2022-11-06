/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_many_fuction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 18:56:44 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/11/05 19:03:32 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/fdf.h"

/*
	converts the cordinate so that  0 0 is in the the middle of the object
*/
double	convert_cords(unsigned int cur_p, double max)
{
	return ((double)(cur_p / (max - 1) - 0.5)*2);
}

int	pixel_put_plus(mlx_image_t *img, double x, double y, int color)
{
	if (x >= img->width || y >= img->height)
		return (1);
	if (x < 0 || y < 0)
		return (1);
	mlx_put_pixel(img, x, y, color);
	return (0);
}

/*
	set the values inside all matrices
*/
void	set_the_matrices(t_all_structs *a_s)
{
	set_the_s_matrix(a_s->mtx_s->matrix, a_s->input);
	set_the_x_matrix(a_s->mtx_x->matrix, a_s->input->input[x_rotation]);
	set_the_y_matrix(a_s->mtx_y->matrix, a_s->input->input[y_rotation]);
	set_the_z_matrix(a_s->mtx_z->matrix, a_s->input->input[z_rotation]);
	set_the_p_matrix(a_s->mtx_p->matrix, a_s->input);
}

/*
	set the default value inside myinput struct
*/
t_input	*default_input(t_input *input)
{
	input->input[x_scale] = 300;
	input->input[y_scale] = 300;
	input->input[z_scale] = 0;
	input->input[w_scale] = 1;
	input->input[x_rotation] = 0;
	input->input[y_rotation] = 0;
	input->input[z_rotation] = 0;
	input->input[x_translation] = WIDTH / 2;
	input->input[y_translation] = HEIGHT / 2;
	input->input[red] = 12;
	input->input[green] = 12;
	input->input[blue] = 12;
	input->input[opacity] = 12;
	return (input);
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
