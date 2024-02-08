/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 04:00:26 by mwojtasi          #+#    #+#             */
/*   Updated: 2024/02/08 04:00:26 by mwojtasi         ###   ########.fr       */
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
	ft_printf("sa\n");
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
	ft_printf("ra\n");
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
	ft_printf("rra\n");
}

void	pb(t_stack *a, t_stack *b)
{
	if ((b->start > 0) && (a->start != a->end))
		b->stack[--b->start] = a->stack[a->start++];
	ft_printf("pb\n");
}

void	pa(t_stack *a, t_stack *b)
{
	if ((a->start > 0) && (b->start != b->end))
		a->stack[--a->start] = b->stack[b->start++];
	ft_printf("pa\n");
}
