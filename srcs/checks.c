/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:49:23 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/04/27 16:04:57 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// checks if the arg is a digit and if it fits in a integer

void	args_valid(char **argv, int argc)
{
	int				i;
	long int		a;

	if (argc == 2)
		i = -1;
	else
		i = 0;
	while (argv[++i])
	{
		if (ft_strisdigit(argv[i]) == 1)
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		a = ft_atol(argv[i]);
		if (a > INT_MAX || a < INT_MIN)
		{
			ft_putstr_fd("Error\n", 2);
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
				ft_putstr_fd("Error\n", 2);
				return (0);
			}
		ptr = ptr->next;
		}
	head = head->next;
	}
	return (1);
}

// checks if the list is organised

int	list_organised(t_node *head)
{
	t_node	*current;
	t_node	*next;

	current = head;
	next = head->next;
	while (current->next != NULL)
	{
		if (current->n > next->n)
		{
			return (0);
		}
	current = current->next;
	next = next->next;
	}
	return (1);
}
