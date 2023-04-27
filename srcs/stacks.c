/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 20:42:53 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/04/27 17:46:16 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// initiates the stacks

t_stack	*stack_init(int argc, char **argv)
{
	t_stack	*stacks;

	stacks = (t_stack *)ft_calloc((sizeof(t_stack)), 1);
	if (!stacks)
		return (NULL);
	stacks->head_a = ft_lstnew(ft_atoi(argv[1]));
	stacks->tail_a = fill_lst_ps(&stacks->head_a, argv);
	stacks->head_b = NULL;
	stacks->tail_b = NULL;
	stacks->size = ft_lstsize(stacks->head_a);
	stacks->argc = argc;
	return (stacks);
}

// fill a stack(list) with the given arguments

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
			ptr->next = ft_lstnew(ft_atoi(argv[i]));
			ptr = ptr->next;
		}	
	}
	return (ptr);
}

// frees one stack

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

//frees both stacks and frees the struckture

void	ft_free_stacks(t_stack *stacks)
{
	if (stacks->head_a)
		ft_free_stack(stacks->head_a);
	if (stacks->head_b)
		ft_free_stack(stacks->head_b);
	if (stacks)
		free(stacks);
}
