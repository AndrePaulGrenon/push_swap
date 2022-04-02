/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 17:03:25 by agrenon           #+#    #+#             */
/*   Updated: 2021/10/18 13:10:36 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cherche(int i, char const *s1, char const *set)
{
	int	j;

	j = 0;
	while (set[j])
	{
		if (set[j] == s1[i])
			return (1);
		j++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{	
	char	*str;
	int		i;
	int		j;

	if (!set || !s1)
		return (NULL);
	j = ft_strlen(s1) - 1;
	i = 0;
	str = (char *) s1;
	while (s1[i] && ft_cherche(i, s1, set) == 1)
		i++;
	while (j != 0 && ft_cherche(j, s1, set) == 1)
		j--;
	return (ft_substr(s1, i, j - i + 1));
}	
