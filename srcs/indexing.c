/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:22:14 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/04/21 15:25:23 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// gives an index to the givven stack

t_node	*index_stack(t_node	*head)
{
	t_node	*ptr;
	int		*arr;
	int		i;

	i = 0;
	ptr = head;
	arr = (int *)ft_calloc(sizeof(int), ft_lstsize(ptr) + 1);
	if (!arr)
		return (NULL);
	arr = lsttoarr(head, arr);
	arr = bubble_sort(arr, ft_lstsize(ptr));
	ptr = head;
	while (ptr)
	{
		i = 0;
		while (arr[i])
		{
			if (arr[i++] == ptr->n)
				ptr->index = i;
		}
		ptr = ptr->next;
	}
	free (arr);
	return (head);
}

// transforms the given list to an array 

int	*lsttoarr(t_node *head, int arr[])
{
	t_node	*ptr;
	int		i;

	i = 0;
	ptr = head;
	while (ptr != NULL)
	{
		arr[i++] = ptr->n;
		ptr = ptr->next;
	}
	return (arr);
}

// sorts the given array using a bubblesort algorithme

int	*bubble_sort(int arr[], int n)
{
	int	j;
	int	swap;
	int	i;

	i = 0;
	swap = 1;
	while (swap)
	{
		swap = 0;
		i++;
		j = 0;
		while (j < n - i)
		{
			if (arr[j] > arr[j + 1])
			{
				ft_swap(&arr[j], &arr[j + 1]);
				swap = 1;
			}
		j++;
		}	
	}
	return (arr);
}
