/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_support.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:47:49 by agrenon           #+#    #+#             */
/*   Updated: 2022/03/25 17:46:36 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push.h"

void	ft_pushn_swap(t_data_piles *data)
{
	ft_push(data, 'b');
	ft_set_info(data);
	if (!data->t_turn)
	{
		if (data->top_b->next && data->sec_b > data->frst_b)
			ft_swap_flag(data, 'b');
		data->shuffle++;
	}
	return ;
}

void	ft_sortb_npush(t_data_piles *data)
{
	int	i;

	i = 0;
	if (!data->t_turn)
	{
		ft_algo_b(data);
		while (i++ < data->len_b_init)
			ft_push(data, 'a');
		data->t_turn = true;
		data->range_up = data->from_a;
	}
	else
	{
		ft_algo_bswitch(data);
		while (i++ < data->len_b_init)
		{
			ft_push(data, 'a');
			ft_rotate_flag(data, 'a');
		}
		data->t_turn = false;
		data->range_low = data->from_b;
	}
	return ;
}

void	ft_evrday_im_shuffling(t_data_piles *data)
{
	if (data->t_turn == true)
	{
		if (data->frst_b < data->las_b)
			ft_reverse_flag(data, 'r');
		else
			ft_reverse_flag(data, 'a');
		data->shuffle++;
	}
	else
	{
		if (data->frst_b > data->las_b)
			ft_rotate_flag(data, 'r');
		else
			ft_rotate_flag(data, 'a');
		data->shuffle++;
	}
	return ;
}
