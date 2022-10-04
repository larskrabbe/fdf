/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:38:01 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/10/04 13:01:13 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/fdf.h"


#include	"../include/fdf.h"


int pixel_put_plus(mlx_image_t *img,double x,double y,int color)
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
	
	mlx_put_pixel(img,  x, y,color);
	return(0);
}

/*
	calc the colour depending on the distance to the points
*/
int		choose_colour()
{
	
	return(COLOUR);
}

/*
	draws a horisontel line on the screen(img). its faster as bresenham
*/
void	draw_hori(t_points *point_a,t_points *point_b, mlx_image_t *img)
{
	int i;

	i = 0;
	if(point_a->screen[1] <= point_b->screen[1])
	{
		while (point_a->screen[1] + i <= point_b->screen[1])
		{
			if(pixel_put_plus(img, point_a->screen[1] + i ,  point_a->screen[0],point_a->color.color))
				return;
			i++;
		}
	}
	else
	{
		while (point_a->screen[1] + i >= point_b->screen[1])
		{
			if(pixel_put_plus(img,  point_a->screen[1] + i, point_a->screen[0],point_a->color.color))
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
			if(pixel_put_plus(img, point_a->screen[1], point_a->screen[0] + i ,point_a->color.color))
				return;
			i++;
		}
	}
	else
	{
		while (point_a->screen[0] + i >= point_b->screen[0])
		{
			if(pixel_put_plus(img, point_a->screen[1], point_a->screen[0] + i,point_a->color.color))
				return;
			i--;
		}
	}
}

void	fill_bresenham_struct(t_breseham *ptr, t_points *point_a, t_points *point_b)
{
	ptr->x = point_a->screen[0];
	ptr->y = point_a->screen[1];
	ptr->dx = ft_abs(point_b->screen[0] - point_a->screen[0]);
	if(point_b->screen[0] < point_a->screen[0])
		ptr->sx = 1;
	else
		ptr->sx = -1;
	ptr->dy = -ft_abs(point_b->screen[1] - point_a->screen[1]);
	if (point_b->screen[1] - point_a->screen[1])
		ptr->sy =1; 
	else
		ptr->sy = -1;
	ptr->error = ptr->dx + ptr->dy;
	ptr->e2 = ptr->error * 2;
}

void plotLine(mlx_image_t *img,int x0,int  y0,int  x1,int y1,t_points *point_a, t_points *point_b)
{
	t_breseham b;

	fill_bresenham_struct(&b,point_a,point_b);
    int dx = ft_abs(x1 - b.x);
    int sx = b.x < x1 ? 1 : -1;
    int dy = -ft_abs(y1 - b.y);
    int sy = b.y < y1 ? 1 : -1;
    int error = b.dx + b.dy;
    
    while (1)
	{
        pixel_put_plus(img,b.x, b.y,COLOUR);
        if( b.x == x1 && b.y == y1)
			break;
        int e2 = 2 * error;
        if (e2 >= dy)
		{
            if (b.x == x1 )
				break;
            error = error +b.dy;
            b.x = b.x + sx;
		}
        if (e2 <= dx)
		{
            if (b.y == y1) 
				break;
            error = error + b.dx;
            b.y = b.y + sy;
        }
	}
}

void	drawline(t_points *point_a,t_points *point_b, mlx_image_t *img)
{
	plotLine(img,point_a->screen[0],point_a->screen[1],point_b->screen[0],point_b->screen[1],point_a, point_b);
}
