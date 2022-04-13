/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:46:38 by agrenon           #+#    #+#             */
/*   Updated: 2022/04/07 10:41:10 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push.h"

void	ft_algo_master(t_data_piles *data)
{
	ft_set_info(data);
	if (ft_is_align(data->top_a, false) && !data->top_b)
		return ;
	else if (data->range_low > data->range_up && !data->top_b)
		ft_reverse_flag(data, 'a');
	else if (data->frst_a >= data->from_a && data->frst_a <= data->from_b)
		ft_pushn_swap(data);
	else if (data->shuffle < data->shuffle_max)
		ft_evrday_im_shuffling(data);
	else if (data->len_b > 0)
	{
		data->len_b_init = data->len_b;
		ft_sortb_npush(data);
		data->shuffle_max = data->shuffle - data->len_b_init;
		data->shuffle = 0;
	}
	else
		return ;
	ft_algo_master(data);
	return ;
}

void	ft_algo_bswitch(t_data_piles *data)
{
	int	p;

	ft_set_info(data);
	p = data->len_b_init - data->len_b;
	if (data->las_b < data->frst_b && data->las_b < data->sec_b)
		ft_reverse_flag(data, 'b');
	else if (data->frst_a < data->sec_a && data->frst_b > data->sec_b && p > 1)
		ft_swap_flag(data, 's');
	else if (data->frst_b > data->sec_b && data->top_b->next)
		ft_swap_flag(data, 'b');
	else if (data->frst_b > data->las_b && data->top_b->next)
		ft_rotate_flag(data, 'b');
	else if (ft_is_align(data->top_b, false) == false)
		ft_push(data, 'a');
	else if (data->len_b < data->len_b_init)
		ft_push(data, 'b');
	else
		return ;
	ft_algo_bswitch(data);
	return ;
}

void	ft_algo_b(t_data_piles *data)
{
	int	p;

	p = data->len_b_init - data->len_b;
	ft_set_info(data);
	if (data->las_b > data->frst_b && data->las_b > data->sec_b)
		ft_reverse_flag(data, 'b');
	else if (data->frst_a > data->sec_a && data->frst_b < data->sec_b && p > 1)
		ft_swap_flag(data, 's');
	else if (data->frst_b < data->sec_b)
		ft_swap_flag(data, 'b');
	else if (data->frst_b < data->las_b)
		ft_rotate_flag(data, 'b');
	else if (ft_is_align(data->top_b, true) == false)
		ft_push(data, 'a');
	else if (data->len_b < data->len_b_init)
		ft_push(data, 'b');
	else
		return ;
	ft_algo_b(data);
	return ;
}

void	ft_algo_a(t_data_piles *data)
{
	ft_set_info(data);
	if (data->frst_a > data->las_a && data->frst_b < data->las_b && data->top_b)
		ft_reverse_flag(data, 'r');
	else if (data->frst_a > data->las_a && data->las_a < data->sec_a)
		ft_reverse_flag(data, 'a');
	else if (data->frst_b < data->las_b && data->las_b >= data->sec_b)
		ft_reverse_flag(data, 'b');
	else if (data->frst_a > data->sec_a)
		ft_swap_flag(data, 'a');
	else if (data->frst_b < data->sec_b)
		ft_swap_flag(data, 'b');
	else if (data->frst_a > data->las_a)
		ft_rotate_flag(data, 'a');
	else if (data->frst_b < data->las_b)
		ft_rotate_flag(data, 'b');
	else if (ft_is_align(data->top_a, false) == false)
		ft_push(data, 'b');
	else if (data->top_b)
		ft_push(data, 'a');
	else
		return ;
	ft_algo_a(data);
}
