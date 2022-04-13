/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:58:45 by agrenon           #+#    #+#             */
/*   Updated: 2022/04/09 12:04:05 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push.h"

t_data_piles	*ft_other_stack(char **argv, int argc)
{
	t_data_piles	*data;
	t_assiette		*plat;
	int				i;
	t_value			*tab;
	bool			err;

	err = false;
	argc = ft_tab_len(argv) - argc;
	tab = malloc(sizeof(t_value) * argc);
	data = ft_set_data(argc);
	i = argc;
	while (i)
	{
		plat = ft_cuire_assiette(data, argv[i - 1]);
		if (ft_err_ch(data, tab, argv[i - 1], plat->value))
			err = true;
		i--;
	}
	ft_generate_data(data, data->arg_c);
	free(tab);
	if (err == false)
		return (data);
	ft_destroy_stacks(data);
	return (NULL);
}
