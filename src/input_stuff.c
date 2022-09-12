/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:53:26 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/09/12 15:10:18 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/fdf.h"

/*
	set the default value inside myinput struct
*/
t_input *default_input(t_input *input)
{
	int scale;

	input->input0  = 500;//x
	input->input1  = 500;//y
	input->input2  = 1;//z
	input->input3  = 1;//w
	input->input4  = 0;//x-rotation
	input->input5  = 0;//y-rotation
	input->input6  = 0;//z-rotation
	input->input7  = WIDTH/2;//translation in x
	input->input8  = HEIGHT/2;//translation in y
	input->input9  = 0;
	input->input10 = 0;
	input->input11 = 0;
	input->input12 = 0;
	input->input13 = 0;
	input->input14 = 0;
	input->input15 = 0;
	return(input);
}

/*
	set the value for the projection matrix
*/
void set_the_s_matrix(double **matrix,t_input *input)
{
	matrix[0][0]= input->input0;
	matrix[1][1]= input->input1;
	matrix[2][2]= input->input2;
	matrix[3][3]= input->input3;

	
}
/*
	set the value for the projection matrix
*/
void set_the_p_matrix(double **matrix,t_input *input)
{
	matrix[0][0]= 1;
	matrix[0][1]= 0;
	matrix[0][2]= 0;
	matrix[0][3]= input->input7;
	matrix[1][0]= 0;
	matrix[1][1]= 1;
	matrix[1][2]= 0;
	matrix[1][3]= input->input8;	
	matrix[2][0]= 0;
	matrix[2][1]= 0;
	matrix[2][2]= 1;
	matrix[2][3]= 0;
	matrix[3][0]= 0;
	matrix[3][1]= 0;
	matrix[3][2]= 0;
	matrix[3][3]= 1;
	
}

/*
	set the value for the projection matrix
*/
void set_the_x_matrix(double **matrix, double value)
{
	matrix[1][1]= cos(value );
	matrix[1][2]= -sin(value) ;
	matrix[2][1]= sin(value );
	matrix[2][2]= cos(value );
}

/*
	set the value for the y_rotation matrix
*/
void set_the_y_matrix(double **matrix, double value)
{
	matrix[0][0]= cos(value);
	matrix[0][2]= sin(value);
	matrix[2][0]= -sin(value);
	matrix[2][2]= cos(value);
}

/*
	set the value for the z_rotaion matrix
*/
void set_the_z_matrix(double **matrix, double value)
{
	matrix[0][0]= cos(value);
	matrix[0][1]= -sin(value);
	matrix[1][0]= sin(value);
	matrix[1][1]= cos(value);
}

/*
	set the values inside all matrices
*/
void set_the_matrices(t_all_structs *a_s)
{
	set_the_s_matrix(a_s->mtx_s->matrix,a_s->input);
	set_the_x_matrix(a_s->mtx_x->matrix,a_s->input->input4);
	set_the_y_matrix(a_s->mtx_y->matrix,a_s->input->input5);
	set_the_z_matrix(a_s->mtx_z->matrix,a_s->input->input6);
	set_the_p_matrix(a_s->mtx_p->matrix,a_s->input);
}
