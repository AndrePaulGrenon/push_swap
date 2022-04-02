/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 18:10:23 by agrenon           #+#    #+#             */
/*   Updated: 2021/10/12 16:46:12 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	char			*ptr;
	unsigned char	my_char;

	my_char = (unsigned char) c;
	ptr = 0;
	i = 0;
	if (my_char < 0 || my_char > 128)
		return ((char *) s);
	while (s[i])
	{
		if (s[i] == my_char)
			ptr = (char *) &s[i];
		i++;
	}
	if (s[i] == my_char)
		ptr = (char *) &s[i];
	return (ptr);
}
