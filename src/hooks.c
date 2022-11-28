/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 09:42:21 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/11/28 13:20:25 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/fdf.h"

void	rotation_hook(t_all_structs *a_s, int caps_check)
{
	double	boost;

	boost = 0.1;
	if (mlx_is_key_down(a_s->mlx, MLX_KEY_1))
		a_s->input->input[x_rotation] += boost * caps_check;
	if (mlx_is_key_down(a_s->mlx, MLX_KEY_2))
		a_s->input->input[y_rotation] += boost * caps_check;
	if (mlx_is_key_down(a_s->mlx, MLX_KEY_3))
		a_s->input->input[z_rotation] += boost * caps_check;
}

void	color_change(t_all_structs *a_s, int caps_check, int color)
{
	if (caps_check == 1 && (unsigned char)a_s->input->input[color] < 255)
		a_s->input->input[color]++;
	else if (caps_check == -1 && (unsigned char)a_s->input->input[color] < 0)
		a_s->input->input[color]--;
}

void	color_hook(t_all_structs *a_s, int caps_check)
{
	if (mlx_is_key_down(a_s->mlx, MLX_KEY_7))
		color_change(a_s, caps_check, red);
	if (mlx_is_key_down(a_s->mlx, MLX_KEY_8))
		color_change(a_s, caps_check, green);
	if (mlx_is_key_down(a_s->mlx, MLX_KEY_9))
		color_change(a_s, caps_check, blue);
	if (mlx_is_key_down(a_s->mlx, MLX_KEY_0))
		color_change(a_s, caps_check, opacity);
}

void	translation_hook(t_all_structs *a_s)
{
	int	boost;

	boost = 10;
	if (mlx_is_key_down(a_s->mlx, MLX_KEY_UP))
		a_s->input->input[y_translation] -= boost;
	if (mlx_is_key_down(a_s->mlx, MLX_KEY_DOWN))
		a_s->input->input[y_translation] += boost;
	if (mlx_is_key_down(a_s->mlx, MLX_KEY_LEFT))
		a_s->input->input[x_translation] -= boost;
	if (mlx_is_key_down(a_s->mlx, MLX_KEY_RIGHT))
		a_s->input->input[x_translation] += boost;
	if (mlx_is_key_down(a_s->mlx, MLX_KEY_EQUAL))
		a_s->input->input[zoom] += 0.1 ;
	if (mlx_is_key_down(a_s->mlx, MLX_KEY_MINUS))
	{
		a_s->input->input[zoom] -= 0.1 ;
		if (a_s->input->input[zoom] < 0)
			a_s->input->input[zoom] = 0. ;
	}
}
