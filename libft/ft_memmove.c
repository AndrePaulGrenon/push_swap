/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 14:29:42 by agrenon           #+#    #+#             */
/*   Updated: 2021/10/07 19:06:41 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

static void	ft_momove(unsigned char *todst, unsigned char *tosrc, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		todst[i] = tosrc[i];
		i++;
	}
	return ;
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tosrc;
	unsigned char	*todst;

	tosrc = (unsigned char *) src;
	todst = (unsigned char *) dst;
	if (src > dst)
	{
		ft_momove(todst, tosrc, len);
	}
	else if (src < dst)
	{
		while (len != 0)
		{
			todst[len - 1] = tosrc[len - 1];
			len--;
		}
	}
	else
		return (0);
	return (dst);
}
