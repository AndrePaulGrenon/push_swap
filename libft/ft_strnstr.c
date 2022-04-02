/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 16:14:58 by agrenon           #+#    #+#             */
/*   Updated: 2021/10/18 13:09:08 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	if (needle[i] == '\0')
		return ((char *) haystack);
	while (haystack[i] && i < len && ft_strlen(needle) <= ft_strlen(haystack))
	{
		if (haystack[i] == needle [j])
		{
			str = (char *) &haystack[i];
			while (haystack[i + j] && haystack[i + j] == needle[j]
				&& i + j < len)
			{
				j++;
			}
			if (needle[j] == '\0')
				return (str);
			j = 0;
		}
		i++;
	}
	return (0);
}
