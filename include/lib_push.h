/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_push.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:14:56 by agrenon           #+#    #+#             */
/*   Updated: 2022/03/31 13:08:16 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_PUSH_H
# define LIB_PUSH_H

# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stddef.h>

typedef long	t_value;

typedef struct node
{
	t_value		value;
	struct node	*next;
	struct node	*previous;
}	t_assiette;

typedef struct stacks
{
	t_assiette	*top_a;
	t_assiette	*top_b;	
	t_value		op_count;
	t_value		min;
	t_value		max;
	t_value		frst_a;
	t_value		frst_b;
	t_value		sec_a;
	t_value		sec_b;
	t_value		las_a;
	t_value		las_b;
	t_value		shuffle_max;
	t_value		shuffle;	
	t_value		range;
	t_value		from_a;
	t_value		from_b;
	t_value		range_up;
	t_value		range_low;
	t_value		len_a;
	t_value		len_b;
	t_value		len_b_init;
	bool		t_turn;
}	t_data_piles;

t_assiette		*ft_cuire_assiette(t_data_piles *data, char *arg);
t_data_piles	*ft_set_data(int argc);
t_data_piles	*ft_stack_create(char **argv, int argc);
void			ft_set_info(t_data_piles *data);
void			ft_print_all_lst(t_assiette *porcelaine);
void			ft_destroy_stacks(t_data_piles *data);
void			ft_push(t_data_piles *data, char c);
t_assiette		*ft_swap(t_assiette *porcelaine);
void			ft_swap_flag(t_data_piles *data, char c);
t_assiette		*ft_rotate(t_assiette *porcelaine);
void			ft_rotate_flag(t_data_piles *data, char c);
t_assiette		*ft_reverse(t_assiette *porcelaine);
void			ft_reverse_flag(t_data_piles *data, char c);
void			ft_algo_a(t_data_piles *data);
void			ft_pushn_swap(t_data_piles *data);
void			ft_sortb_npush(t_data_piles *data);
void			ft_evrday_im_shuffling(t_data_piles *data);
void			ft_algo_b(t_data_piles *data);
void			ft_algo_bswitch(t_data_piles *data);
void			ft_algo_master(t_data_piles *data);
void			ft_thinking(t_data_piles *data);
bool			ft_is_align(t_assiette *data, bool reverse);
#endif 
