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

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

void sa(int *a, size_t size)
{
	int tmp;

	if (size < 2)
		return ;
	tmp = a[0];
	a[0] = a[1];
	a[1] = tmp;
	printf("sa\n");
}

void ra(int *a, size_t size)
{
	int tmp;
	int i;

	if (size < 2)
		return ;
	tmp = a[0];
	i = 0;
	while (i < size - 1)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[size - 1] = tmp;
	printf("ra\n");
}

void rra(int *a, size_t size)
{
	int tmp;
	int i;

	if (size < 2)
		return ;
	tmp = a[size - 1];
	i = size - 1;
	while (i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = tmp;
	printf("rra\n");
}

int is_sorted(int *a, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size - 1)
	{
		if (a[i] > a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void three_sort(int *a, size_t size)
{
	if (a[0] > a[1] && a[1] < a[2] && a[0] < a[2])
		sa(a, size);
	else if (a[0] > a[1] && a[1] > a[2] && a[0] > a[2])
	{
		sa(a, size);
		rra(a, size);
	}
	else if (a[0] > a[1] && a[1] < a[2] && a[0] > a[2])
		ra(a, size);
	else if (a[0] < a[1] && a[1] > a[2] && a[0] < a[2])
	{
		sa(a, size);
		ra(a, size);
	}
	else
		rra(a, size);
}

void exit_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	return (0);
}

void check_input(int argc, char **argv)
{
	size_t i;
	size_t	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (ft_atoi(argv[i]) == -1)
			exit_error();
		while (argv[i][j])
		{
			if (argv[i][j] > '9' || argv[i][j] < '0')
				exit_error();
			j++;
		}
		i++;
	}
}

void fill_stack_a(t_stacks *stacks, int argc, char **argv)
{
	size_t i;

	i = 1;
	while (i < argc)
	{
		stacks->a->stack[i - 1] = ft_atoi(argv[i]);
		i++;
	}
}

t_stacks *init_stacks(int argc, char **argv)
{
	int			*a;
	int			*b;
	t_stacks	*stacks;

	a = malloc(sizeof(int) * (argc - 1));
	b = malloc(sizeof(int) * (argc - 1));
	stacks = malloc(sizeof(t_stacks));
	stacks->a = malloc(sizeof(t_stack));
	stacks->b = malloc(sizeof(t_stack));
	stacks->a->stack = a;
	stacks->b->stack = b;
	stacks->a->size = argc - 1;
	stacks->b->size = 0;
	return (stacks);
}

void free_stacks(t_stacks *stacks)
{
	free(stacks->a->stack);
	free(stacks->b->stack);
	free(stacks->a);
	free(stacks->b);
	free(stacks);
}

void print_stacks(t_stacks *stacks)
{
	size_t i;

	i = 0;
	printf("stack a:\n");
	while (i < stacks->a->size)
	{
		printf("%d\n", stacks->a->stack[i]);
		i++;
	}
	i = 0;
	printf("stack b:\n");
	while (i < stacks->b->size)
	{
		printf("%d\n", stacks->b->stack[i]);
		i++;
	}
}

int main(int argc, char **argv)
{
	t_stacks	*stacks;

	if (argc < 2)
		exit_error();
	check_input(argc, argv);
	stacks = init_stacks(argc, argv);
	fill_stack_a(stacks, argc, argv);
	print_stacks(stacks);
	free_stacks(stacks);
	return (0);
}