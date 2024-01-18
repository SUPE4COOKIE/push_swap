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

void pb(t_stack *a, t_stack *b)
{
	if ((b->start > 0) && (a->start != a->end))
		b->stack[--b->start] = a->stack[a->start++];
	printf("pb\n");
}

void pa(t_stack *a, t_stack *b)
{
	if ((a->start > 0) && (b->start != b->end))
		a->stack[--a->start] = b->stack[b->start++];
	printf("pa\n");
}

int get_n_bit(int num, size_t n)
{
	return ((num >> n) & 1);
}

void ra(t_stack *a)
{
	size_t i;
	int		tmp;

	i = a->start;
	tmp = a->stack[i];
	while ((i + 1) < a->end)
	{
		a->stack[i] = a->stack[i + 1];
		i++;
	}
	a->stack[i] = tmp;
	printf("ra\n");
}

void rb(t_stack *b)
{
	size_t i;
	int		tmp;

	i = b->start;
	tmp = b->stack[i];
	while ((i + 1) < b->end)
	{
		b->stack[i] = b->stack[i + 1];
		i++;
	}
	b->stack[i] = tmp;
	printf("rb\n");
}

int is_sorted(t_stack *a)
{
    size_t i;

    if (a->end - a->start <= 1)  // If there's one or no element, it's sorted
        return (1);

    for (i = a->start; i < a->end - 1; i++)  // Iterate up to the second-to-last element
    {
        if (a->stack[i] > a->stack[i + 1])
            return (0);  // Return 0 if any element is greater than its next element
    }
    return (1);  // Return 1 if no such pair is found
}

//void three_sort(int *a, size_t size)
//{
//	if (a[0] > a[1] && a[1] < a[2] && a[0] < a[2])
//		sa(a, size);
//	else if (a[0] > a[1] && a[1] > a[2] && a[0] > a[2])
//	{
//		sa(a, size);
//		rra(a, size);
//	}
//	else if (a[0] > a[1] && a[1] < a[2] && a[0] > a[2])
//		ra(a, size);
//	else if (a[0] < a[1] && a[1] > a[2] && a[0] < a[2])
//	{
//		sa(a, size);
//		ra(a, size);
//	}
//	else
//		rra(a, size);
//}

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
	stacks->a->end = argc - 1;
	stacks->b->end = argc - 1;
	stacks->a->start = 0;
	stacks->b->start = argc - 1;
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

	i = stacks->a->start;
	printf("stack a:\n");
	while (i < stacks->a->end)
	{
		printf("%d\n", stacks->a->stack[i]);
		i++;
	}
	i = stacks->b->start;
	printf("stack b:\n");
	while (i < stacks->b->end)
	{
		printf("%d\n", stacks->b->stack[i]);
		i++;
	}
}

void	radix_sort(t_stack *a, t_stack *b, t_stacks *stacks)
{
	size_t	nbit;
	size_t	i;
	size_t	op_count;

	nbit = 0;
	while(!is_sorted(a))
	{
		if (nbit > 8)
			exit_error();
		i = a->start;
		op_count = a->end - i;
		while (op_count--)
		{
			if (!get_n_bit(a->stack[i], nbit))
			{
				pb(a, b);
				i = a->start;
			}
			else
			{
				ra(stacks->a);
			}
		}
		while (b->start < b->end)
		{
			pa(a, b);
		}
		nbit++;
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
	radix_sort(stacks->a, stacks->b, stacks);
	//rb(stacks->b);
	//pb(stacks->a, stacks->b);
	//printf("%d", get_n_bit(5, 0));
	print_stacks(stacks);
	free_stacks(stacks);
	return (0);
}