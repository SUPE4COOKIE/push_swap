/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 06:15:13 by mwojtasi          #+#    #+#             */
/*   Updated: 2024/01/14 06:15:13 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	ft_isspace(char c)
{
	if ((c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
			|| c == '\r'))
		return (1);
	return (0);
}

static int	return_overflow(long int result, int nptr, int sign)
{
	long int	tmp;

	tmp = (result * 10 + nptr);
	if (result != ((tmp - nptr) / 10))
	{
		if (sign < 0)
			return (-1);
		else
			return (0);
	}
	return (1);
}

int	ft_atoi(const char *nptr)
{
	long int	result;
	int			sign;

	result = 0;
	sign = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr && ft_isdigit((unsigned char)*nptr))
	{
		if (return_overflow(result, (int)*nptr - '0', sign) != 1)
			exit_error();
		result = result * 10 + *nptr - '0';
		nptr++;
	}
	return ((int)(result * sign));
}