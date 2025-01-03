/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 08:24:24 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/12/09 14:16:25 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*lstdup(t_list *lst)
{
	t_list	*dup;

	dup = NULL;
	while (lst)
	{
		ft_lstadd_back(&dup, ft_lstnew(lst->content));
		lst = lst->next;
	}
	return (dup);
}

static int	*lst_array(t_list *lst, int size)
{
	int	*array;
	int	i;

	array = malloc(size * sizeof(int));
	if (!array)
		return (NULL);
	i = 0;
	while (lst)
	{
		array[i] = (long) lst->content;
		lst = lst->next;
		i++;
	}
	return (array);
}

static void	array_sort(int *array, int size)
{
	int	i;
	int	modified;
	int	temp;

	modified = 1;
	while (modified)
	{
		modified = 0;
		i = 0;
		while (i < size - 1)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				modified = 1;
			}
			i++;
		}
	}
}

int	*array_chr(int *array, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (array[i] == value)
			return (array + i);
		i++;
	}
	return (NULL);
}

void	lst_to_index(t_list *lst, int size)
{
	int	*array;

	array = lst_array(lst, size);
	array_sort(array, size);
	while (lst)
	{
		lst->content = (void *)
			(array_chr(array, size, (long) lst->content) - array);
		lst = lst->next;
	}
	free(array);
}
