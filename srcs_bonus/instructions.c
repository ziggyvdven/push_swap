/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:52:04 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/04/28 16:52:42 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*ft_lstnew_bonus(char *content)
{
	t_node	*next;

	next = (t_node *)malloc(sizeof(t_node));
	if (!(next))
		return (NULL);
	next->str = content;
	next->next = NULL;
	return (next);
}

void	ft_lstadd_back_bonus(t_node **lst, t_node *new)
{
	t_node	*ptr;

	if (!lst)
		return ;
	if (lst)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			ptr = *lst;
			while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new;
		}
	}
}

void	ft_print_slist(t_node *head)
{
	t_node	*ptr;

	ptr = head;
	ft_printf("list:\n");
	while (ptr != NULL)
	{
		ft_printf("%s\n", ptr->str);
		ptr = ptr->next;
	}
}

t_node	*get_instructions(t_node *head)
{
	char	*str;

	head = NULL;
	while (1)
	{
		str = get_next_line(0);
		if (head == NULL)
			head = ft_lstnew_bonus(str);
		else
			ft_lstadd_back_bonus(&head, ft_lstnew_bonus(str));
		if (!(strncmp(str, "\n", 1)))
			break ;
		free(str);
	}
	ft_printf("list size: %d\n", ft_lstsize(head));
	ft_print_slist(head);
	return (head);
}
