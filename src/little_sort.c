/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:17:51 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/12/09 16:16:29 by dvan-hum         ###   ########.fr       */
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

static void	swap_sort(t_list **stack, int size)
{
	while (!is_sort(*stack))
	{
		if ((long)(*stack)->content + 1 == (long)(*stack)->next->content)
		{
			execute("ra", stack, NULL);
			execute("ra", stack, NULL);
			continue ;
		}
		if (((long)(*stack)->content > (long)(*stack)->next->content
			&& ((long)(*stack)->content + 1) % size != (long)(*stack)->next->content)
			|| (size >= 3 && (long) ft_lstgeti(*stack, 2)->content == (long)(*stack)->content + 1
			&& ((long) ft_lstgeti(*stack, 1)->content + 1) % size == (long)(*stack)->content))
			execute("sa", stack, NULL);
		else
		{
			execute("ra", stack, NULL);
		}
	}
}

void	little_sort(t_list **stack, t_list **stack_b, int size)
{
	char	*better;

	if (size < 5)
		swap_sort(stack, size);
	else if (size == 5)
	{
		better = better_rot(*stack_b, 'a', (int[1]){size - 1}, 1);
		while ((long)(*stack)->content != size - 1)
			execute(better, stack, NULL);
		execute("pb", stack, stack_b);
		t_list **truc = &ft_lstlast(*get_out())->next;
		swap_sort(stack, size - 1);
		filter_redundant(truc, size - 1);
		execute("pa", stack, stack_b);
		execute("ra", stack, stack_b);
	}
}
