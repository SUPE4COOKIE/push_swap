/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 04:16:34 by mwojtasi          #+#    #+#             */
/*   Updated: 2024/04/03 19:57:49 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	three_sort(t_stacks *s)
{
	int	*a;
	int	i;

	a = s->a->stack;
	i = s->a->start;
	if (a[i] > a[1 + i] && a[1 + i] < a[2 + i] && a[i] < a[2 + i])
		sa(s);
	else if (a[i] > a[1 + i] && a[1 + i] > a[2 + i] && a[i] > a[2 + i])
	{
		sa(s);
		rra(s);
	}
	else if (a[i] > a[1 + i] && a[1 + i] < a[2 + i] && a[i] > a[2 + i])
		ra(s);
	else if (a[i] < a[1 + i] && a[1 + i] > a[2 + i] && a[i] < a[2 + i])
	{
		sa(s);
		ra(s);
	}
	else if (a[i] < a[1 + i] && a[1 + i] > a[2 + i] && a[i] > a[2 + i])
		rra(s);
}

void	push_min_b(t_stacks *stacks)
{
	int	min_index;

	min_index = get_min_index(stacks->a);
	if (min_index > (int)((stacks->a->end - stacks->a->start) / 2))
	{
		while (min_index++ < (int)stacks->a->end)
			rra(stacks);
	}
	else
	{
		while (min_index-- > (int)stacks->a->start)
			ra(stacks);
	}
	pb(stacks);
}

void	small_sort(t_stacks *stacks)
{
	int	size;
	int	i;

	size = stacks->a->end - stacks->a->start;
	if (size == 2)
		sa(stacks);
	else if (size == 3)
		three_sort(stacks);
	else
	{
		i = 0;
		while (i++ < size - 3)
			push_min_b(stacks);
		three_sort(stacks);
		while (stacks->b->start < stacks->b->end)
			pa(stacks);
	}
}
