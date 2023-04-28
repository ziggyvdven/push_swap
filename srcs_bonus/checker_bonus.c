/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:40:32 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/04/28 16:37:59 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// prints the stacks

void	printlist(t_stack *stacks)
{
	t_node	*ptr;

	ptr = stacks->head_a;
	ft_printf("Stack A:\n");
	while (ptr != NULL)
	{
		ft_printf("%d", ptr->n);
		ft_printf(" (%d)\n", ptr->index);
		ptr = ptr->next;
	}
	ft_printf("\n");
	ft_printf("Stack B:\n");
	ptr = stacks->head_b;
	while (ptr != NULL)
	{
		ft_printf("%d", ptr->n);
		ft_printf(" (%d)\n", ptr->index);
		ptr = ptr->next;
	}
	ft_printf("\n");
}

// frees the stacks and exits the program

void	ft_clean_error(t_stack *stacks)
{
	ft_free_stacks(stacks);
	exit(1);
}

// print and exit

void	ft_clean_exit(t_stack *stacks, char **argv)
{
	ft_free_stacks(stacks);
	if (stacks->argc == 2)
		ft_free_array(argv);
	exit(0);
}

// frees the array if argument is passed as a string

void	ft_free_array(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		free(argv[i]);
		argv[i] = NULL;
		i++;
	}
	free(argv);
}

int	main(int argc, char **argv)
{
	t_stack		*stacks;
	t_node		*lst;

	lst = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	args_valid(argv, argc);
	stacks = stack_init(argc, argv);
	if (!(list_valid(stacks->head_a)))
		ft_clean_error(stacks);
	stacks->head_a = index_stack(stacks->head_a);
	if (list_organised(stacks->head_a))
		ft_clean_exit(stacks, argv);
	lst = get_instructions(lst);
	ft_clean_exit(stacks, argv);
	return (0);
}
