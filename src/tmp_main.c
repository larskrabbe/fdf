#include "../include/fdf.h"

#define WIDTH 256 * 20
#define HEIGHT 256 * 20

mlx_image_t	*g_img;

void	hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
		mlx_close_window(param);
	if (mlx_is_key_down(param, MLX_KEY_UP))
		g_img->instances[0].y -= 5;
	if (mlx_is_key_down(param, MLX_KEY_DOWN))
		g_img->instances[0].y += 5;
	if (mlx_is_key_down(param, MLX_KEY_LEFT))
		g_img->instances[0].x -= 5;
	if (mlx_is_key_down(param, MLX_KEY_RIGHT))
		g_img->instances[0].x += 5;
}



int32_t	not_main(t_map *map)
{
	mlx_t	*mlx;
	mlx_image_t *img;

	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", false);
	if (!mlx)
		exit(EXIT_FAILURE);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	g_img = img;
	int i= 0;
	// while ( i++ < 100)	
	// 	mlx_put_pixel(g_img,i, i, 800080);

	//memset(g_img->pixels, 255, g_img->width * g_img->height * sizeof(int));
	// int t_x = 0;
	// while(t_x < 500)
	// {
	// 	drawline(t_x,0,100,100,img);
	// 	t_x = t_x + 10;
	// }
	int	c_y = 0;
	int	c_x = 0;
	while(map->max_y > c_y )
	{
		while(map->max_x > c_x)
		{
			ft_printf("y %i x %i map x %i map y %i \n",c_y, c_x,map->position[c_y][c_x]->cords[1],map->position[c_y][c_x]->cords[0]);
			if(c_x + 1< map->max_x)
				drawline(map->position[c_y][c_x],map->position[c_y][c_x + 1],img);
			if(c_y + 1 < map->max_y)
				drawline(map->position[c_y][c_x],map->position[c_y + 1][c_x],img);
			c_x++;
		}
		c_x = 0;
		c_y++;
	}
	 	// drawline(0,0,0,100,img);
	 	// drawline(0,100,100,100,img);
	 	// drawline(100,100,100,0,img);
	 	// drawline(100,0,0,0,img);
	mlx_image_to_window(mlx, g_img, 50, 50);
	mlx_loop_hook(mlx, &hook, mlx);
	mlx_loop(mlx);

	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
int	main(int argc, char** argv)
{
	t_map	*map;

	if (argc <= 1)
		return(0);
	map = ft_calloc(sizeof(t_map),1);
	convert_map(argv[1],map);
	print_map(map); //debug
	not_main(map);
	free_map(map);
	return(0);
}

