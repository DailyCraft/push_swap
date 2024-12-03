/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:17:51 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/12/03 16:35:18 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sort(t_list *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if ((long) stack->content > (long) stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	swap_sort(t_list **stack, int *bubble, int size)
{
	(void) bubble;
	(void) size;
	while (!is_sort(*stack))
	{
		if ((array_chr(bubble, size, (long) (*stack)->content) + 1) == array_chr(bubble, size, (long) (*stack)->next->content))
		{
			execute("ra", stack, NULL);
			execute("ra", stack, NULL);
			continue ;
		}
		if ((long) (*stack)->content > (long) (*stack)->next->content
			&& (array_chr(bubble, size, (long) (*stack)->content) - bubble + 1) % size != array_chr(bubble, size, (long) (*stack)->next->content) - bubble)
			execute("sa", stack, NULL);
		else
		{
			execute("ra", stack, NULL);
			//if (size < 4)
			//	execute("ra", stack, NULL);
		}
	}
}

void	little_sort(t_list **stack, t_list **stack_b, int *bubble, int size)
{
	(void) stack_b;
	(void) bubble;
	if (size < 5)
	{
		swap_sort(stack, bubble, size);
	}
}
