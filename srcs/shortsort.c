/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:22:22 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/04/25 18:56:22 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*sort3(t_stack *stacks)
{
	t_node	*head;
	t_node	*mid;
	t_node	*tail;

	head = stacks->head_a;
	mid = stacks->head_a->next;
	tail = ft_lstlast(stacks->head_a);
	if (head->n > mid->n && mid->n < tail->n && tail->n > head->n)
		sa(stacks);
	else if (head->n > mid->n && mid->n > tail->n)
	{
		sa(stacks);
		rra(stacks);
	}
	else if (head->n > mid->n && mid->n < tail->n && tail->n < head->n)
		ra(stacks);
	else if (head->n < mid->n && mid->n > tail->n && tail->n > head->n)
	{
		sa(stacks);
		ra(stacks);
	}
	else if (head->n < mid->n && mid->n > tail->n && tail->n < head->n)
		rra(stacks);
	return (stacks);
}

t_stack	*sort4(t_stack *stacks)
{
	pb(stacks);
	stacks = sort3(stacks);
	while (stacks->head_b)
	{
		stacks->tail_a = ft_lstlast(stacks->head_a);
		if (stacks->head_b->index == 1)
			pa(stacks);
		else if (stacks->head_b->index == 4)
		{
			pa(stacks);
			ra(stacks);
		}
		else
		{
			if (stacks->head_b->index < stacks->head_a->index
				&& stacks->head_b->index > stacks->tail_a->index)
				pa(stacks);
			else
				ra(stacks);
		}
	}
	while (list_organised(stacks->head_a) == 0)
		ra(stacks);
	return (stacks);
}


t_stack	*sort5(t_stack *stacks)
{
	pb(stacks);
	pb(stacks);
	stacks = sort3(stacks);
	while (stacks->head_b)
	{
		stacks->tail_a = ft_lstlast(stacks->head_a);
		if (ft_lstsize(stacks->head_a) == 4)
			stacks = sort4(stacks);
		if (stacks->head_b->index == 1)
			pa(stacks);
		else if (stacks->head_b->index == 5
			|| (stacks->head_b->index == 4 && stacks->head_b->next->index == 5))
		{
			pa(stacks);
			ra(stacks);
		}
		else
		{
			if (stacks->head_b->index < stacks->head_a->index
				&& stacks->head_b->index > stacks->tail_a->index)
				pa(stacks);
			else
				ra(stacks);
		}
	}
	while (list_organised(stacks->head_a) == 0)
		ra(stacks);
	return (stacks);
}

t_stack	*shortsort(t_stack *stacks)
{
	int	size;

	size = ft_lstsize(stacks->head_a);
	if (size == 3)
		stacks = sort3(stacks);
	else if (size == 4)
		stacks = sort4(stacks);
	else if (size == 5)
		stacks = sort5(stacks);
	return (stacks);
}
