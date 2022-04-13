/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:27:29 by agrenon           #+#    #+#             */
/*   Updated: 2022/04/06 18:06:10 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push.h"

int	ft_tab_len(char **argv)
{
	int		i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

void	ft_set_range(t_data_piles *data)
{
	if (data->t_turn == true)
	{
		data->from_a = data->range_low;
		data->from_b = data->range_low + data->range;
	}
	else
	{
		data->from_a = data->range_up - data->range;
		data->from_b = data->range_up;
	}
	return ;
}

void	ft_set_info_value(t_data_piles *data)
{
	t_assiette	*begin;

	data->frst_a = INT_MAX;
	data->sec_a = INT_MAX;
	data->las_a = INT_MAX;
	if (data->top_a)
	{
		data->frst_a = data->top_a->value;
		if (data->top_a->next)
		{
			data->sec_a = data->top_a->next->value;
			begin = data->top_a;
			while (begin)
			{
				if (begin->next == NULL)
					data->las_a = begin->value;
				begin = begin->next;
			}
		}
	}
	return ;
}

void	ft_set_info(t_data_piles *data)
{
	t_assiette	*begin;

	ft_set_info_value(data);
	ft_set_range(data);
	data->frst_b = INT_MIN;
	data->sec_b = INT_MIN;
	data->las_b = INT_MIN;
	if (data->top_b)
	{
		data->frst_b = data->top_b->value;
		if (data->top_b->next)
		{
			data->sec_b = data->top_b->next->value;
			begin = data->top_b;
			while (begin)
			{
				if (begin->next == NULL)
					data->las_b = begin->value;
				begin = begin->next;
			}
		}
	}
	return ;
}
