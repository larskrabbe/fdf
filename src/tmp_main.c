#include "../include/fdf.h"

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;

// 	mlx = mlx_init(); // init the 'mlx'pointer necessarry for the funktion of mlxlib
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!"); // create a window with title "Hello World"
// 	mlx_loop(mlx); // 'starts' the window 
// }


// int	main(void)
// {
// 	void	*img;
// 	void	*mlx;

// 	mlx = mlx_init();
// 	img = mlx_new_image(mlx, 1920, 1080); // create a buffer image before we push it to the window
// }

// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

// int	main(void)
// {
// 	void	*mlx;
// 	t_data	img;

// 	mlx = mlx_init();
// 	img.img = mlx_new_image(mlx, 1920, 1080);// need to create tmp windows,  so window  tearing doenst happend

// 	/*
// 	** After creating an image, we can call `mlx_get_data_addr`, we pass
// 	** `bits_per_pixel`, `line_length`, and `endian` by reference. These will // need to look in to it // dont know why i need to parse it by adress  or at all // and not calling just the struct ???????
// 	** then be set accordingly for the *current* data address.
// 	*/
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 								&img.endian);
// }
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_point{

	int	color;
	
}t_point;


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}



int	main(int argc, char** argv)
{
	// void	*mlx;
	// void	*mlx_win;
	// t_data	img;

	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 1920, 1080, "FDF The Wireframe");
	// img.img = mlx_new_image(mlx, 1920, 1080);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,&img.endian);
	// int k =0;
	// int j =0;
	if (argc <= 1)
		return(0);
	t_map *map;
	map = ft_calloc(sizeof(t_map),1);
	convert_map(argv[1],map);//need to free it latter
	print_map(map);
	free_map(map);
	//print_cords(map);
	// while(j <1000)
	// {
	// 	while (k < 1000)
	// 	{
	// 		if(k%2 == 1)
	// 			my_mlx_pixel_put(&img, k, j, 0x00FF0000);
	// 		else
	// 			my_mlx_pixel_put(&img, k, j, 0xf8f8ff);
	// 		k++;
	// 	}
	// 	k = 0;
	// 	j++;
	// }
	//my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	//mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	//mlx_loop(mlx);
	// char str[] = "  ";

	// ft_printf("%i",count_words_in_str(str,' '));
	
}

