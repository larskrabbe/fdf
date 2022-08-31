/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:38:01 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/08/31 15:04:36 by lkrabbe          ###   ########.fr       */
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
#define COLOUR 1000
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

void	drawline(t_points *point_a,t_points *point_b, mlx_image_t *img)
{
	// int dx, dy, p, x, y;
 
	// dx = x1 - x0;
	// dy = y1 - y0;
	if(point_a->cords[1] == point_b->cords[1])
		return(draw_vert(point_a, point_b, img));
	if(point_a->cords[0] == point_b->cords[0])
		return(draw_vert(point_a, point_b, img));
	// p = 2 * dy - dx;
	// if(dy <= dx)
	// {
	// 	while(x0 < x1)
	// 	{
	// 		if(p >= 0)
	// 		{
	// 			mlx_put_pixel(img, x0, y0, 1000);
	// 			y0 = y0 + 1;
	// 			p = p + 2 * dy - 2 * dx;
	// 		}
	// 		else
	// 		{
	// 			mlx_put_pixel(img, x0, y0, 1000);
	// 			p = p + 2 * dy;
	// 		}
	// 		x0 = x0 + 1;
	// 	}
	// }
	// else
	// {
	// 	while(y0 < y1)
	// 	{
	// 		if(p >= 0)
	// 		{
	// 			mlx_put_pixel(img, x0, y0, 1000);
	// 			x0 = x0 + 1;
	// 			p = p + 2 * dy - 2 * dx;
	// 		}
	// 		else
	// 		{
	// 			mlx_put_pixel(img, x0, y0, 1000);
	// 			p = p + 2 * dy;
	// 		}
	// 		y0 = y0 + 1;
	// 	}
	// }
}
 
// int main()
// {
// int gdriver=DETECT, gmode, error, x0, y0, x1, y1;
// initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");
 
// printf("Enter co-ordinates of first point: ");
// scanf("%d%d", &x0, &y0);
 
// printf("Enter co-ordinates of second point: ");
// scanf("%d%d", &x1, &y1);
// drawline(x0, y0, x1, y1);
 
// return 0;
// }