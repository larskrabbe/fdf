#include "../include/fdf.h"

/*
	returns plus or minus  One depending if the Caps key is pressed
*/
int Caps_check(mlx_t *mlx)
{
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT_SHIFT) || mlx_is_key_down(mlx, MLX_KEY_CAPS_LOCK))
		return(-1);
	return(1);
}

/*

*/
void	hook(void *param)// can use this to  spin things around
{
	t_all_structs *a_s;

	a_s = param;

	double boost;
	boost =1;

	

	if (mlx_is_key_down(a_s->mlx, MLX_KEY_ESCAPE))// this stays
		mlx_close_window(a_s->mlx);
	if (mlx_is_key_down(a_s->mlx, MLX_KEY_UP))
		a_s->input->input7-= boost* 10;
	if (mlx_is_key_down(a_s->mlx, MLX_KEY_DOWN))
		a_s->input->input7+= 10;
	if (mlx_is_key_down(a_s->mlx, MLX_KEY_LEFT))
		a_s->input->input8-= 10;
	if (mlx_is_key_down(a_s->mlx, MLX_KEY_RIGHT))
		a_s->input->input8+= 10;
	if (mlx_is_key_down(a_s->mlx, MLX_KEY_A))
		a_s->input->input0 += boost * Caps_check(a_s->mlx);
	if (mlx_is_key_down(a_s->mlx, MLX_KEY_S))
		a_s->input->input1 += boost *Caps_check(a_s->mlx);
	if (mlx_is_key_down(a_s->mlx, MLX_KEY_D))
		a_s->input->input2 += boost *Caps_check(a_s->mlx);
	if (mlx_is_key_down(a_s->mlx, MLX_KEY_F))
		a_s->input->input3 += boost *Caps_check(a_s->mlx);
	if (mlx_is_key_down(a_s->mlx, MLX_KEY_1))
		a_s->input->input4 += boost *Caps_check(a_s->mlx);
	if (mlx_is_key_down(a_s->mlx, MLX_KEY_2))
		a_s->input->input5 += boost *Caps_check(a_s->mlx);
	if (mlx_is_key_down(a_s->mlx, MLX_KEY_3))
		a_s->input->input6 += boost *Caps_check(a_s->mlx);

		
	//a_s->mtx_p->f_print(a_s->mtx_p);
	//printf("before set_matrices\n");
	set_the_matrices(a_s);
	ft_bzero(a_s->img->pixels,(a_s->img->width * a_s->img->height));
	//printf("before map_to_screen\n");
	// a_s->mtx_p->f_print(a_s->mtx_p);
	// a_s->mtx_z->f_print(a_s->mtx_z);
	// a_s->mtx_y->f_print(a_s->mtx_y);
	// a_s->mtx_x->f_print(a_s->mtx_x);
	map_to_screen(a_s);
	//print_screen(a_s->map);
	//printf("before draw_on_screen\n");
	if (mlx_is_key_down(a_s->mlx, MLX_KEY_TAB))
	{
		printf("scale matrix \n");
		a_s->mtx_s->f_print(a_s->mtx_s);
		printf("z rotation matrix \n");
		a_s->mtx_z->f_print(a_s->mtx_z);
		printf("y rotation matrix \n");
		a_s->mtx_y->f_print(a_s->mtx_y);
		printf("x rotation matrix \n");
		a_s->mtx_x->f_print(a_s->mtx_x);
		printf("projection matrix \n");
		a_s->mtx_p->f_print(a_s->mtx_p);
		print_screen(a_s->map);
	}
		draw_on_screen(a_s->map, a_s->img);
}

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
	funktion to start the loob and open the window
*/
int32_t	mlx_main(t_all_structs *a_s)
{
	a_s->mlx = mlx_init(WIDTH, HEIGHT, "FDF", true);
	if (!a_s->mlx)
		exit(EXIT_FAILURE);// need safe release
	a_s->img = mlx_new_image(a_s->mlx, WIDTH, HEIGHT);// need to safe width and heigth in to struct
	mlx_image_to_window(a_s->mlx, a_s->img, 0, 0);
	mlx_loop_hook(a_s->mlx, &hook, a_s);
	//printf("before mlx_loop\n");
	//a_s->mtx_s->f_print(a_s->mtx_s);
	mlx_loop(a_s->mlx);
	mlx_terminate(a_s->mlx);
	return (EXIT_SUCCESS);
}
double convert_cords_back(double cur_p, unsigned max,int zoom)
{
	//printf(">>%f\n",cur_p);
	return((int)(cur_p));	
}
	
/*
	rotaion and transformation of each cordinate
*/
void	vector_transform(t_all_structs *a_s,int cur_x, int cur_y)
{
	double	tmp_a[4];
	double	tmp_b[4];

	matrix_multiply_vector(a_s->mtx_s,a_s->map->position[cur_y][cur_x]->cords,4,tmp_b);
	matrix_multiply_vector(a_s->mtx_z,tmp_b,4,tmp_a);
	matrix_multiply_vector(a_s->mtx_y,tmp_a,4,tmp_b);
	matrix_multiply_vector(a_s->mtx_x,tmp_b,4,tmp_a);
	matrix_multiply_vector(a_s->mtx_p,tmp_a,4,tmp_b);// if(a_s->map->position[cur_y][cur_x]->screen[3] == 0)
	a_s->map->position[cur_y][cur_x]->screen[0] = convert_cords_back(tmp_b[0],WIDTH,1);
	a_s->map->position[cur_y][cur_x]->screen[1] = convert_cords_back(tmp_b[1],HEIGHT,1);
	//print_screen(a_s->map);
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
	frees all the stuff that was allocated in the beginnig
*/
void free_before_end(t_all_structs *a_s)
{
	a_s->mtx_p->f_delete_matrix(a_s->mtx_s);
	a_s->mtx_p->f_delete_matrix(a_s->mtx_x);
	a_s->mtx_p->f_delete_matrix(a_s->mtx_y);
	a_s->mtx_p->f_delete_matrix(a_s->mtx_z);
	a_s->mtx_p->f_delete_matrix(a_s->mtx_p);
	free_map(a_s->map);
}

/*
	setup for my matrices
	creates 4 4x4 matrices
*/
t_matrix_obj	*matrix_setup(t_matrix_obj *mtx)
{
	construct_matrix_obj(mtx);
	mtx->f_create(mtx,4,4);
	return(mtx);
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
	mtx_s.f_print(&mtx_s);
	// print_map(&map);
	// printf("-------\n\n\n");
	mlx_main(&a_s);
	free_before_end(&a_s);
	return(0);
}
