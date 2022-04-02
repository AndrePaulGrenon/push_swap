/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 12:31:53 by agrenon           #+#    #+#             */
/*   Updated: 2021/10/07 16:45:22 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dst, const void *src, unsigned int n)
{
	unsigned int	i;
	unsigned char	*todst;
	unsigned char	*tosrc;

	todst = (unsigned char *) dst;
	tosrc = (unsigned char *) src;
	i = 0;
	if (dst == src)
		return (dst);
	while (i < n)
	{
		todst[i] = tosrc[i];
		i++;
	}
	return (dst);
}
