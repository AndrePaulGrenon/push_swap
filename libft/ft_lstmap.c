/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:07:21 by agrenon           #+#    #+#             */
/*   Updated: 2021/10/14 11:18:54 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *s), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_element;

	if (!lst)
		return (0);
	new_list = NULL;
	while (lst)
	{
		if (new_list)
		{
			new_element = ft_lstnew((*f)(lst->content));
			if (new_element == 0)
			{
				ft_lstclear(&new_list, del);
				return (NULL);
			}
			ft_lstadd_back(&new_list, new_element);
		}
		else
			new_list = ft_lstnew((*f)(lst->content));
		lst = lst->next;
	}
	return (new_list);
}
