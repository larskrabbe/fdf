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

void	draw_on_screen(t_map *map,mlx_image_t *img)
{
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
}

int32_t	mlx_main(t_map *map)
{
	mlx_t	*mlx;
	mlx_image_t *img;

	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", false);
	if (!mlx)
		exit(EXIT_FAILURE);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	g_img = img;

	draw_on_screen(map, img);
	mlx_image_to_window(mlx, g_img, 50, 50);
	mlx_loop_hook(mlx, &hook, mlx);
	mlx_loop(mlx);

	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

void	map_to_screen(t_map *map,void (*f_convert)(t_map *map, int cur_x, int cur_y))
{
	int cur_x;
	int cur_y;

	cur_x = 0;
	cur_y = 0;
	while (cur_y < map->max_y)
	{
		while (cur_x < map->max_x)
		{
			f_convert(map, cur_x,  cur_y);
			cur_x++;
		}
		cur_x = 0;
		cur_y++;
	}
}
/*
2D = (x3D + z3D) * cos(theta)
y2D = (-x3D + z3D) * sin(theta) + y3D
*/
void	convert_test(t_map *map,int cur_x, int cur_y)
{
	map->position[cur_y][cur_x]->screen[0] = (map->position[cur_y][cur_x]->cords[0]) * 30;
	map->position[cur_y][cur_x]->screen[1] = (map->position[cur_y][cur_x]->cords[1] ) * 30;
}



int	main(int argc, char** argv)
{
	t_map	*map;
	void	(*f_convert)(t_map *map, int cur_x, int cur_y);
	f_convert = &convert_test;
	if (argc <= 1)
		return(0);
	map = ft_calloc(sizeof(map),1);
	convert_map(argv[1],map);
	map_to_screen(map,f_convert);
	mlx_main(map);
	free_map(map);
	return(0);
}

