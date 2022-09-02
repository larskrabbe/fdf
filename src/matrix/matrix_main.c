
#include	"matrix_o.h"
int	*matrix_multiply_vector(struct s_matrix_obj *matrix, int *vector, unsigned vec_len,int *result);

// main for testing my matrix class
int	main()
{
	ft_printf("start\n");
	int int_array[] = {1,2,3,4,5,};
	int vec[] = {3,3,3,3};
	int result[10];
	t_matrix_obj matrix_a;
	
	construct_matrix_obj(&matrix_a);
	
	matrix_a.f_create(&matrix_a,4,5);
	matrix_a.f_set_single(&matrix_a,2,0,1);
	matrix_a.f_set_row(&matrix_a,int_array,0);
	matrix_a.f_set_column(&matrix_a,int_array,2);
	matrix_a.f_print(&matrix_a);
	matrix_a.f_set_single(&matrix_a,2,3,(matrix_a.f_get_single(&matrix_a,2,3) + 4));
	matrix_a.f_delete_matrix(&matrix_a);
	matrix_multiply_vector(&matrix_a,vec,4,result);
	int i = 0;
	while(i <= 4)
	{
		ft_printf("|%i|\n",result[i]); 
		i++;
	}
	printf("end\n");
	return(0);
}