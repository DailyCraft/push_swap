/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:43:09 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/12/02 15:50:25 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	lst_to_index(t_list *stack, int *bubble, int size)
{
	while (stack)
	{
		stack->content = (void *)
			(array_chr(bubble, size, (long) stack->content) - bubble);
		stack = stack->next;
	}
}

void	radix_sort(t_list **stack, t_list **stack_b, int *bubble, int size)
{
	int	max_bits;
	int	bit;
	int	i;

	max_bits = 0;
	while ((size - 1) >> max_bits != 0)
		max_bits++;
	lst_to_index(*stack, bubble, size);
	bit = 0;
	while (bit < max_bits)
	{
		i = 0;
		while (i < size)
		{
			if ((((long)(*stack)->content >> bit) & 1) == 1)
				execute("ra", stack, stack_b);
			else
				execute("pb", stack, stack_b);
			i++;
		}
		while (*stack_b)
			execute("pa", stack, stack_b);
		bit++;
	}
}
