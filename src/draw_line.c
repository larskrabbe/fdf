/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe < lkrabbe@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:38:01 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/10/07 21:24:30 by lkrabbe          ###   ########.fr       */
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
	ptr->dx = my_abs(point_b->screen[0] - point_a->screen[0]);
	if(ptr->x <point_b->screen[0])
		ptr->sx = 1;
	else
		ptr->sx = -1;
	ptr->dy = -my_abs(point_b->screen[1] - point_a->screen[1]);
	if (ptr->y <point_b->screen[1])
		ptr->sy =1; 
	else
		ptr->sy = -1;
	ptr->error = ptr->dx + ptr->dy;
	ptr->pixel_color.color = point_a->color.color;
}

double distants(int ax, int ay, int bx , int by)
{
	double	max_distants;
	long int	x;
	long int	y;
	
	x = my_abs((bx - ax) * (bx - ax));
	y = my_abs((by - ay) * (by - ay));
	max_distants = sqrt(x + y);
	return (max_distants);
}

void	choose_color(t_breseham *ptr, t_points *point_a, t_points *point_b,float c, float d)
{
	//printf(" %% %f and  %% %f\n", (1 - d / c), d / c);
	double tmp;
	ptr->pixel_color.red = point_a->color.red * (1 - d / c) + point_b->color.red * (d / c);
	ptr->pixel_color.blue = point_a->color.blue * (1 - d / c) + point_b->color.blue * (d / c);
	ptr->pixel_color.green = point_a->color.green * (1 - d / c) + point_b->color.green * (d / c);
	ptr->pixel_color.opaqe = point_a->color.opaqe * (1 - d / c) + point_b->color.opaqe * (d / c);
	//printf("red %i = %i and %i \n",ptr->pixel_color.red,  point_a->color.red  ,point_b->color.red);
	//printf(" pixel %.8x  A %.8x B %.8x\n",ptr->pixel_color.color, point_a->color.color, point_b->color.color);
}


void plotLine(mlx_image_t *img,t_points *point_a, t_points *point_b)
{
	t_breseham b;
	
	fill_bresenham_struct(&b,point_a,point_b);
	float c = my_abs(b.dx) + my_abs(b.dy);
	float d = 0;
    while (1)
	{
		choose_color(&b,point_a,point_b,c ,d);
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
			d++;
		}
        if (b.e2 <= b.dx)
		{
            if (b.y == point_b->screen[1]) 
				break;
            b.error = b.error + b.dx;
            b.y = b.y + b.sy;
			d++;
        }
	}
}

void	drawline(t_points *point_a,t_points *point_b, mlx_image_t *img)
{
		plotLine(img,point_a, point_b);
	}
