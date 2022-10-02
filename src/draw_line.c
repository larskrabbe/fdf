/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:38:01 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/10/02 17:48:22 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/fdf.h"


int pixel_put_plus(mlx_image_t *img,double x,double y,u_colour color)
{
	if (x >= img->width || y >= img->height)
	{
		return(1);
	}
	if (x < 0 || y < 0)
	{
		return(1);
	}
	mlx_put_pixel(img, x, y, color.abcd);
	return(0);
}

/*
	calc the colour depending on the distance to the points
*/
int		choose_colour()
{
	
	return(COLOUR);
}



void plotLine(mlx_image_t *img,int x0,int  y0,int  x1,int y1,u_colour colour)
{
    int dx = abs(x1 - x0);
    int sx = x0 < x1 ? 1 : -1;
    int dy = -abs(y1 - y0);
    int sy = y0 < y1 ? 1 : -1;
    int error = dx + dy;
    
    while (1)
	{
        pixel_put_plus(img,x0, y0,colour);
        if( x0 == x1 && y0 == y1)
			break;
        int e2 = 2 * error;
        if (e2 >= dy)
		{
            if (x0 == x1 )
				break;
            error = error + dy;
            x0 = x0 + sx;
		}
        if (e2 <= dx)
		{
            if (y0 == y1) 
				break;
            error = error + dx;
            y0 = y0 + sy;
        }
	}
}


void	drawline(t_points *point_a,t_points *point_b, mlx_image_t *img)
{
	plotLine(img,point_a->screen[0],point_a->screen[1],point_b->screen[0],point_b->screen[1],point_a->colour);
}
// /*
// 	draws a horisontel line on the screen(img). its faster as bresenham
// */
// void	draw_hori(t_points *point_a,t_points *point_b, mlx_image_t *img)
// {
// 	int i;

// 	i = 0;
// 	if(point_a->screen[1] <= point_b->screen[1])
// 	{
// 		while (point_a->screen[1] + i <= point_b->screen[1])
// 		{
// 			if(pixel_put_plus(img, point_a->screen[1] + i ,  point_a->screen[0],point_a->colour))
// 				return;
// 			i++;
// 		}
// 	}
// 	else
// 	{
// 		while (point_a->screen[1] + i >= point_b->screen[1])
// 		{
// 			if(pixel_put_plus(img,  point_a->screen[1] + i, point_a->screen[0],point_a->colour))
// 				return;
// 			i--;
// 		}
// 	}
// }

// void	draw_vert(t_points *point_a,t_points *point_b, mlx_image_t *img)
// {
// 	unsigned i;

// 	i = 0;
// 	if(point_a->screen[0] <= point_b->screen[0])
// 	{
// 		while (point_a->screen[0] + i <= point_b->screen[0])
// 		{
// 			if(pixel_put_plus(img, point_a->screen[1], point_a->screen[0] + i ,point_a->colour))
// 				return;
// 			i++;
// 		}
// 	}
// 	else
// 	{
// 		while (point_a->screen[0] + i >= point_b->screen[0])
// 		{
// 			if(pixel_put_plus(img, point_a->screen[1], point_a->screen[0] + i,point_a->colour))
// 				return;
// 			i--;
// 		}
// 	}
// }

// // need to replace abs with ft_abs
// // unsigned ft_abs()
// // {
	
	
// // }

// // need  to look to avoid using this struct, but its to many variable , maybe look to splitting funktion
// typedef struct s_bresenham
// {
// 	double dx;
// 	double sx;
// 	double dy;
// 	double sy;
// 	double err;
// 	double e2;
// 	double folow[2];
// }t_bresenham;
