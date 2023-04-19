/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_ab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvandeven <zvandeven@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:06:21 by zvandeven         #+#    #+#             */
/*   Updated: 2023/04/18 15:17:37 by zvandeven        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ss(t_stack *stacks)
{
	if (stacks == NULL)
		return ;
	sa(stacks);
	sb(stacks);
}

void	rr(t_stack *stacks)
{
	if (stacks == NULL)
		return ;
	ra(stacks);
	rb(stacks);
}

void	rrr(t_stack *stacks)
{
	if (stacks == NULL)
		return ;
	rra(stacks);
	rrb(stacks);
}
