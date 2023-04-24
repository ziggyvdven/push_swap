/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:49:14 by zvandeven         #+#    #+#             */
/*   Updated: 2023/04/24 14:00:11 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Swap the first 2 elements at the top of stacks b.
// Do nothing if there is only one or no elements.

void	sb(t_stack *stacks)
{
	t_node	*ptr;
	int		tmp;

	if (stacks->head_b == NULL)
		return ;
	ptr = stacks->head_b;
	ptr = ptr->next;
	tmp = stacks->head_b->n;
	stacks->head_a->n = ptr->n;
	ptr->n = tmp;
	ft_putendl_fd("sb", 1);
}

// Shift up all elements of stacks b by 1.
// The first element becomes the last one.

void	rb(t_stack *stacks)
{
	t_node	*next;
	t_node	*current;
	int		last_n;
	int		last_index;

	if (stacks->head_b == NULL)
		return ;
	current = stacks->head_b;
	last_n = current->n;
	last_index = current->index;
	while (current->next != NULL)
	{
		next = current->next;
		ft_swap(&next->n, &current->n);
		ft_swap(&next->index, &current->index);
		current = current->next;
	}
	current->n = last_n;
	current->index = last_index;
	ft_putendl_fd("rb", 1);
}

// Shift down all elements of stacks b by 1.
// The last element becomes the first one.

void	rrb(t_stack *stacks)
{
	t_node	*current;
	int		tmp;

	if (stacks->head_b == NULL)
		return ;
	current = stacks->head_b;
	tmp = current->n;
	while (current->next != NULL)
	{
		current = current->next;
		ft_swap(&tmp, &current->n);
	}
	stacks->head_b->n = tmp;
	ft_putendl_fd("rrb", 1);
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
	ft_putendl_fd("pa", 1);
}
