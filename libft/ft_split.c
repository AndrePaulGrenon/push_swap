/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:17:10 by agrenon           #+#    #+#             */
/*   Updated: 2021/10/25 11:41:42 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	unsigned int	ft_strdiv(const char *s, char c)
{
	int		i;
	int		count;
	bool	div;

	div = true;
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			div = true;
		else
		{
			if (div == true)
				count++;
			div = false;
		}
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char			**tab;
	unsigned int	i;
	int				count;
	int				start;

	if (!s)
		return (0);
	tab = ft_calloc(ft_strdiv(s, c) + 1, sizeof(char *));
	if (!tab)
		return (0);
	count = 0;
	start = -1;
	i = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start == -1)
			start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start >= 0)
		{
			tab[count++] = ft_substr(s, start, (i - start));
			start = -1;
		}
		i++;
	}
	return (tab);
}
