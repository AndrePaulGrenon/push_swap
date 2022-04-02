/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:03:05 by agrenon           #+#    #+#             */
/*   Updated: 2022/03/30 16:51:08 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push.h"

bool	ft_exit(t_data_piles *data, char *nombre, int numb)
{
	if (nombre && numb == 0)
	{
		ft_putstr_fd("ERREUR:  ", 1);
		ft_putstr_fd(nombre, 1);
		ft_putstr_fd(" est invalide\n", 1);
	}
	else if (numb < SHRT_MIN || numb > SHRT_MAX)
	{
		ft_putstr_fd("ERREUR:  ", 1);
		ft_putstr_fd(nombre, 1);
		if (nombre[0] == '-')
			ft_putstr_fd(" est trop petit.\n", 1);
		else
			ft_putstr_fd(" est trop grand.\n", 1);
	}
	else
	{
		ft_putstr_fd("ERREUR:  ", 1);
		ft_putnbr_fd(data->top_a->value, 1);
		ft_putstr_fd(" est un doublon\n", 1);
	}
	return (true);
}

bool	ft_error_check(t_data_piles *data, t_value *t, char *arg, t_value n)
{
	int		i;

	i = 0;
	while (arg[i])
	{
		if (arg[0] == '-' && i == 0)
			i = i + 0;
		else if (arg[i] < 48 || arg[i] > 57)
			return (ft_exit(data, arg, 0));
		i++;
	}
	i = 0;
	if (n > SHRT_MAX || n < SHRT_MIN)
		return (ft_exit(data, arg, n));
	while (t[i])
	{
		if (n == t[i])
			return (ft_exit(data, NULL, n));
		i++;
	}
	t[i] = n;
	return (false);
}

void	ft_generate_data(t_data_piles *data, int argc)
{
	t_assiette	*begin;
	int			coeff;

	coeff = 8 + (argc / 25);
	begin = data->top_a;
	data->min = data->top_a->value;
	data->max = data->top_a->value;
	while (begin)
	{
		if (begin->value > data->max)
			data->max = begin->value;
		else if (begin->value < data->min)
			data->min = begin->value;
		begin = begin->next;
	}
	data->range = ((data->max - data->min) / (argc - 1)) * coeff;
	if (!data->range)
		data->range = coeff;
	data->range_low = data->min - 1;
	data->range_up = data->max + 1;
	data->t_turn = false;
	return ;
}

t_data_piles	*ft_set_data(int argc)
{
	t_data_piles	*temp;

	temp = malloc(sizeof(t_data_piles));
	temp->op_count = 0;
	temp->len_a = argc - 1;
	temp->len_b = 0;
	temp->shuffle = 0;
	temp->shuffle_max = argc - 1;
	return (temp);
}

t_data_piles	*ft_stack_create(char **argv, int argc)
{
	t_data_piles	*data;
	t_assiette		*plat;
	int				i;
	t_value			*tab;
	bool			err;

	err = false;
	tab = malloc(sizeof(t_value) * argc);
	data = ft_set_data(argc);
	i = argc - 1;
	while (i)
	{
		plat = ft_cuire_assiette(data, argv[i]);
		if (ft_error_check(data, tab, argv[i], plat->value))
			err = true;
		i--;
	}
	ft_generate_data(data, argc);
	free(tab);
	if (err == false)
		return (data);
	ft_destroy_stacks(data);
	return (NULL);
}
