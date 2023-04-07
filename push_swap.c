/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:47:38 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/04/06 21:22:24 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	printlist(t_stack *stacka)
{
	t_node	*ptr;

	ptr = stacka->head_a;
	while (ptr->next != NULL)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack		*stacka;

	(void)argv;
	if (argc == 1)
		exit (1);
	args_valid(argv);
	stacka = stack_init(argc, argv);
	printlist(stacka);
}
