/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 21:54:17 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/11/18 22:55:35 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static int	array_contains(int *array, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (array[i] == value)
			return (1);
		i++;
	}
	return (0);
}

static void	sort_part(t_list **stack, t_list **stack_b, int *bubble, int size)
{
	int	i;
	int	min_i;
	int	max_i;

	i = 0;
	while (i < size)
	{
		if (array_contains(bubble, size, (long)(*stack)->content))
		{
			execute("pb", stack, stack_b);
			i++;
		}
		else
			execute("ra", stack, stack_b);
	}

	min_i = 0;
	max_i = size - 1;
	while (*stack_b)
	{
		if ((long)(*stack_b)->content == bubble[min_i])
		{
			execute("pa", stack, stack_b);
			execute("ra", stack, stack_b);
			min_i++;
		}
		else if ((long)(*stack_b)->content == bubble[max_i])
		{
			execute("pa", stack, stack_b);
			max_i--;
		}
		else
			execute("rb", stack, stack_b);
	}

	while ((long)(*stack)->content >= bubble[0] && (long)(*stack)->content <= bubble[size - 1])
		execute("ra", stack, stack_b);
}

void	sort(t_list **stack, t_list **stack_b)
{
	int	size;
	int	*bubble;

	size = ft_lstsize(*stack);
	bubble = lst_array(*stack, size);
	array_sort(bubble, size);
	sort_part(stack, stack_b, bubble, size / 2);
	sort_part(stack, stack_b, bubble + size / 2, size - size / 2);
	while ((long)(*stack)->content != bubble[0])
		execute("ra", stack, stack_b);
}
