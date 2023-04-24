/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_ab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:06:21 by zvandeven         #+#    #+#             */
/*   Updated: 2023/04/21 16:40:57 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// swap a and b at the same time

void	ss(t_stack *stacks)
{
	if (stacks == NULL)
		return ;
	sa(stacks);
	sb(stacks);
	ft_putendl_fd("ss", 1);
}

// rotate a and b at the same time

void	rr(t_stack *stacks)
{
	if (stacks == NULL)
		return ;
	ra(stacks);
	rb(stacks);
	ft_putendl_fd("rr", 1);
}

// reverse rotate a and b at the same time

void	rrr(t_stack *stacks)
{
	if (stacks == NULL)
		return ;
	rra(stacks);
	rrb(stacks);
	ft_putendl_fd("rrr", 1);
}
