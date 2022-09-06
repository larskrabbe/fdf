/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:15:15 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/09/06 20:23:28 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include	

// #define WIDTH 256 * 20
// #define HEIGHT 256 * 20


// // void	hook(void *param, void *param2)
// // {
// // 	mlx_t	*mlx;

// // 	mlx = param;
// // 	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
// // 		mlx_close_window(param);
// // 	if (mlx_is_key_down(param, MLX_KEY_UP))
// // 		g_img->instances[0].y -= 5;
// // 	if (mlx_is_key_down(param, MLX_KEY_DOWN))
// // 		g_img->instances[0].y += 5;
// // 	if (mlx_is_key_down(param, MLX_KEY_LEFT))
// // 		g_img->instances[0].x -= 5;
// // 	if (mlx_is_key_down(param, MLX_KEY_RIGHT))
// // 		g_img->instances[0].x += 5;
// // }git

// void	draw_on_screen(t_map *map,mlx_image_t *img)
// {
// 	int	c_y = 0;
// 	int	c_x = 0;
// 	while(map->max_y > c_y )
// 	{
// 		while(map->max_x > c_x)
// 		{
// 			//printf("y %i x %i map x %i map y %i \n",c_y, c_x,map->position[c_y][c_x]->cords[1],map->position[c_y][c_x]->cords[0]);
// 			if(c_x + 1< map->max_x)
// 				drawline(map->position[c_y][c_x],map->position[c_y][c_x + 1],img);
// 			if(c_y + 1 < map->max_y)
// 				drawline(map->position[c_y][c_x],map->position[c_y + 1][c_x],img);
// 			c_x++;
// 		}
// 		c_x = 0;
// 		c_y++;
// 	}
// }

// int32_t	mlx_main(t_map *map, t_input *input)
// {
// 	mlx_t	*mlx;
// 	mlx_image_t *img;

// 	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", false);
// 	if (!mlx)
// 		exit(EXIT_FAILURE);
// 	img = mlx_new_image(mlx, WIDTH, HEIGHT);
// 	g_img = img;

// 	draw_on_screen(map, img);
// 	mlx_image_to_window(mlx, g_img, 50, 50);
// 	mlx_loop_hook(mlx, &hook, mlx, input);
// 	mlx_loop(mlx);

// 	mlx_terminate(mlx);
// 	return (EXIT_SUCCESS);
// }

