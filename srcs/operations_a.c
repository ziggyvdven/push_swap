/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:14:48 by zvandeven         #+#    #+#             */
/*   Updated: 2023/04/19 17:37:33 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Swap the first 2 elements at the top of stacks a.
// Do nothing if there is only one or no elements.

void	sa(t_stack *stacks)
{
	t_node	*ptr;
	int		tmp;

	if (stacks->head_a == NULL)
		return ;
	ptr = stacks->head_a;
	ptr = ptr->next;
	tmp = stacks->head_a->n;
	stacks->head_a->n = ptr->n;
	ptr->n = tmp;
}

// Shift up all elements of stacks a by 1.
// The first element becomes the last one

void	ra(t_stack *stacks)
{
	t_node	*next;
	t_node	*current;
	int		tmp;
	int		last;

	if (stacks->head_a == NULL)
		return ;
	current = stacks->head_a;
	last = current->n;
	while (current->next != NULL)
	{
	next = current->next;
	tmp = current->n;
	current->n = next->n;
	next->n = tmp;
	current = current->next;
	}
	current->n = last;
}

// Shift down all elements of stacks a by 1.
// The last element becomes the first one.

void	rra(t_stack *stacks)
{
	t_node	*current;
	int		tmp;

	if (stacks->head_a == NULL)
		return ;
	current = stacks->head_a;
	tmp = current->n;
	while (current->next != NULL)
	{
		current = current->next;
		ft_swap(&tmp, &current->n);
	}
	stacks->head_a->n = tmp;
}

// Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty

void	pb(t_stack *stacks)
{
	t_node	*ptr;

	if (stacks->head_a == NULL)
		return ;
	ptr = stacks->head_a;
	ptr = ptr->next;
	stacks->head_a->next = stacks->head_b;
	stacks->head_b = stacks->head_a;
	stacks->head_a = ptr;
}

