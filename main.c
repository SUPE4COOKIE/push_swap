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

int check_input(int argc, char **argv)
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
	return (1);
}
int main(int argc, char **argv)
{
	if (argc < 2)
		exit_error();
	printf("is valid %d", check_input(argc, argv));
	
	return (0);
}