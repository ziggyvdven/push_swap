/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:47:38 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/04/19 17:23:38 by zvan-de-         ###   ########.fr       */
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

void	ft_clean_error(t_stack *stacks)
{
	ft_free_stacks(stacks);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_stack		*stacks;

	(void)argv;
	if (argc == 1 || argc == 2)
		exit (0);
	args_valid(argv);
	stacks = stack_init(argc, argv);
	if (!(list_valid(stacks->head_a)))
		ft_clean_error(stacks);
	pb(stacks);
	pb(stacks);
	ra(stacks);
	sa(stacks);
	printlist(stacks);
	ft_free_stacks(stacks);
	return (0);
}
