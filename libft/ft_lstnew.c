/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:27:28 by agrenon           #+#    #+#             */
/*   Updated: 2021/10/14 11:27:29 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_struc;

	new_struc = (t_list *) malloc(sizeof(t_list));
	if (!new_struc)
		return (0);
	new_struc->content = content;
	new_struc->next = NULL;
	return (new_struc);
}
