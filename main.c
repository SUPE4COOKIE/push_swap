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

void sa(t_stack *a)
{
	int tmp;

	if ((a->end - a->start) < 2)
		return ;
	tmp = a->stack[a->start];
	a->stack[a->start] = a->stack[a->start + 1];
	a->stack[a->start + 1] = tmp;
	printf("sa\n");
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

void rra(t_stack *a)
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

int	get_min_index(t_stack *s)
{
	int	i;
	int	min;
	int	min_index;

	i = s->end - 1;
	min = s->stack[i];
	min_index = i;
	while (i >= (int)s->start)
	{
		if (s->stack[i] < min)
		{
			min = s->stack[i];
			min_index = i;
		}
		i--;
	}
	return (min_index);
}

int is_sorted(t_stack *a)
{
    size_t i;

    if (a->end - a->start <= 1)
        return (1);

    for (i = a->start; i < a->end - 1; i++)
    {
        if (a->stack[i] > a->stack[i + 1])
            return (0);
    }
    return (1);
}

void three_sort(t_stack *s)
{
	int *a;
	int i;

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

void exit_error(t_stacks *stacks)
{
	if (stacks)
		free_stacks(stacks);
	write(2, "Error\n", 6);
	exit(0);
}

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	exit_error(NULL);
	return (0);
}

int is_in(int *arr, int len, int val)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (arr[i] == val)
			return (1);
		i++;
	}
	return (0);
}

void fill_stack_a(t_stacks *stacks, int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (is_in(stacks->a->stack, i - 1, ft_atoi(argv[i], stacks)))
			exit_error(stacks);
		stacks->a->stack[i - 1] = ft_atoi(argv[i], stacks);
		i++;
	}
}

t_stacks *init_stacks(int argc)
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
				ra(stacks->a);
		}
		while (b->start < b->end)
			pa(a, b);
		nbit++;
	}
}

void	push_min_b(t_stacks *stacks)
{
	int min_index;

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

void small_sort(t_stacks *stacks)
{
	int size;

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

int is_indexed(int *indexed, int val, int i)
{
	int j;

	j = 0;
	while (j < i)
	{
		if (indexed[j] == val)
			return (1);
		j++;
	}
	return (0);
}

void index_values(t_stacks *s)
{
	size_t	i;
	size_t	j;
	size_t	min_index;
	t_stack	*a;
	int	*final_list;
	int	*indexed;

	a = s->a;
	final_list = malloc(sizeof(int) * (a->end - a->start));
    indexed = malloc(sizeof(int) * (a->end - a->start));
    if (!final_list || !indexed)
        exit_error(s);
    i = 0;
    min_index = a->start;
    while (i < a->end)
	{
        j = 0;
        while (j < a->end)
		{
            if (a->stack[min_index] > a->stack[j] && !is_indexed(indexed, a->stack[j], i))
                min_index = j;
            j++;
        }
        final_list[min_index] = i;
        indexed[i] = a->stack[min_index];
        j = 0;
        while (j < a->end)
		{
            if (!is_indexed(indexed, a->stack[j], i + 1))
			{
                min_index = j;
                break;
            }
            j++;
        }
        i++;
    }
	i = 0;
	while (i < a->end)
	{
		a->stack[i] = final_list[i];
		i++;
	}
	free(final_list);
	free(indexed);
}

int main(int argc, char **argv)
{
	t_stacks	*stacks;

	if (argc < 2 || !argv[1][0])
		exit_error(NULL);
	stacks = init_stacks(argc);
	fill_stack_a(stacks, argc, argv);
	if (is_sorted(stacks->a))
		return (free_stacks(stacks), 0);
	index_values(stacks);
	if (stacks->a->end - stacks->a->start <= 5)
		small_sort(stacks);
	else
		radix_sort(stacks->a, stacks->b, stacks);
	free_stacks(stacks);
	return (0);
}