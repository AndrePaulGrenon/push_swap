/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:34:37 by agrenon           #+#    #+#             */
/*   Updated: 2021/09/29 14:34:40 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *b, int c, int l)
{
	int				i;
	unsigned char	*str;

	str = b;
	i = 0;
	while (i < l)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
