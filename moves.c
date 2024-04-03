/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 04:00:26 by mwojtasi          #+#    #+#             */
/*   Updated: 2024/04/03 19:49:32 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	sa(t_stacks *s)
{
	int	tmp;
	t_stack	*a;

	a = s->a;
	if ((a->end - a->start) < 2)
		return ;
	tmp = a->stack[a->start];
	a->stack[a->start] = a->stack[a->start + 1];
	a->stack[a->start + 1] = tmp;
	if (write(1, "sa\n", 3) == -1)
		exit_error(s);
}

void	ra(t_stacks *s)
{
	size_t	i;
	int		tmp;
	t_stack	*a;
	
	a = s->a;
	i = a->start;
	tmp = a->stack[i];
	while ((i + 1) < a->end)
	{
		a->stack[i] = a->stack[i + 1];
		i++;
	}
	a->stack[i] = tmp;
	if (write(1, "ra\n", 3) == -1)
		exit_error(s);
}

void	rra(t_stacks *s)
{
	size_t	i;
	int		tmp;
	t_stack	*a;

	a = s->a;
	if ((a->end - a->start) < 2)
		return ;
	i = a->end - 1;
	tmp = a->stack[i];
	while (i > a->start)
	{
		a->stack[i] = a->stack[i - 1];
		i--;
	}
	a->stack[a->start] = tmp;
	if (write(1, "rra\n", 4) == -1)
		exit_error(s);
}

void	pb(t_stacks *s)
{
	t_stack	*a;
	t_stack	*b;

	a = s->a;
	b = s->b;
	if ((b->start > 0) && (a->start != a->end))
		b->stack[--b->start] = a->stack[a->start++];
	if (write(1, "pb\n", 3) == -1)
		exit_error(s);
}

void	pa(t_stacks *s)
{
	t_stack	*a;
	t_stack	*b;
	
	a = s->a;
	b = s->b;
	if ((a->start > 0) && (b->start != b->end))
		a->stack[--a->start] = b->stack[b->start++];
	if (write(1, "pa\n", 3) == -1)
		exit_error(s);
}
