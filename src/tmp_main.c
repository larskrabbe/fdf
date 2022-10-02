#include "../include/fdf.h"


/*
	draws line betwenn cords
*/
void	draw_on_screen(t_map *map, mlx_image_t *img)
{
	int	c_y = 0;
	int	c_x = 0;

	//print_map(map);
	while(map->max_y > c_y )
	{
		while(map->max_x > c_x)
		{
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

/*
	uses f vector_transform on each cordinate// maybe change it to funktion pointer
*/
void	map_to_screen(t_all_structs *a_s)
{
	int cur_x;
	int cur_y;

	cur_x = 0;
	cur_y = 0;
	while (cur_y < a_s->map->max_y)
	{
		while (cur_x < a_s->map->max_x)
		{
			//printf("before vector_transform\n");
			vector_transform(a_s, cur_x,  cur_y);
			cur_x++;
		}
		cur_x = 0;
		cur_y++;
	}
}


/*
	Creat the main Struct that contain all other structs and frees them at the end
	small input protection
	gives the main struct to the mlx_main
*/
int	main(int argc, char** argv)
{
	mlx_t			mlx;
	t_map			map;
	t_input			input;
	t_matrix_obj	mtx_s;
	t_matrix_obj	mtx_x;
	t_matrix_obj	mtx_y;
	t_matrix_obj	mtx_z;
	t_matrix_obj	mtx_p;
	t_all_structs	a_s;

	int32_t test = 561351321;

	if (argc <= 1)
		return(0);
	a_s.mlx = &mlx;
	a_s.input = default_input(&input);
	a_s.map = convert_map(argv[1],&map);
	a_s.mtx_s = matrix_setup(&mtx_s);
	a_s.mtx_x = matrix_setup(&mtx_x);
	a_s.mtx_y = matrix_setup(&mtx_y);
	a_s.mtx_z = matrix_setup(&mtx_z);
	a_s.mtx_p = matrix_setup(&mtx_p);
	mlx_main(&a_s);
	free_before_end(&a_s);
	return(0);
}
