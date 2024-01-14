/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 05:40:55 by mwojtasi          #+#    #+#             */
/*   Updated: 2024/01/14 05:40:55 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

typedef struct s_stack
{
	int				*stack;
	int				size;
}					t_stack;

typedef struct s_stacks
{
	t_stack			*a;
	t_stack			*b;
}					t_stacks;

int	ft_isdigit(int c);
int	ft_atoi(const char *nptr);
void exit_error(void);

#endif