/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertionsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:13:41 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/04/21 16:51:10 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*insertion(t_stack *stacks)
{
	int		i;
	int		n;

	n = ft_lstsize(stacks->head_a);
	i = 1;
	while (i < n)
	{
		if (stacks->head_a->index == i)
		{
			pb(stacks);
			i++;
		}
		else
			ra(stacks);
	}
	while (i > 0)
	{
		pa(stacks);
		i--;
	}
	return (stacks);
}
