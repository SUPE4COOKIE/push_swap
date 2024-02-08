/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 04:16:34 by mwojtasi          #+#    #+#             */
/*   Updated: 2024/02/08 04:16:34 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	three_sort(t_stack *s)
{
	int	*a;
	int	i;

	a = s->stack;
	i = s->start;
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
			rra(stacks->a);
	}
	else
	{
		while (min_index-- > (int)stacks->a->start)
			ra(stacks->a);
	}
	pb(stacks->a, stacks->b);
}

void	small_sort(t_stacks *stacks)
{
	int	size;

	size = stacks->a->end - stacks->a->start;
	if (size == 2)
		sa(stacks->a);
	else if (size == 3)
		three_sort(stacks->a);
	else if (size == 4)
	{
		push_min_b(stacks);
		three_sort(stacks->a);
		pa(stacks->a, stacks->b);
	}
	else if (size == 5)
	{
		push_min_b(stacks);
		push_min_b(stacks);
		three_sort(stacks->a);
		pa(stacks->a, stacks->b);
		pa(stacks->a, stacks->b);
	}
}
