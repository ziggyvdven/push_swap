/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:37:21 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/04/25 18:13:44 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include	"../libft/includes/libft.h"
# include	<limits.h>

typedef struct s_node	t_node;

typedef struct s_stack
{
	t_node	*head_a;
	t_node	*tail_a;
	t_node	*head_b;
	t_node	*tail_b;
	int		size;
	int		argc;
}	t_stack;

/*CHECKS*********************************/
void		args_valid(char **argv, int argc);
int			list_valid(t_node *head);
int			list_organised(t_node *head);

/*INDEXING*******************************/
t_node		*index_stack(t_node	*ptr);
int			*bubble_sort(int arr[], int n);
int			*lsttoarr(t_node *head, int arr[]);

/*STACK**********************************/
t_stack		*stack_init(int argc, char **argv);
t_node		*fill_lst_ps(t_node **head_a, char **argv);
void		ft_free_stack(t_node *lst);
void		ft_free_stacks(t_stack *stacks);
void		ft_free_array(char **ar);

/*SORTING*********************************/
t_stack		*insertion(t_stack *stacks);
t_stack		*ft_radixsort(t_stack *stacks);
t_stack		*shortsort(t_stack *stacks);
t_stack		*sort3(t_stack *stacks);

/*OPERATIONS******************************/
void		sa(t_stack *stacks);
void		ra(t_stack *stacks);
void		rra(t_stack *stacks);
void		pb(t_stack *stacks);
void		sb(t_stack *stacks);
void		rb(t_stack *stacks);
void		rrb(t_stack *stacks);
void		pa(t_stack *stacks);
void		ss(t_stack *stacks);
void		rr(t_stack *stacks);
void		rrr(t_stack *stacks);

#endif
