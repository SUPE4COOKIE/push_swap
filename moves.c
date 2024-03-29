/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 04:00:26 by mwojtasi          #+#    #+#             */
/*   Updated: 2024/03/29 22:00:45 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	sa(t_stack *a)
{
	int	tmp;

	if ((a->end - a->start) < 2)
		return ;
	tmp = a->stack[a->start];
	a->stack[a->start] = a->stack[a->start + 1];
	a->stack[a->start + 1] = tmp;
	if (!write(1, "sa\n", 3))
		exit_error(NULL);
}

void	ra(t_stack *a)
{
	size_t	i;
	int		tmp;

	i = a->start;
	tmp = a->stack[i];
	while ((i + 1) < a->end)
	{
		a->stack[i] = a->stack[i + 1];
		i++;
	}
	a->stack[i] = tmp;
	if (!write(1, "ra\n", 3))
		exit_error(NULL);
}

void	rra(t_stack *a)
{
	size_t	i;
	int		tmp;

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
	if (!write(1, "rra\n", 4))
		exit_error(NULL);
}

void	pb(t_stack *a, t_stack *b)
{
	if ((b->start > 0) && (a->start != a->end))
		b->stack[--b->start] = a->stack[a->start++];
	if (!write(1, "pb\n", 3))
		exit_error(NULL);
}

void	pa(t_stack *a, t_stack *b)
{
	if ((a->start > 0) && (b->start != b->end))
		a->stack[--a->start] = b->stack[b->start++];
	if (!write(1, "pa\n", 3))
		exit_error(NULL);
}
