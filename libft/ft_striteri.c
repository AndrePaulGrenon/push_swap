/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:34:57 by agrenon           #+#    #+#             */
/*   Updated: 2021/10/08 15:01:26 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	void	(*str)(unsigned int, char *);
	int		i;

	str = f;
	if (s == 0)
		return ;
	i = 0;
	while (s[i])
	{
		(*str)(i, &s[i]);
		i++;
	}
	return ;
}
