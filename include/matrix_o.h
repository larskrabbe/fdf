/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_o.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:37:38 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/11/06 18:32:18 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_O_H
# define MATRIX_O_H

//*************************LIBARYS*********************************************

# include	"libft.h"//need to change for later projects

//*************************STRUCTURE*******************************************

typedef struct s_matrix_obj{
	double			**matrix;
	unsigned int	rows;
	unsigned int	columns;
	double			**(*f_create)(struct s_matrix_obj *matrix, \
	unsigned rows, unsigned columns);
	void			(*f_delete_matrix)(struct s_matrix_obj *matrix);
	void			(*f_print)(struct s_matrix_obj *matrix);
	void			(*f_set_to_null)(struct s_matrix_obj *matrix);
	void			(*f_set_single)(struct s_matrix_obj *matrix, \
	unsigned row, unsigned column, double value);
	void			(*f_set_row)(struct s_matrix_obj *matrix, \
	double *new_values, unsigned int t_row);
	void			(*f_set_column)(struct s_matrix_obj *matrix, \
	double *new_values, unsigned int t_column);
	double			*(*f_get_row)(struct s_matrix_obj *matrix, unsigned t_row);
	double			*(*f_get_column)(struct s_matrix_obj *matrix, \
	unsigned t_column);
	double			(*f_get_single)(struct s_matrix_obj *matrix, \
	unsigned column, unsigned row);
	double			**(*f_get_matrix)(struct s_matrix_obj *matrix);
	void			(*f_solve_matrix)(struct s_matrix_obj *matrix);
}t_matrix_obj;

//***************************PROTOTYPES****************************************

//------matrixsetup.c

//Constructor for my 'Class'
void	construct_matrix_obj(t_matrix_obj *matrix);

// frees a specic amount of arrays and the pointer that points to it
void	*free_arrays(double **ptr, unsigned int n);

//create the matrix(int [columns][rows]) will be stored in the heap
double	**create_matrix(struct s_matrix_obj *matrix, \
unsigned int rows, unsigned int columns);

// frees the whole matrix 
void	delete_matrix(t_matrix_obj *matrix);

//------matrix_utils.c

//prints the whole matrix //works only good for small number values
void	print_matrix(t_matrix_obj *matrix);

// set every value inside the matrix to 0 
void	null_matrix(struct s_matrix_obj *matrix);

//------matrix_setter.c

// change a single value of the matrix
void	set_sinlge_value(struct s_matrix_obj *matrix, \
unsigned row, unsigned column, double value);

//change the target row to the value of the array
void	set_whole_row(struct s_matrix_obj *matrix, \
double *new_values, unsigned int t_row);

//change the target row to the value of the array
void	set_whole_coloumn(struct s_matrix_obj *matrix, \
double *new_values, unsigned int t_column);

//------matrix_getter.c

//return a single value of the matrix
double	get_single_value(struct s_matrix_obj *matrix, \
unsigned column, unsigned row);

//returns a allocated and copied array  of target row
double	*get_single_row(struct s_matrix_obj *matrix, unsigned int t_row);

//returns a allocated and copied array  of target row
double	*get_single_column(struct s_matrix_obj *matrix, unsigned int t_column);

//returns a allocated copy of the matrix
double	**get_matrix_copy(struct s_matrix_obj *matrix);

void	matrix_multiply_vector(struct s_matrix_obj *matrix, double *vector, \
unsigned int vec_len, double *result);
#endif