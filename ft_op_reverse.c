/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_reverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:26:31 by agrenon           #+#    #+#             */
/*   Updated: 2022/03/30 16:41:08 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push.h"

t_assiette	*ft_reverse(t_assiette *porcelaine)
{
	t_assiette	*temp_b;
	t_assiette	*begin;

	if (!porcelaine || !porcelaine->next)
		return (porcelaine);
	begin = porcelaine;
	temp_b = porcelaine;
	while (begin)
	{
		if (begin->next == NULL)
		{
			temp_b = begin;
			temp_b->next = porcelaine;
			if (temp_b->previous)
				temp_b->previous->next = NULL;
			temp_b->previous = NULL;
			porcelaine->previous = temp_b;
			break ;
		}
		begin = begin->next;
	}
	return (temp_b);
}

void	ft_reverse_flag(t_data_piles *data, char c)
{
	if (c == 'a')
	{
		data->top_a = ft_reverse(data->top_a);
		write(1, "rra\n", 4);
	}
	else if (c == 'b')
	{
		data->top_b = ft_reverse(data->top_b);
		write(1, "rrb\n", 4);
	}
	else if (c == 'r')
	{
		data->top_a = ft_reverse(data->top_a);
		data->top_b = ft_reverse(data->top_b);
		write(1, "rrr\n", 4);
	}
	data->op_count++;
	return ;
}
