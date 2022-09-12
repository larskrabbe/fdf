/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_stuff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:44:36 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/09/12 15:51:23 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/fdf.h"

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
	converts the
*/
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
	a_s->map->position[cur_y][cur_x]->screen[0] = (int)tmp_b[0];
	a_s->map->position[cur_y][cur_x]->screen[1] = (int)tmp_b[1];
	//print_screen(a_s->map);
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
	free_map(a_s->map,a_s->map->max_x,a_s->map->max_y);
}
