/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 09:42:21 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/10/04 10:11:29 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/fdf.h"

void	color_hook(t_all_structs *a_s, int caps_check)
{
	int	i;

	if (mlx_is_key_down(a_s->mlx, MLX_KEY_7))
		i = red;
	else if (mlx_is_key_down(a_s->mlx, MLX_KEY_8))
		i = green;
	else if (mlx_is_key_down(a_s->mlx, MLX_KEY_9))
		i = blue;
	else if (mlx_is_key_down(a_s->mlx, MLX_KEY_0))
		i = opacity;
	else
		i = 0;
	if (i != 0)
	{
		if (caps_check == 1 && (unsigned char)a_s->input->input[red] < 255)
			a_s->input->input[i]++;
		else if (caps_check == -1 && (unsigned char)a_s->input->input[red] < 0)
			a_s->input->input[i]--;
	}
}
