/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:14:48 by zvandeven         #+#    #+#             */
/*   Updated: 2023/04/24 14:00:21 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Swap the first 2 elements at the top of stacks a.
// Do nothing if there is only one or no elements.

void	sa(t_stack *stacks)
{
	t_node	*ptr;
	int		tmp_n;
	int		tmp_index;

	if (stacks->head_a == NULL)
		return ;
	ptr = stacks->head_a;
	ptr = ptr->next;
	tmp_n = stacks->head_a->n;
	tmp_index = stacks->head_a->index;
	stacks->head_a->n = ptr->n;
	stacks->head_a->index = ptr->index;
	ptr->n = tmp_n;
	ptr->index = tmp_index;
	ft_putendl_fd("sa", 1);
}

// Shift up all elements of stacks a by 1.
// The first element becomes the last one

void	ra(t_stack *stacks)
{
	t_node	*next;
	t_node	*current;
	int		last_n;
	int		last_index;

	if (stacks->head_a == NULL)
		return ;
	current = stacks->head_a;
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
	ft_putendl_fd("ra", 1);
}

// Shift down all elements of stacks a by 1.
// The last element becomes the first one.

void	rra(t_stack *stacks)
{
	t_node	*current;
	int		tmp_n;
	int		tmp_index;

	if (stacks->head_a == NULL)
		return ;
	current = stacks->head_a;
	tmp_n = current->n;
	tmp_index = current->index;
	while (current->next != NULL)
	{
		current = current->next;
		ft_swap(&tmp_n, &current->n);
		ft_swap(&tmp_index, &current->index);
	}
	stacks->head_a->n = tmp_n;
	stacks->head_a->index = tmp_index;
	ft_putendl_fd("rra", 1);
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
	ft_putendl_fd("pb", 1);
}
