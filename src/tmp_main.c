#include "../include/fdf.h"

#define WIDTH 256 * 2
#define HEIGHT 256 * 2

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
	//drawline(50,0,50,600);
	drawline(20,2,50,100,img);
	drawline(0,0,50,200,img);
	drawline(0,0,20,100,img);

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

