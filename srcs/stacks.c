/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 20:42:53 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/04/19 17:21:49 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*stack_init(int argc, char **argv)
{
	t_stack	*stacks;

	(void)argc;
	stacks = (t_stack *)ft_calloc((sizeof(t_stack)), 1);
	if (!stacks)
		return (NULL);
	stacks->head_a = lst_new_ps(argv, 1);
	stacks->tail_a = fill_lst_ps(&stacks->head_a, argv);
	stacks->head_b = NULL;
	stacks->tail_b = NULL;
	stacks->argc = argc;
	return (stacks);
}

t_node	*fill_lst_ps(t_node **head_a, char **argv)
{
	t_node	*ptr;
	int		i;

	i = 1;
	ptr = NULL;
	if (head_a)
	{
		ptr = *head_a;
		while (ptr->next != NULL)
			ptr = ptr->next;
		while (argv[++i])
		{
			ptr->next = lst_new_ps(argv, i);
			ptr = ptr->next;
		}	
	}
	return (ptr);
}

t_node	*lst_new_ps(char **argv, int i)
{
	t_node	*a;

	a = (t_node *)malloc(sizeof(t_node));
	if (!a)
		return (NULL);
	a->n = ft_atoi(argv[i]);
	a->next = NULL;
	return (a);
}

void	ft_free_stack(t_node *stack)
{
	t_node	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		if (tmp)
			free(tmp);
	}
	if (stack)
		free (stack);
}

void	ft_free_stacks(t_stack *stacks)
{
	if (stacks->head_a)
		ft_free_stack(stacks->head_a);
	if (stacks->head_b)
		ft_free_stack(stacks->head_b);
	if (stacks)
		free(stacks);
}
