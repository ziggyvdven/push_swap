/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:49:23 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/04/13 17:34:14 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	args_valid(char **argv)
{
	int				i;
	long int		a;

	i = 0;
	while (argv[++i])
	{
		if (ft_strisdigit(argv[i]) == 1)
		{
			ft_printf("Error\n");
			exit(1);
		}
		a = ft_atol(argv[i]);
		if (a > INT_MAX || a < INT_MIN)
		{
			ft_printf("Error\n");
			exit(1);
		}
	}
	return ;
}
