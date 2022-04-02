#include "lib_push.h" 

// PRINT FUNCTIONS
// printf("Shuffle max: %ld\n Shuffle: %ld\n", data->shuffle_max, da    ta->shuffle);
 //printf("data->range : %ld argc: %d\n", data->range, argc - 1);
 //printf("From_a : %ld from_b: %ld\n", data->from_a, data->from_b);
 //printf("data->range : %ld argc: %d\n", data->range, argc - 1);
 //printf("Min: %ld\n Max: %ld\n", data->min, data->max);


int	main(int argc, char **argv)
{
	t_data_piles *data;

	data = ft_stack_create(argv, argc);
	if (!data)
		return (0);
//	printf("\n FULL STACK BEGIN A \n");
//	ft_print_all_lst(data->top_a);
	//printf("\n OPERATIONS: \n");
	//if (argc > 2)
	//ft_algo_a(data);

	ft_thinking(data);
	
/*	if (argc < 30)		
		ft_algo_a(data);
	else	
		ft_algo_master(data);
*/
	printf("\n-FIN FIN --- Pile a \n");
	ft_print_all_lst(data->top_a);
	printf("\nNOMBRE OPÉRATIONS: %ld\n  \n", data->op_count);
	printf("\n Vrai : %d\n  \n", ft_is_align(data->top_a, false));
	

	ft_destroy_stacks(data); //free
	return(0);
}
