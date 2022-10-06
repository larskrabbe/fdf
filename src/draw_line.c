/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe < lkrabbe@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:38:01 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/10/05 16:21:52 by lkrabbe          ###   ########.fr       */
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

// /*
// 	calc the colour depending on the distance to the points
// */
// t_color	choose_colour(t_points *point_a, t_points *point_b,int x, int y)
// {
// 	t_color pixel_color;

// 	pixel_color.red = point_a->color.red + (point_a->color.red - point_b->color.red) * 
	
// 	return(pixel_color);
// }

void	fill_bresenham_struct(t_breseham *ptr, t_points *point_a, t_points *point_b)
{
	ptr->x = point_a->screen[0];
	ptr->y = point_a->screen[1];
	ptr->dx = ft_abs(point_b->screen[0] - point_a->screen[0]);
	if(ptr->x <point_b->screen[0])
		ptr->sx = 1;
	else
		ptr->sx = -1;
	ptr->dy = -ft_abs(point_b->screen[1] - point_a->screen[1]);
	if (ptr->y <point_b->screen[1])
		ptr->sy =1; 
	else
		ptr->sy = -1;
	ptr->error = ptr->dx + ptr->dy;
}


void color_base(t_points *point_a, t_points *point_b,t_breseham *ptr)
{
	ptr->pixel_color.color = point_a->color.color;
	ptr->add_red = point_b->color.red - point_a->color.red;
	ptr->add_blue = point_b->color.blue - point_a->color.blue;
	ptr->add_green = point_b->color.green - point_a->color.green;
	ptr->add_opaqe = point_b->color.opaqe - point_a->color.opaqe;
	// if (ptr->add_red != 0 && ptr->dx != 0)
	// 	ptr->add_red = ptr->add_red / ptr->dx;
	// if (ptr->add_blue != 0 && ptr->dx != 0)
	// 	ptr->add_blue = ptr->add_blue / ptr->dx;
	// if (ptr->add_green != 0 && ptr->dx != 0)
	// 	ptr->add_green = ptr->add_green / ptr->dx;
	// if (ptr->add_opaqe != 0 && ptr->dx != 0)
	// 	ptr->add_opaqe = ptr->add_opaqe / ptr->dx;
}

void plotLine(mlx_image_t *img,t_points *point_a, t_points *point_b)
{
	t_breseham b;
	
	color_base(point_a,point_b,&b);
	fill_bresenham_struct(&b,point_a,point_b);
    while (1)
	{
		//choose_colour();
        pixel_put_plus(img,b.x, b.y,b.pixel_color.color);
        if( b.x == point_b->screen[0] && b.y == point_b->screen[1])
			break;
		b.e2 = 2 * b.error;
        if (b.e2 >= b.dy)
		{
            if (b.x == point_b->screen[0])
				break;
            b.error = b.error +b.dy;
            b.x = b.x + b.sx;
		}
        if (b.e2 <= b.dx)
		{
            if (b.y == point_b->screen[1]) 
				break;
            b.error = b.error + b.dx;
            b.y = b.y + b.sy;
        }
		b.pixel_color.red += b.add_red;
		b.pixel_color.blue += b.add_blue;
		b.pixel_color.green += b.add_green;
		b.pixel_color.opaqe += b.add_opaqe;
	}
}

void	drawline(t_points *point_a,t_points *point_b, mlx_image_t *img)
{
		plotLine(img,point_a, point_b);
}
