/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 04:23:31 by mwojtasi          #+#    #+#             */
/*   Updated: 2024/02/08 04:23:31 by mwojtasi         ###   ########.fr       */
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
	int			*a;
	int			*b;
	t_stacks	*stacks;

	a = malloc(sizeof(int) * (argc - 1));
	b = malloc(sizeof(int) * (argc - 1));
	stacks = malloc(sizeof(t_stacks));
	if (!a || !b || !stacks)
		exit_error(stacks);
	stacks->a = malloc(sizeof(t_stack));
	stacks->b = malloc(sizeof(t_stack));
	if (!stacks->a || !stacks->b)
		exit_error(stacks);
	stacks->a->stack = a;
	stacks->b->stack = b;
	stacks->a->end = argc - 1;
	stacks->b->end = argc - 1;
	stacks->a->start = 0;
	stacks->b->start = argc - 1;
	return (stacks);
}

void	free_stacks(t_stacks *stacks)
{
	free(stacks->a->stack);
	free(stacks->b->stack);
	free(stacks->a);
	free(stacks->b);
	free(stacks);
}
