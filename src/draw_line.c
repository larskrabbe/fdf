/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:38:01 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/08/31 20:06:11 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/fdf.h"

/*
plotLine(x0, y0, x1, y1)
	dx = abs(x1 - x0)
	sx = x0 < x1 ? 1 : -1
	dy = -abs(y1 - y0)
	sy = y0 < y1 ? 1 : -1
	error = dx + dy
	
	while true
		plot(x0, y0)
		if x0 == x1 && y0 == y1 break
		e2 = 2 * error
		if e2 >= dy
			if x0 == x1 break
			error = error + dy
			x0 = x0 + sx
		end if
		if e2 <= dx
			if y0 == y1 break
			error = error + dx
			y0 = y0 + sy
		end if
	end while
*/
#define COLOUR 0xFFFFF
void	draw_hori(t_points *point_a,t_points *point_b, mlx_image_t *img)
{
	int i;

	i = 0;
	if(point_a->cords[1] <= point_b->cords[1])
	{
		while (point_a->cords[1] + i <= point_b->cords[1])
		{
			mlx_put_pixel(img, point_a->cords[1] + i ,  point_a->cords[0], COLOUR);
			i++;
		}
	}
	else
	{
		while (point_a->cords[1] >= point_b->cords[1])
		{
			mlx_put_pixel(img,  point_a->cords[1] + i, point_a->cords[0],COLOUR);
			i--;
		}
	}
}

void	draw_vert(t_points *point_a,t_points *point_b, mlx_image_t *img)
{
	int i;

	i = 0;
	if(point_a->cords[0] <= point_b->cords[0])
	{
		while (point_a->cords[0] + i <= point_b->cords[0])
		{
			mlx_put_pixel(img, point_a->cords[1], point_a->cords[0] + i , COLOUR);
			i++;
		}
	}
	else
	{
		while (point_a->cords[0] >= point_b->cords[0])
		{
			mlx_put_pixel(img, point_a->cords[1], point_a->cords[0] + i , COLOUR);
			i--;
		}
	}
}

// need to replace abs with ft_abs
unsigned ft_abs()
{
	
	
}

// need  to look to avoid using this struct, but its to many variable , maybe look to splitting funktion
typedef struct s_bresenham
{
	int dx;
	int sx;
	int dy;
	int sy;
	int err;
	int e2;
	int folow[2];
}t_bresenham;

void	drawline(t_points *point_a,t_points *point_b, mlx_image_t *img)
{
	t_bresenham data;

	data.dx =  abs(point_b->cords[1] - point_a->cords[1]);
	data.sx = point_a->cords[1] < point_b->cords[1] ? 1 : -1;
	data.dy = -abs(point_b->cords[0] - point_a->cords[0]);
	data.sy = point_a->cords[0] < point_b->cords[0] ? 1 : -1;
	data.err = data.dx + data.dy;
	data.e2 = 0;
	data.folow[0] = point_a->cords[0];
	data.folow[1] = point_a->cords[1];

	if(data.dx == 0)
		return(draw_vert(point_a, point_b, img));
	if(data.dy == 0)
		return(draw_hori(point_a, point_b, img));
	while (1)
	{
		mlx_put_pixel(img, data.folow[1], data.folow[0], COLOUR);
		if (data.folow[1] == point_b->cords[1] &&data.folow[0] ==point_b->cords[0])
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