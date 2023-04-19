/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvandeven <zvandeven@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:37:21 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/04/18 15:18:24 by zvandeven        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include	"../libft/includes/libft.h"
# include	<limits.h>

typedef struct s_node	t_node;

typedef struct s_node
{
	int		n;
	t_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*head_a;
	t_node	*tail_a;
	t_node	*head_b;
	t_node	*tail_b;
	int		argc;
}	t_stack;

/*CHECKS*********************************/
void		args_valid(char **argv);
void		list_valid(t_node *head);

/*STACK**********************************/
t_stack		*stack_init(int argc, char **argv);
t_node		*lst_new_ps(char **argv, int i);
t_node		*fill_lst_ps(t_node **head_a, char **argv);

/*operations******************************/
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
