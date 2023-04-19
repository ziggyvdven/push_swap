/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvandeven <zvandeven@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:14:48 by zvandeven         #+#    #+#             */
/*   Updated: 2023/04/18 15:48:01 by zvandeven        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Swap the first 2 elements at the top of stacks a.
// Do nothing if there is only one or no elements.

void	sa(t_stack *stacks)
{
	t_node	*ptr;
	int		tmp;

	ptr = stacks->head_a;
	if (ptr->next == NULL)
		return ;
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

	current = stacks->head_a;
	if (current->next == NULL || current == NULL)
		return ;
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

	current = stacks->head_a;
	if (current->next == NULL)
		return ;
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

