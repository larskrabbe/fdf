/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:53:26 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/11/01 20:50:36 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/fdf.h"

/*
	set the default value inside myinput struct
*/
t_input	*default_input(t_input *input)
{
	input->input[x_scale] = 300;
	input->input[y_scale] = 300;
	input->input[z_scale] = 0;
	input->input[w_scale] = 1;
	input->input[x_rotation] = 0;
	input->input[y_rotation] = 0;
	input->input[z_rotation] = 0;
	input->input[x_translation] = WIDTH / 2;
	input->input[y_translation] = HEIGHT / 2;
	input->input[red] = 12;
	input->input[green] = 12;
	input->input[blue] = 12;
	input->input[opacity] = 12;
	return (input);
}

/*
	set the value for the projection matrix
*/
void	set_the_s_matrix(double **matrix, t_input *input)
{
	matrix[0][0] = input->input[x_scale];
	matrix[1][1] = input->input[y_scale];
	matrix[2][2] = input->input[z_scale];
}

/*
	set the value for the projection matrix
*/
void	set_the_p_matrix(double **matrix, t_input *input)
{
	matrix[0][3] = input->input[x_translation];
	matrix[1][3] = input->input[y_translation];
}

/*
	set the value for the projection matrix
*/
void	set_the_x_matrix(double **matrix, double value)
{
	matrix[1][1] = cos(value);
	matrix[1][2] = -sin(value);
	matrix[2][1] = sin(value);
	matrix[2][2] = cos(value);
}

/*
	set the value for the y_rotation matrix
*/
void	set_the_y_matrix(double **matrix, double value)
{
	matrix[0][0] = cos(value);
	matrix[0][2] = sin(value);
	matrix[2][0] = -sin(value);
	matrix[2][2] = cos(value);
}

/*
	set the value for the z_rotaion matrix
*/
void	set_the_z_matrix(double **matrix, double value)
{
	matrix[0][0] = cos(value);
	matrix[0][1] = -sin(value);
	matrix[1][0] = sin(value);
	matrix[1][1] = cos(value);
}

/*
	set the values inside all matrices
*/
void	set_the_matrices(t_all_structs *a_s)
{
	set_the_s_matrix(a_s->mtx_s->matrix, a_s->input);
	set_the_x_matrix(a_s->mtx_x->matrix, a_s->input->input[x_rotation]);
	set_the_y_matrix(a_s->mtx_y->matrix, a_s->input->input[y_rotation]);
	set_the_z_matrix(a_s->mtx_z->matrix, a_s->input->input[z_rotation]);
	set_the_p_matrix(a_s->mtx_p->matrix, a_s->input);
}
