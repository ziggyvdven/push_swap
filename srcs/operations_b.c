/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvandeven <zvandeven@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:49:14 by zvandeven         #+#    #+#             */
/*   Updated: 2023/04/18 15:22:36 by zvandeven        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Swap the first 2 elements at the top of stacks b.
// Do nothing if there is only one or no elements.

void	sb(t_stack *stacks)
{
	t_node	*ptr;
	int		tmp;

	ptr = stacks->head_b;
	if (ptr->next == NULL)
		return ;
	ptr = ptr->next;
	tmp = stacks->head_b->n;
	stacks->head_a->n = ptr->n;
	ptr->n = tmp;
}

// Shift up all elements of stacks b by 1.
// The first element becomes the last one.

void	rb(t_stack *stacks)
{
	t_node	*next;
	t_node	*current;
	int		tmp;
	int		last;

	current = stacks->head_b;
	if (current->next == NULL)
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

// Shift down all elements of stacks b by 1.
// The last element becomes the first one.

void	rrb(t_stack *stacks)
{
	t_node	*current;
	int		tmp;

	current = stacks->head_b;
	if (current->next == NULL)
		return ;
	tmp = current->n;
	while (current->next != NULL)
	{
		current = current->next;
		ft_swap(&tmp, &current->n);
	}
	stacks->head_b->n = tmp;
}

// Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty

void	pa(t_stack *stacks)
{
	t_node	*ptr;

	if (stacks->head_b == NULL)
		return ;
	ptr = stacks->head_b;
	ptr = ptr->next;
	stacks->head_b->next = stacks->head_a;
	stacks->head_a = stacks->head_b;
	stacks->head_b = ptr;
}
