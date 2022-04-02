#include "lib_push.h" 



void	ft_three(t_data_piles *data)
{
	ft_set_info(data);
	//if (ft_is_align(data->top_a, true) == false)
	//	return ;
	if (data->las_a < data->frst_a && data->sec_a < data->frst_a)
		ft_rotate_flag(data, 'a');
	else if (data->las_a < data->sec_a && data->sec_a < data->frst_a)
		ft_reverse_flag(data, 'a');	
	else if (data->frst_a > data->las_a)
		ft_rotate_flag(data, 'a');
	else if (data->frst_a > data->sec_a)
		ft_swap_flag(data, 'a');
	else 
		return;	
	ft_three(data);
}

void	ft_thinking(t_data_piles *data)
{

	ft_three(data);
	return ;
}
