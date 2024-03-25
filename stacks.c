/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 04:23:31 by mwojtasi          #+#    #+#             */
/*   Updated: 2024/03/26 00:00:48 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	fill_stack_a(t_stacks *stacks, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (is_in(stacks->a->stack, i - 1, ft_atoi(argv[i], stacks)))
			exit_error(stacks);
		stacks->a->stack[i - 1] = ft_atoi(argv[i], stacks);
		i++;
	}
}

t_stacks	*init_stacks(int argc)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		exit_error(NULL);
	stacks->a = malloc(sizeof(t_stack));
	stacks->b = malloc(sizeof(t_stack));
	if (!stacks->a || !stacks->b)
		exit_error(stacks);
	stacks->a->stack = malloc(sizeof(int) * (argc - 1));
	stacks->b->stack = malloc(sizeof(int) * (argc - 1));
	if (!stacks->a->stack || !stacks->b->stack)
		exit_error(stacks);
	stacks->a->end = argc - 1;
	stacks->b->end = argc - 1;
	stacks->a->start = 0;
	stacks->b->start = argc - 1;
	return (stacks);
}

void	free_stacks(t_stacks *stacks)
{
	if (!stacks)
		return ;
	if (stacks->a)
	{
		if (stacks->a->stack)
			free(stacks->a->stack);
		free(stacks->a);
	}
	if (stacks->b)
	{
		if (stacks->b->stack)
			free(stacks->b->stack);
		free(stacks->b);
	}
	free(stacks);
}
