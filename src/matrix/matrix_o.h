/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_o.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:37:38 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/08/31 20:30:21 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MATRIX_O_H
# define MATRIX_O_H

//*************************LIBARYS*********************************************

# include	"../../include/fdf.h"//need to change for later projects

//*************************STRUCTURE*******************************************

/*
	Main structure for my  class
	create a m*n matrix
	is able to change the value of  single value or whole line
	need to be able to calculate with other matrixs
*/


	//-----------CLASS-------
	typedef struct	s_matrix_obj{ 

	//----------OBJECTS------
	int			**matrix;// maybe import this ina separte struct // like a sup class
	
	//---------PROPERTIES--------
	// not sure here... because i will need them  to create the base matrix
	unsigned 	rows;// maybe import this ina separte struct
	unsigned 	columns;// maybe import this ina separte struct

	//---------METHODS--------
	//setup
	int			**(*f_create)(struct s_matrix_obj *matrix, unsigned rows,unsigned columns);
	void		(*f_delete_matrix)(struct s_matrix_obj *matrix);
	
	//utiles
	void		(*f_print)(struct s_matrix_obj *matrix);
	void 		(*f_set_to_null)(struct s_matrix_obj *matrix);
	
	//setter
	void		(*f_set_single)(struct s_matrix_obj *matrix, unsigned row, unsigned column,int value);
	void		(*f_set_row)(struct s_matrix_obj *matrix, int *new_values, unsigned t_row);
	void		(*f_set_column)(struct s_matrix_obj *matrix, int *new_values, unsigned t_column);
	
	//getter
	int			(*f_get_single)(struct s_matrix_obj *matrix, unsigned column,unsigned row);
	int			*(*f_get_row)(struct s_matrix_obj *matrix,unsigned t_row);
	int			*(*f_get_column)(struct s_matrix_obj *matrix,unsigned t_column);
	int			**(*f_get_matrix)(struct s_matrix_obj *matrix);
	
	
	//void		(*f_change_row)(unsigned row,int *values); // no reason to do this yet,
	//void		(*f_change_column)(unsigned column,int *values); // no reason to do this yet,
	//void		(*f_copy_matrix)
	//TYPE		*(*f_return_as_vetor)(int** matrix);
	void		(*f_solve_matrix)(struct s_matrix_obj *matrix);//do i need it right now
	
	
}t_matrix_obj;


//***************************PROTOTYPES****************************************


//------matrixsetup.c

//Constructor for my 'Class'
void	construct_matrix_obj(t_matrix_obj *matrix);

// frees a specic amount of arrays and the pointer that points to it //not in the constructer
void	*free_arrays(int **ptr, unsigned n);

//create the matrix(int [columns][rows]) will be stored in the heap
int		**create_matrix(struct s_matrix_obj *matrix, unsigned rows,unsigned columns);

// frees the whole matrix 
void	delete_matrix(t_matrix_obj *matrix);

//------matrix_utils.c

//prints the whole matrix //works only good for small number values
void	print_matrix(t_matrix_obj *matrix);

// set every value inside the matrix to 0 // will be change later to a value form the parameter
void 	null_matrix(struct s_matrix_obj *matrix);

//------matrix_setter.c

// change a single value of the matrix
void	set_sinlge_value(struct s_matrix_obj *matrix, unsigned row,unsigned column,int value);

//change the target row to the value of the array
void	set_whole_row(struct s_matrix_obj *matrix, int *new_values, unsigned t_row);

//change the target row to the value of the array
void	set_whole_coloumn(struct s_matrix_obj *matrix, int *new_values, unsigned t_column);

//------matrix_getter.c

//return a single value of the matrix
int		get_single_value(struct s_matrix_obj *matrix, unsigned column, unsigned row);

//returns a allocated and copied array  of target row
int		*get_single_row(struct s_matrix_obj *matrix,unsigned t_row);

//returns a allocated and copied array  of target row
int		*get_single_column(struct s_matrix_obj *matrix,unsigned t_column);

//returns a allocated copy of the matrix
int 	**get_matrix_copy(struct s_matrix_obj *matrix);





#endif

//**************************TO DO**************************************
// struct test
// {
// 	union {
// 		int a;
// 		double b:	
// 	};
// 	int i;
// };

// struct test idk;
// idk.a
//	To Do
//	- Need to work for not just ints atleast doubles or kust doubles
//	- adding math:
//		- plus // can do it like this for now >>>> set = get + n
//		- minus 
//		- divide
//		- multiply
//		- auto solve??
//		- need to work for single values and for whole rows or columns
//		- 