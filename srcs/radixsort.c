/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radixsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:14:53 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/04/25 13:05:35 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*ft_radixsort(t_stack *stacks)
{
	int	nbits;
	int	i;
	int	j;

	i = 0;
	nbits = 0;
	while (((stacks->size) >> nbits) != 0)
		nbits++;
	while (i < nbits)
	{
		j = 0;
		while (j < stacks->size)
		{
			if (((stacks->head_a->index >> i) & 1) == 1)
				ra(stacks);
			else
				pb(stacks);
			j++;
		}
		while (stacks->head_b)
			pa(stacks);
		i++;
	}
	return (stacks);
}
