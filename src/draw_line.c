/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:38:01 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/08/29 21:09:22 by lkrabbe          ###   ########.fr       */
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



void	drawline(int x0, int y0, int x1, int y1, mlx_image_t *img)
{
    int dx, dy, p, x, y;
 
	dx=x1-x0;
	dy=y1-y0;
	
	p=2*dy-dx;
	
	while(x0<x1)
	{
		if(p>=0)
		{
			mlx_put_pixel(img,x0, y0, 0);
			y0=y0+1;
			p=p+2*dy-2*dx;
			}
		else
		{
			mlx_put_pixel(img,x0, y0, 0);
			p=p+2*dy;
		}
		x0=x0+1;
	}
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