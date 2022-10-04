/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe < lkrabbe@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:15:15 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/10/03 13:29:37 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/fdf.h"

/*
	returns plus or minus  One depending if the Caps key is pressed
	1 if not pressed
*/
int Caps_check(mlx_t *mlx)
{
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT_SHIFT) || mlx_is_key_down(mlx, MLX_KEY_CAPS_LOCK))
		return(-1);
	return(1);
}

/*
	The hook funktion that runs during the loop
*/
void	hook(void *param)// can use this to  spin things around
{
	t_all_structs *a_s;

	a_s = param;

	double boost;//  maybe use define for this
	boost =0.1;

	if (mlx_is_key_down(a_s->mlx, MLX_KEY_ESCAPE))// this stays
		mlx_close_window(a_s->mlx);
	if (mlx_is_key_down(a_s->mlx, MLX_KEY_UP))
		a_s->input->input[y_translation] -= 10;
	if (mlx_is_key_down(a_s->mlx, MLX_KEY_DOWN))
		a_s->input->input[y_translation] += 10;
	if (mlx_is_key_down(a_s->mlx, MLX_KEY_LEFT))
		a_s->input->input[x_translation] -= 10;
	if (mlx_is_key_down(a_s->mlx, MLX_KEY_RIGHT))
		a_s->input->input[x_translation] += 10;
	if (mlx_is_key_down(a_s->mlx, MLX_KEY_A))
		a_s->input->input[x_scale] += boost* 10 * Caps_check(a_s->mlx);
	if (mlx_is_key_down(a_s->mlx, MLX_KEY_S))
		a_s->input->input[y_scale] += boost* 10 *Caps_check(a_s->mlx);
	if (mlx_is_key_down(a_s->mlx, MLX_KEY_D))
		a_s->input->input[z_scale] += boost *Caps_check(a_s->mlx);
	if (mlx_is_key_down(a_s->mlx, MLX_KEY_1))
		a_s->input->input[x_rotation] += boost *Caps_check(a_s->mlx);
	if (mlx_is_key_down(a_s->mlx, MLX_KEY_2))
		a_s->input->input[y_rotation] += boost *Caps_check(a_s->mlx);
	if (mlx_is_key_down(a_s->mlx, MLX_KEY_3))
		a_s->input->input[z_rotation] += boost *Caps_check(a_s->mlx);
	set_the_matrices(a_s);
	ft_bzero(a_s->img->pixels,(WIDTH * HEIGHT * sizeof(u_int32_t)));
	map_to_screen(a_s);
	if (mlx_is_key_down(a_s->mlx, MLX_KEY_TAB))
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
		print_screen(a_s->map);
	}
		draw_on_screen(a_s->map, a_s->img);
}

/*
	funktion to start the loob and open the window
*/
int32_t	mlx_main(t_all_structs *a_s)
{
	a_s->mlx = mlx_init(WIDTH, HEIGHT, "FDF", 1);
	if (!a_s->mlx)
		exit(EXIT_FAILURE);// need safe release
	a_s->img = mlx_new_image(a_s->mlx, WIDTH, HEIGHT);// need to safe width and heigth in to struct
	mlx_image_to_window(a_s->mlx, a_s->img, 0, 0);
	mlx_loop_hook(a_s->mlx, &hook, a_s);
	//printf("before mlx_loop\n");
	//a_s->mtx_s->f_print(a_s->mtx_s);
	mlx_loop(a_s->mlx);
	mlx_terminate(a_s->mlx);
	return (EXIT_SUCCESS);
}