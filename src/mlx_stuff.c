/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:15:15 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/11/06 19:28:23 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/fdf.h"

/*
	returns plus or minus  One depending if the Caps key is pressed
	1 if not pressed
*/
int	caps_check(mlx_t *mlx)
{
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT_SHIFT) || \
	mlx_is_key_down(mlx, MLX_KEY_CAPS_LOCK))
		return (-1);
	return (1);
}

/*
	The hook funktion that runs during the loop
*/
void	hook(void *param)
{
	t_all_structs	*a_s;
	double			boost;

	a_s = param;
	boost = 0.1;
	if (mlx_is_key_down(a_s->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(a_s->mlx);
	if (mlx_is_key_down(a_s->mlx, MLX_KEY_A))
		a_s->input->input[x_scale] += boost * 10 * caps_check(a_s->mlx);
	if (mlx_is_key_down(a_s->mlx, MLX_KEY_S))
		a_s->input->input[y_scale] += boost * 10 * caps_check(a_s->mlx);
	if (mlx_is_key_down(a_s->mlx, MLX_KEY_D))
		a_s->input->input[z_scale] += boost * caps_check(a_s->mlx);
	translation_hook(a_s);
	rotation_hook(a_s, caps_check(a_s->mlx));
	color_hook(a_s, caps_check(a_s->mlx));
	set_the_matrices(a_s);
	ft_bzero(a_s->img->pixels, (WIDTH * HEIGHT * sizeof(u_int32_t)));
	map_to_screen(a_s);
	if (mlx_is_key_down(a_s->mlx, MLX_KEY_TAB))
		print_data(a_s);
	draw_on_screen(a_s->map, a_s->img);
}

/*
	funktion to start the loob and open the window
*/
int32_t	mlx_main(t_all_structs *a_s)
{
	a_s->mlx = mlx_init(WIDTH, HEIGHT, "FDF", 1);
	if (!a_s->mlx)
		exit(EXIT_FAILURE);
	a_s->img = mlx_new_image(a_s->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(a_s->mlx, a_s->img, 0, 0);
	mlx_loop_hook(a_s->mlx, &hook, a_s);
	mlx_loop(a_s->mlx);
	mlx_terminate(a_s->mlx);
	return (EXIT_SUCCESS);
}
