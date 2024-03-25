/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 23:44:00 by mwojtasi          #+#    #+#             */
/*   Updated: 2024/01/10 23:44:00 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	exit_error(t_stacks *stacks)
{
	if (stacks)
		free_stacks(stacks);
	write(2, "Error\n", 6);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	if (argc < 2)
		return (0);
	if (!argv[1][0])
		exit_error(NULL);
	stacks = init_stacks(argc);
	fill_stack_a(stacks, argc, argv);
	if (is_sorted(stacks->a))
		return (free_stacks(stacks), 0);
	index_values(stacks);
	if (stacks->a->end - stacks->a->start <= 30)
		small_sort(stacks);
	else
		radix_sort(stacks->a, stacks->b, stacks);
	free_stacks(stacks);
	return (0);
}
