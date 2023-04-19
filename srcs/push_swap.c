/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvandeven <zvandeven@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:47:38 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/04/18 15:34:14 by zvandeven        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	printlist(t_stack *stacks)
{
	t_node	*ptr;

	ptr = stacks->head_a;
	ft_printf("Stack A:\n");
	while (ptr != NULL)
	{
		ft_printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
	ft_printf("\n");
	ft_printf("Stack B:\n");
	ptr = stacks->head_b;
	while (ptr != NULL)
	{
		ft_printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
	ft_printf("\n");
}

void	free_stack(t_node **stack)
{
	t_node	*head;
	t_node	*tmp;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(stack);
}

int	main(int argc, char **argv)
{
	t_stack		*stacks;

	(void)argv;
	if (argc == 1)
		exit (0);
	args_valid(argv);
	stacks = stack_init(argc, argv);
	list_valid(stacks->head_a);
	pb(stacks);
	pb(stacks);
	ra(stacks);
	sa(stacks);
	pa(stacks);
	pa(stacks);
	printlist(stacks);
	free(stacks->head_a);
	free(stacks->head_b);
	free(stacks);
}
