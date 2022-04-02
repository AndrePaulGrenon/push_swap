/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:42:25 by agrenon           #+#    #+#             */
/*   Updated: 2021/10/08 11:07:29 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = ft_strlen(dst);
	j = 0;
	k = i;
	if (dstsize <= 0)
		return (ft_strlen(src));
	if (ft_strlen(dst) >= dstsize)
		return (ft_strlen(src) + dstsize);
	while (i < dstsize - 1 && src[j])
	{	
		dst[i] = src[j];
		j++;
		i++;
	}
	dst[i] = '\0';
	return (k + ft_strlen(src));
}
