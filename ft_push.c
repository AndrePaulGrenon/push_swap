/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:23:01 by agrenon           #+#    #+#             */
/*   Updated: 2022/03/30 16:41:22 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push.h"

void	ft_push_a(t_data_piles *data)
{
	t_assiette	*temp;

	temp = data->top_a;
	temp->previous = NULL;
	data->top_a = temp->next;
	temp->next = data->top_b;
	data->top_b = temp;
	if (temp->next)
		temp->next->previous = temp;
	if (data->top_a)
		data->top_a->previous = NULL;
	data->len_a--;
	data->len_b++;
	write(1, "pb\n", 3);
	return ;
}

void	ft_push_b(t_data_piles *data)
{
	t_assiette	*temp;

	temp = data->top_b;
	temp->previous = NULL;
	data->top_b = temp->next;
	temp->next = data->top_a;
	data->top_a = temp;
	if (temp->next)
		temp->next->previous = temp;
	if (data->top_b)
		data->top_b->previous = NULL;
	write(1, "pa\n", 3);
	data->len_a++;
	data->len_b--;
	return ;
}

void	ft_push(t_data_piles *data, char c)
{
	if (c == 'b')
	{
		if (data->top_a == NULL)
			return ;
		ft_push_a(data);
	}
	else if (c == 'a')
	{
		if (data->top_b == NULL)
			return ;
		ft_push_b(data);
	}
	data->op_count++;
	return ;
}
