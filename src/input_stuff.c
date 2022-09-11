/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:53:26 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/09/11 17:00:55 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/fdf.h"

/*
	set the default value inside myinput struct
*/
t_input *default_input(t_input *input)
{
	int scale;

	input->input0  = 5;//x
	input->input1  = 5;//y
	input->input2  = 1;//z
	input->input3  = 1;//w
	input->input4  = 0;//x-rotation
	input->input5  = 0;//y-rotation
	input->input6  = 0;//z-rotation
	input->input7  = 200;//translation in x
	input->input8  = 200;//translation in y
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
void set_the_s_matrix(t_all_structs *a_s)
{
	a_s->mtx_s->matrix[0][0]= a_s->input->input0;
	a_s->mtx_s->matrix[0][1]= 0;
	a_s->mtx_s->matrix[0][2]= 0;
	a_s->mtx_s->matrix[0][3]= 0;
	a_s->mtx_s->matrix[1][0]= 0;
	a_s->mtx_s->matrix[1][1]= a_s->input->input1;
	a_s->mtx_s->matrix[1][2]= 0;
	a_s->mtx_s->matrix[1][3]= 0;	
	a_s->mtx_s->matrix[2][0]= 0;
	a_s->mtx_s->matrix[2][1]= 0;
	a_s->mtx_s->matrix[2][2]= a_s->input->input2;
	a_s->mtx_s->matrix[2][3]= 0;
	a_s->mtx_s->matrix[3][0]= 0;
	a_s->mtx_s->matrix[3][1]= 0;
	a_s->mtx_s->matrix[3][2]= 0;
	a_s->mtx_s->matrix[3][3]= 1;
	
}
/*
	set the value for the projection matrix
*/
void set_the_p_matrix(t_all_structs *a_s)
{
	a_s->mtx_p->matrix[0][0]= 1;
	a_s->mtx_p->matrix[0][1]= 0;
	a_s->mtx_p->matrix[0][2]= 0;
	a_s->mtx_p->matrix[0][3]= a_s->input->input7;
	a_s->mtx_p->matrix[1][0]= 0;
	a_s->mtx_p->matrix[1][1]= 1;
	a_s->mtx_p->matrix[1][2]= 0;
	a_s->mtx_p->matrix[1][3]= a_s->input->input8;	
	a_s->mtx_p->matrix[2][0]= 0;
	a_s->mtx_p->matrix[2][1]= 0;
	a_s->mtx_p->matrix[2][2]= 1;
	a_s->mtx_p->matrix[2][3]= 0;
	a_s->mtx_p->matrix[3][0]= 0;
	a_s->mtx_p->matrix[3][1]= 0;
	a_s->mtx_p->matrix[3][2]= 0;
	a_s->mtx_p->matrix[3][3]= 1;
	
}

/*
	set the value for the projection matrix
*/
void set_the_x_matrix(t_all_structs *a_s)
{
	a_s->mtx_x->matrix[0][0]= 1;
	a_s->mtx_x->matrix[0][1]= 0;
	a_s->mtx_x->matrix[0][2]= 0;
	a_s->mtx_x->matrix[0][3]= 0;
	a_s->mtx_x->matrix[1][0]= 0;
	a_s->mtx_x->matrix[1][1]= cos(a_s->input->input4 / 10 * 10);
	a_s->mtx_x->matrix[1][2]= -sin(a_s->input->input4 / 10 * 10);
	a_s->mtx_x->matrix[1][3]= 0;	
	a_s->mtx_x->matrix[2][0]= 0;
	a_s->mtx_x->matrix[2][1]= sin(a_s->input->input4 / 10 * 10);
	a_s->mtx_x->matrix[2][2]= cos(a_s->input->input4 / 10 * 10);
	a_s->mtx_x->matrix[2][3]= 0;
	a_s->mtx_x->matrix[3][0]= 0;
	a_s->mtx_x->matrix[3][1]= 0;
	a_s->mtx_x->matrix[3][2]= 0;
	a_s->mtx_x->matrix[3][3]= 1;
}

/*
	set the value for the y_rotation matrix
*/
void set_the_y_matrix(t_all_structs *a_s)
{
	a_s->mtx_y->matrix[0][0]= cos(a_s->input->input5);
	a_s->mtx_y->matrix[0][1]= 0;
	a_s->mtx_y->matrix[0][2]= sin(a_s->input->input5);
	a_s->mtx_y->matrix[0][3]= 0;
	a_s->mtx_y->matrix[1][0]= 0;
	a_s->mtx_y->matrix[1][1]= 1;
	a_s->mtx_y->matrix[1][2]= 0;
	a_s->mtx_y->matrix[1][3]= 0;	
	a_s->mtx_y->matrix[2][0]= -sin(a_s->input->input5);
	a_s->mtx_y->matrix[2][1]= 0;
	a_s->mtx_y->matrix[2][2]= cos(a_s->input->input5);
	a_s->mtx_y->matrix[2][3]= 0;
	a_s->mtx_y->matrix[3][0]= 0;
	a_s->mtx_y->matrix[3][1]= 0;
	a_s->mtx_y->matrix[3][2]= 0;
	a_s->mtx_y->matrix[3][3]= 1;
}

/*
	set the value for the z_rotaion matrix
*/
void set_the_z_matrix(t_all_structs *a_s)
{
	a_s->mtx_z->matrix[0][0]= cos(a_s->input->input6 / 10 * 10);
	a_s->mtx_z->matrix[0][1]= -sin(a_s->input->input6 / 10 * 10);
	a_s->mtx_z->matrix[0][2]= 0;
	a_s->mtx_z->matrix[0][3]= 0;
	a_s->mtx_z->matrix[1][0]= sin(a_s->input->input6 / 10 * 10);
	a_s->mtx_z->matrix[1][1]= cos(a_s->input->input6 / 10 * 10);
	a_s->mtx_z->matrix[1][2]= 0;
	a_s->mtx_z->matrix[1][3]= 0;
	a_s->mtx_z->matrix[2][0]= 0;
	a_s->mtx_z->matrix[2][1]= 0;
	a_s->mtx_z->matrix[2][2]= 1;
	a_s->mtx_z->matrix[2][3]= 0;
	a_s->mtx_z->matrix[3][0]= 0;
	a_s->mtx_z->matrix[3][1]= 0;
	a_s->mtx_z->matrix[3][2]= 0;
	a_s->mtx_z->matrix[3][3]= 1;
}


void set_the_matrices(t_all_structs *a_s)
{
	set_the_s_matrix(a_s);
	set_the_x_matrix(a_s);
	set_the_y_matrix(a_s);
	set_the_z_matrix(a_s);
	set_the_p_matrix(a_s);
}
