/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:38:01 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/11/06 18:19:08 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/fdf.h"

void	fill_brshm_strct(t_breseham *ptr, t_points *point_a, t_points *point_b)
{
	ptr->x = point_a->screen[0];
	ptr->y = point_a->screen[1];
	ptr->dx = my_abs(point_b->screen[0] - point_a->screen[0]);
	if (ptr->x < point_b->screen[0])
		ptr->sx = 1;
	else
		ptr->sx = -1;
	ptr->dy = -my_abs(point_b->screen[1] - point_a->screen[1]);
	if (ptr->y < point_b->screen[1])
		ptr->sy = 1;
	else
		ptr->sy = -1;
	ptr->error = ptr->dx + ptr->dy;
	ptr->pixel_color.color = point_a->color.color;
	ptr->start = my_abs(ptr->dx) + my_abs(ptr->dy);
	ptr->end = 0;
}

double	distants(int ax, int ay, int bx, int by)
{
	double		max_distants;
	long int	x;
	long int	y;

	x = my_abs((bx - ax) * (bx - ax));
	y = my_abs((by - ay) * (by - ay));
	max_distants = sqrt(x + y);
	return (max_distants);
}

void	choose_color(t_breseham *ptr, t_points *point_a, \
t_points *point_b, float a_to_b)
{
	ptr->pixel_color.red = point_a->color.red * \
	(1 - a_to_b) + point_b->color.red * (a_to_b);
	ptr->pixel_color.blue = point_a->color.blue * \
	(1 - a_to_b) + point_b->color.blue * (a_to_b);
	ptr->pixel_color.green = point_a->color.green * \
	(1 - a_to_b) + point_b->color.green * (a_to_b);
	ptr->pixel_color.opaqe = point_a->color.opaqe * \
	(1 - a_to_b) + point_b->color.opaqe * (a_to_b);
}

void	plotline(mlx_image_t *img, t_points *point_a, \
t_points *point_b, t_breseham *b)
{
	while (1)
	{
		choose_color(b, point_a, point_b, b->end / b->start);
		pixel_put_plus(img, b->x, b->y, b->pixel_color.color);
		if (b->x == point_b->screen[0] && b->y == point_b->screen[1])
			break ;
		b->e2 = 2 * b->error;
		if (b->e2 >= b->dy)
		{
			if (b->x == point_b->screen[0])
				break ;
			b->error = b->error + b->dy;
			b->x = b->x + b->sx;
			b->end++;
		}
		if (b->e2 <= b->dx)
		{
			if (b->y == point_b->screen[1])
				break ;
			b->error = b->error + b->dx;
			b->y = b->y + b->sy;
			b->end++;
		}
	}
}

void	drawline(t_points *point_a, t_points *point_b, mlx_image_t *img)
{
	t_breseham	b;

	fill_brshm_strct(&b, point_a, point_b);
	plotline(img, point_a, point_b, &b);
}
