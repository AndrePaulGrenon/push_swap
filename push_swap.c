/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:59:15 by agrenon           #+#    #+#             */
/*   Updated: 2022/04/09 14:37:47 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push.h" 

t_data_piles	*ft_stack_split(char **argv)
{
	int				i;
	char			**tab;
	t_data_piles	*data;

	tab = ft_split(argv[1], ' ');
	data = ft_other_stack(tab, 0);
	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
	return (data);
}

int	main(int argc, char **argv)
{
	t_data_piles	*data;

	if (argc <= 1)
		return (0);
	if (argc == 2)
		data = ft_stack_split(argv);
	else
		data = ft_stack_create(argv, 1);
	if (!data)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	else if (data->arg_c == 3)
		ft_only_three(data);
	else if (data->arg_c < 30)
		ft_algo_a(data);
	else
		ft_algo_master(data);
	ft_destroy_stacks(data);
	return (0);
}
