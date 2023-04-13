/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:47:38 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/04/13 17:34:07 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	printlist(t_stack *stacka)
{
	t_node	*ptr;

	ptr = stacka->head_a;
	while (ptr != NULL)
	{
		ft_printf("%d ", ptr->n);
		ptr = ptr->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack		*stack;

	(void)argv;
	if (argc == 1)
		exit (1);
	args_valid(argv);
	stack = stack_init(argc, argv);
	printlist(stack);
}
