/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:35:04 by agrenon           #+#    #+#             */
/*   Updated: 2022/03/25 18:07:50 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push.h"

void	ft_print_all_lst(t_assiette *porcelaine)
{
	t_assiette	*begin;

	begin = porcelaine;
	while (begin)
	{
		printf("|  %ld  |   Adress: %p Next: %p Prev: %p\n", begin->value,begin, begin->next, begin->previous);
		begin = begin->next;
	}
	return ;
}

t_assiette	*ft_cuire_assiette(t_data_piles *data, char *arg)
{
	t_assiette	*temp;

	temp = malloc(sizeof(t_assiette));
	temp->value = ft_atoi(arg);
	temp->next = data->top_a;
	if (data->top_a)
		data->top_a->previous = temp;
	data->top_a = temp;
	return (temp);
}

void	ft_destroy_stacks(t_data_piles *data)
{
	t_assiette	*begin;
	t_assiette	*temp;

	if (data->top_a)
	{
		begin = data->top_a;
		while (begin)
		{
			temp = begin->next;
			free(begin);
			begin = temp;
		}
	}
	if (data->top_b)
	{
		begin = data->top_b;
		while (begin)
		{
			temp = begin->next;
			free(begin);
			begin = temp;
		}
	}
	free(data);
	return ;
}

bool	ft_is_align(t_assiette *data, bool reverse)
{
	bool		is_align;
	t_assiette	*begin;

	is_align = true;
	begin = data;
	while (begin)
	{
		if (begin->previous)
		{
			if (begin->value < begin->previous->value && reverse == false)
			{
				is_align = false;
				break ;
			}
			if (begin->value > begin->previous->value && reverse == true)
			{
				is_align = false;
				break ;
			}
		}
		begin = begin->next;
	}
	return (is_align);
}
