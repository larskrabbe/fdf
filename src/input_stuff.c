/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe < lkrabbe@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:53:26 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/09/06 10:51:51 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/fdf.h"



// void default_input(t_input *input)
// {
// 	input->input0  = 1;
// 	input->input1  = 0;
// 	input->input2  = 0;
// 	input->input3  = 0;
// 	input->input4  = 0;
// 	input->input5  = 1;
// 	input->input6  = 0;
// 	input->input7  = 0;
// 	input->input8  = 0;
// 	input->input9  = 0;
// 	input->input10 = 1;
// 	input->input11 = 0;
// 	input->input12 = 0;
// 	input->input13 = 0;
// 	input->input14 = 0;
// 	input->input15 = 1;
// }

void set_the_matrix(t_matrix_obj *mat,t_map *map)
{
	int scale;

	scale = 5;
	mat->matrix[0][0]= 1 * scale ;
	mat->matrix[0][1]= 1 * scale ;
	mat->matrix[0][2]= 1  ;
	mat->matrix[1][1]= 1 * scale;
	mat->matrix[1][2]= 1 * scale;
	mat->matrix[2][2]= 1 ;
	mat->matrix[3][3]= 1;
}

// mlx_t	*get_s_mlx(void *param)
// {
// 	t_tmp_struct	*tmp;

// 	tmp = param;
// 	return(tmp->mlx);
// }

// t_input	*get_s_input(void *param)
// {
// 	t_tmp_struct	*tmp;

// 	tmp = param;
// 	return(tmp->input);
// }

// t_map	*get_s_map(void *param)
// {
// 	t_tmp_struct	*tmp;

// 	tmp = param;
// 	return(tmp->map);
// }
