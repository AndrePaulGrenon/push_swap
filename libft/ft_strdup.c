/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 18:10:42 by agrenon           #+#    #+#             */
/*   Updated: 2021/10/12 13:16:04 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	size;

	ptr = malloc(ft_strlen(s1) + 1);
	if (!ptr)
		return (0);
	size = ft_strlcpy(ptr, s1, ft_strlen(s1) + 1);
	return (ptr);
}
