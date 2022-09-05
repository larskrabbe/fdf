#include "../include/fdf.h"

mlx_image_t	*g_img;




void	draw_on_screen(t_map *map,mlx_image_t *img)
{
	int	c_y = 0;
	int	c_x = 0;
	while(map->max_y > c_y )
	{
		while(map->max_x > c_x)
		{
			//ft_printf("y %i x %i map x %i map y %i \n",c_y, c_x,map->position[c_y][c_x]->cords[1],map->position[c_y][c_x]->cords[0]);
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

int32_t	mlx_main(t_map *map, t_input *input, t_matrix_obj *mat)
{
	mlx_t	*mlx;
	mlx_image_t *img;
	t_tmp_struct tmp;

	tmp.mlx = mlx;
	tmp.input = input;
	tmp.mat = mat;
	tmp.map = map;
	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", false);
	if (!mlx)
		exit(EXIT_FAILURE);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	g_img = img;

	draw_on_screen(map, img);
	
	mlx_image_to_window(mlx, g_img, 50, 50);
	printf("here\n");
	mlx_loop_hook(mlx, &hook, &tmp);
	mlx_loop(mlx);

	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

void	map_to_screen(t_map *map,t_matrix_obj *mat,void (*f_convert)(t_map *map, t_matrix_obj *mat, int cur_x, int cur_y))
{
	int cur_x;
	int cur_y;

	cur_x = 0;
	cur_y = 0;
	while (cur_y < map->max_y)
	{
		while (cur_x < map->max_x)
		{
			f_convert(map,mat, cur_x,  cur_y);
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
void	convert_test(t_map *map,t_matrix_obj *mat,int cur_x, int cur_y)
{
	matrix_multiply_vector(mat,map->position[cur_y][cur_x]->cords,4,map->position[cur_y][cur_x]->screen);
	// map->position[cur_y][cur_x]->screen[0] = (map->position[cur_y][cur_x]->cords[0]) * 30;
	// map->position[cur_y][cur_x]->screen[1] = (map->position[cur_y][cur_x]->cords[1] ) * 30;
}

int	main(int argc, char** argv)
{
	t_map			map;
	t_matrix_obj	mat;
	t_input			input;
	void			(*f_convert)(t_map *map, t_matrix_obj *mat, int cur_x, int cur_y);

	f_convert = &convert_test;
	if (argc <= 1)
		return(0);
	default_input(&input);
	convert_map(argv[1],&map);
	construct_matrix_obj(&mat);
	mat.f_create(&mat,4,4);
	set_the_matrix(&mat,&map,&input);
	mat.f_print(&mat);
	map_to_screen(&map,&mat,f_convert);
	mlx_main(&map,&input,&mat);
	free_map(&map);
	return(0);
}

