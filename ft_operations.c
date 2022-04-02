/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:17:49 by agrenon           #+#    #+#             */
/*   Updated: 2022/03/30 16:40:52 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push.h"

t_assiette	*ft_swap(t_assiette *porcelaine)
{
	t_assiette	*temp_b;

	if (!porcelaine || !porcelaine->next)
		return (porcelaine);
	temp_b = porcelaine->next;
	porcelaine->next = temp_b->next;
	temp_b->next = porcelaine;
	porcelaine->previous = temp_b;
	if (porcelaine->next)
		porcelaine->next->previous = porcelaine;
	temp_b->previous = NULL;
	return (temp_b);
}

void	ft_swap_flag(t_data_piles *data, char c)
{
	if (c == 'a')
	{
		data->top_a = ft_swap(data->top_a);
		write(1, "sa\n", 3);
	}
	else if (c == 'b')
	{
		data->top_b = ft_swap(data->top_b);
		write(1, "sb\n", 3);
	}
	else if (c == 's')
	{
		data->top_a = ft_swap(data->top_a);
		data->top_b = ft_swap(data->top_b);
		write(1, "ss\n", 3);
	}
	data->op_count++;
	return ;
}

t_assiette	*ft_rotate(t_assiette *porcelaine)
{
	t_assiette	*temp_b;
	t_assiette	*begin;

	if (!porcelaine || !porcelaine->next)
		return (porcelaine);
	begin = porcelaine;
	temp_b = porcelaine->next;
	while (begin)
	{
		if (begin->next == NULL)
		{
			porcelaine->previous = begin;
			begin->next = porcelaine;
			break ;
		}
		begin = begin->next;
	}
	porcelaine->next = NULL;
	temp_b->previous = NULL;
	return (temp_b);
}

void	ft_rotate_flag(t_data_piles *data, char c)
{
	if (c == 'a')
	{
		data->top_a = ft_rotate(data->top_a);
		write(1, "ra\n", 3);
	}
	else if (c == 'b')
	{
		data->top_b = ft_rotate(data->top_b);
		write(1, "rb\n", 3);
	}
	else if (c == 'r')
	{
		data->top_a = ft_rotate(data->top_a);
		data->top_b = ft_rotate(data->top_b);
		write(1, "rr\n", 3);
	}
	data->op_count++;
	return ;
}
