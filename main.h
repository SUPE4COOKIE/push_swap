/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 05:40:55 by mwojtasi          #+#    #+#             */
/*   Updated: 2024/01/14 05:40:55 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				*stack;
	size_t			end;
	size_t			start;
}	t_stack;

typedef struct s_stacks
{
	t_stack			*a;
	t_stack			*b;
}					t_stacks;

int			ft_atoi(const char *nptr, t_stacks *stacks);
void		exit_error(t_stacks *stacks);
void		free_stacks(t_stacks *stacks);
void		sa(t_stacks *s);
void		ra(t_stacks *s);
void		rra(t_stacks *s);
void		pb(t_stacks *s);
void		pa(t_stacks *s);
void		three_sort(t_stacks *s);
void		push_min_b(t_stacks *stacks);
void		small_sort(t_stacks *stacks);
int			is_sorted(t_stack *a);
int			get_n_bit(int num, size_t n);
int			get_min_index(t_stack *s);
int			is_in(int *arr, int len, int val);
void		fill_stack_a(t_stacks *stacks, int argc, char **argv);
t_stacks	*init_stacks(int argc);
void		free_stacks(t_stacks *stacks);
void		radix_sort(t_stack *a, t_stack *b, t_stacks *stacks);
int			is_indexed(int *indexed, int val, int i);
void		index_values(t_stacks *s);
void		set_next_index(t_stack *a, int *indexed, int i, int *final_list);
#endif