/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 04:27:09 by mwojtasi          #+#    #+#             */
/*   Updated: 2024/04/03 19:53:23 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	radix_sort(t_stack *a, t_stack *b, t_stacks *stacks)
{
	size_t	nbit;
	size_t	i;
	size_t	op_count;

	nbit = 0;
	while (!is_sorted(a))
	{
		i = a->start;
		op_count = a->end - i;
		while (op_count--)
		{
			if (!get_n_bit(a->stack[i], nbit))
			{
				pb(stacks);
				i = a->start;
			}
			else
				ra(stacks);
		}
		while (b->start < b->end)
			pa(stacks);
		nbit++;
	}
}

int	is_indexed(int *indexed, int val, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (indexed[j] == val)
			return (1);
		j++;
	}
	return (0);
}

void	set_next_index(t_stack *a, int *indexed, int size, int *final_list)
{
	size_t	j;
	size_t	min_index;

	j = 0;
	min_index = -1;
	while (j < a->end)
	{
		if (!is_indexed(indexed, a->stack[j], size))
		{
			if (min_index == (size_t)(-1) || a->stack[j] < a->stack[min_index])
				min_index = j;
		}
		j++;
	}
	if (min_index != (size_t)-1)
	{
		final_list[min_index] = size;
		indexed[size] = a->stack[min_index];
	}
}

void	index_values(t_stacks *s)
{
	size_t	i;
	int		*final_list;
	int		*indexed;

	final_list = malloc(sizeof(int) * (s->a->end - s->a->start));
	if (!final_list)
		exit_error(s);
	indexed = malloc(sizeof(int) * (s->a->end - s->a->start));
	if (!indexed)
	{
		free(final_list);
		exit_error(s);
	}
	i = 0;
	while (i < s->a->end)
	{
		set_next_index(s->a, indexed, i, final_list);
		i++;
	}
	i = 0;
	free(s->a->stack);
	s->a->stack = final_list;
	free(indexed);
}
