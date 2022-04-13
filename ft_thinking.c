/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thinking.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:55:38 by agrenon           #+#    #+#             */
/*   Updated: 2022/04/02 16:56:56 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push.h" 

void	ft_only_three(t_data_piles *data)
{
	ft_set_info(data);
	if (data->las_a < data->frst_a && data->sec_a < data->frst_a)
		ft_rotate_flag(data, 'a');
	else if (data->las_a < data->sec_a && data->sec_a < data->frst_a)
		ft_reverse_flag(data, 'a');
	else if (data->frst_a > data->las_a)
		ft_rotate_flag(data, 'a');
	else if (data->frst_a > data->sec_a)
		ft_swap_flag(data, 'a');
	else
		return ;
	ft_only_three(data);
}
