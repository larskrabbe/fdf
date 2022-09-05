/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:53:26 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/09/05 20:05:35 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/fdf.h"



void default_input(t_input *input)
{
	input->input0  = 1;
	input->input1  = 0;
	input->input2  = 0;
	input->input3  = 0;
	input->input4  = 0;
	input->input5  = 1;
	input->input6  = 0;
	input->input7  = 0;
	input->input8  = 0;
	input->input9  = 0;
	input->input10 = 1;
	input->input11 = 0;
	input->input12 = 0;
	input->input13 = 0;
	input->input14 = 0;
	input->input15 = 1;
}

void set_the_matrix(t_matrix_obj *mat,t_map *map,t_input *input)
{
	int scale;

	scale = 5;
	mat->f_set_single(mat,0,0,input->input0 * scale);// x value
	mat->f_set_single(mat,1,0,input->input1);
	mat->f_set_single(mat,2,0,input->input2);
	mat->f_set_single(mat,3,0,input->input3);
	mat->f_set_single(mat,0,1,input->input4);
	mat->f_set_single(mat,1,1,input->input5 * scale );// y value
	mat->f_set_single(mat,2,1,input->input6);
	mat->f_set_single(mat,3,1,input->input7);
	mat->f_set_single(mat,0,2,input->input8);
	mat->f_set_single(mat,1,2,input->input9);
	mat->f_set_single(mat,2,2,input->input10);
	mat->f_set_single(mat,3,2,input->input11);
	mat->f_set_single(mat,0,3,input->input12);
	mat->f_set_single(mat,1,3,input->input13);
	mat->f_set_single(mat,2,3,input->input14);
	mat->f_set_single(mat,3,3,input->input15);

}

mlx_t	*get_s_mlx(void *param)
{
	t_tmp_struct	*tmp;

	tmp = param;
	return(tmp->mlx);
}

t_input	*get_s_input(void *param)
{
	t_tmp_struct	*tmp;

	tmp = param;
	return(tmp->input);
}

t_map	*get_s_map(void *param)
{
	t_tmp_struct	*tmp;

	tmp = param;
	return(tmp->map);
}
void	hook(void *param)
{
	mlx_t	*mlx;
	// t_input	*input;
	// t_map	*map;
	// mlx_image_t *img_b;
	t_tmp_struct *tmp;
	tmp = param;
	mlx = get_s_mlx(param);
	// input = get_s_input(param);
	// map = get_s_map(param);
	//img_b = mlx_new_image(mlx, WIDTH, HEIGHT);

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))// this stays
		mlx_close_window(mlx);
	printf("here\n");
	// if(mlx_is_key_down(param, MLX_KEY_UP))
	// 	tmp->input->input0++;
	if (mlx_is_key_down(param, MLX_KEY_UP))
		g_img->instances[0].y -= 5;
	if (mlx_is_key_down(param, MLX_KEY_DOWN))
		g_img->instances[0].y += 5;
	if (mlx_is_key_down(param, MLX_KEY_LEFT))
		g_img->instances[0].x -= 5;
	if (mlx_is_key_down(param, MLX_KEY_RIGHT))
		g_img->instances[0].x += 5;
	//mlx_image_to_window(mlx,g_img,50,50);
	//draw_on_screen(map,img_b);
	//set_the_matrix(tmp->mat,map,input);
	//print_matrix(tmp->mat);
}
