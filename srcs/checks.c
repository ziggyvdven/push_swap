/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:49:23 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/04/19 17:16:38 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// checks if there are duplicate arguments

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

// checks if there are duplicate arguments

int	list_valid(t_node *head)
{
	t_node	*ptr;

	while (head->next != NULL)
	{
		ptr = head->next;
		while (ptr != NULL)
		{
			if (head->n == ptr->n)
			{
				ft_printf("Error\n");
				return (0);
			}
		ptr = ptr->next;
		}
	head = head->next;
	}
	return(1);
}
