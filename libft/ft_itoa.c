/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 15:06:05 by agrenon           #+#    #+#             */
/*   Updated: 2021/10/12 15:43:19 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	recursive_itoa(int n, int i, char *s1)
{
	if (n < 0)
	{
		s1[0] = '-';
		if (n == INT_MIN)
		{
			s1[1] = '2';
			n = -147483648;
		}
		n = n * (-1);
	}
	if (n < 10)
	{
		s1[i] = n + 48;
		return (n);
	}
	else
	{
		s1[i] = (recursive_itoa((n % 10), i - 1, s1) + 48);
		(void) (recursive_itoa((n / 10), i - 1, s1)) ;
		return (n);
	}
}	

char	*ft_itoa(int n)
{
	char	*ptr;
	int		n_len;
	int		n_value;

	n_value = n;
	n_len = 0;
	if (n <= 0)
	{
		n_len++;
		n_value = n * (-1);
	}
	while (n_value > 0)
	{
		n_len++;
		n_value = n_value / 10;
	}
	if (n == INT_MIN)
		n_len = 11;
	ptr = ft_calloc(1, n_len + 1);
	if (ptr == 0)
		return (0);
	recursive_itoa(n, n_len - 1, ptr);
	ptr [n_len] = '\0';
	return (ptr);
}
