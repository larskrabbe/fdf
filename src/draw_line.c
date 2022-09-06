/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:38:01 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/09/06 20:33:59 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/fdf.h"

#define COLOUR 0xFFFFFF 

int pixel_put_plus(mlx_image_t *img,double x,double y)
{
	if (x >= img->width || y >= img->height)
	{
		//printf("outside %f %f",x,y);
		return(1);
	}
	if (x < 0 || y < 0)
	{
		//printf("inside");
		return(1);
	}
	
	mlx_put_pixel(img,  x, y,COLOUR);
	return(0);
}

void	draw_hori(t_points *point_a,t_points *point_b, mlx_image_t *img)
{
	int i;

	i = 0;
	if(point_a->screen[1] <= point_b->screen[1])
	{
		while (point_a->screen[1] + i <= point_b->screen[1])
		{
			if(pixel_put_plus(img, point_a->screen[1] + i ,  point_a->screen[0]))
				return;
			i++;
		}
	}
	else
	{
		while (point_a->screen[1] + i >= point_b->screen[1])
		{
			if(pixel_put_plus(img,  point_a->screen[1] + i, point_a->screen[0]))
				return;
			i--;
		}
	}
}

void	draw_vert(t_points *point_a,t_points *point_b, mlx_image_t *img)
{
	unsigned i;

	i = 0;
	if(point_a->screen[0] <= point_b->screen[0])
	{
		while (point_a->screen[0] + i <= point_b->screen[0])
		{
			if(pixel_put_plus(img, point_a->screen[1], point_a->screen[0] + i ))
				return;
			i++;
		}
	}
	else
	{
		while (point_a->screen[0] + i >= point_b->screen[0])
		{
			if(pixel_put_plus(img, point_a->screen[1], point_a->screen[0] + i))
				return;
			i--;
		}
	}
}

// need to replace abs with ft_abs
// unsigned ft_abs()
// {
	
	
// }

// need  to look to avoid using this struct, but its to many variable , maybe look to splitting funktion
typedef struct s_bresenham
{
	double dx;
	double sx;
	double dy;
	double sy;
	double err;
	double e2;
	double folow[2];
}t_bresenham;

void	drawline(t_points *point_a,t_points *point_b, mlx_image_t *img)
{
	t_bresenham data;

	data.dx =  fabs(point_b->screen[1] - point_a->screen[1]);
	data.sx = point_a->screen[1] < point_b->screen[1] ? 1 : -1;
	data.dy = -fabs(point_b->screen[0] - point_a->screen[0]);
	data.sy = point_a->screen[0] < point_b->screen[0] ? 1 : -1;
	data.err = data.dx + data.dy;
	data.e2 = 0;
	data.folow[0] = point_a->screen[0];
	data.folow[1] = point_a->screen[1];
	unsigned i = 0;

	if(point_a->screen[1] > img->height || point_a->screen[0] > img->width)
		return;
	if(data.dx == 0)
		return(draw_vert(point_a, point_b, img));
	if(data.dy == 0)
		return(draw_hori(point_a, point_b, img));
	while (1)
	{
		i++;
		if(pixel_put_plus(img, data.folow[1], data.folow[0]))
			return;
		if (data.folow[1] == point_b->screen[1] &&data.folow[0] ==point_b->screen[0])
			break;
		data.e2 = 2 * data.err;
		if (data.e2 > data.dy) 
		{
			data.err += data.dy;
			data.folow[1] += data.sx;
		}
		if (data.e2 < data.dx)
		{
			data.err += data.dx;
			data.folow[0] += data.sy;
		}
	}
}