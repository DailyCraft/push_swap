/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:17:51 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/12/10 09:53:19 by dvan-hum         ###   ########.fr       */
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

static int	sa_or_ra(t_list *stack, int size)
{
	if ((long) stack->content > (long) stack->next->content)
		return (((long) stack->content + 1) % size
			!= (long) stack->next->content);
	else if (size >= 3 && ft_lstgeti(stack, 2)->content == stack->content + 1)
		return (((long) ft_lstgeti(stack, 1)->content + 1) % size
			== (long) stack->content);
	return (0);
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
		if (sa_or_ra(*stack, size))
			execute("sa", stack, NULL);
		else
			execute("ra", stack, NULL);
	}
}

void	little_sort(t_list **stack, t_list **stack_b, int size)
{
	char	*better;
	t_list	**out_child;

	if (size < 5)
		swap_sort(stack, size);
	else if (size == 5)
	{
		better = better_rot(*stack_b, 'a', (int [1]){size - 1}, 1);
		while ((long)(*stack)->content != size - 1)
			execute(better, stack, NULL);
		execute("pb", stack, stack_b);
		out_child = &ft_lstlast(*get_out())->next;
		swap_sort(stack, size - 1);
		filter_redundant(out_child, size - 1);
		execute("pa", stack, stack_b);
		execute("ra", stack, stack_b);
	}
}
