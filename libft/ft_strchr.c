/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:22:27 by agrenon           #+#    #+#             */
/*   Updated: 2021/10/12 16:47:59 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	unsigned char	my_char;

	my_char = (unsigned char) c;
	i = 0;
	if (my_char < 0 || my_char > 255)
		return ((char *) s);
	while (s[i])
	{
		if (s[i] == my_char)
		{
			return ((char *) &s[i]);
		}
		i++;
	}
	if (s[i] == my_char)
		return ((char *) &s[i]);
	return (0);
}
