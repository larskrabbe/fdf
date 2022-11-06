/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:53:26 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/11/05 19:02:47 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/fdf.h"

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
