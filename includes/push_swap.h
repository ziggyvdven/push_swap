/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:37:21 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/04/06 21:12:00 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include	"../libft/libft.h"
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
	int		argc;
}	t_stack;

/*CHECKS*********************************/
void		args_valid(char **argv);

/*STACK**********************************/
t_stack		*stack_init(int argc, char **argv);
t_node		*lst_new_ps(char **argv, int i);
t_node		*fill_lst_ps(t_node **head_a, char **argv);


#endif
