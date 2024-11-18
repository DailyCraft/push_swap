/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:11:03 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/11/18 22:53:36 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_list **stack)
{
	t_list	*second;
	t_list	*third;

	if (ft_lstsize(*stack) < 2)
		return ;
	second = ft_lstgeti(*stack, 1);
	third = ft_lstgeti(*stack, 2);
	second->next = *stack;
	(*stack)->next = third;
	*stack = second;
}

static void	push(t_list **from, t_list **to)
{
	t_list	*moved;

	if (!*from)
		return ;
	moved = *from;
	*from = (*from)->next;
	ft_lstadd_front(to, moved);
}

static void	rotate(t_list **stack)
{
	t_list	*moved;

	if (ft_lstsize(*stack) < 2)
		return ;
	moved = *stack;
	*stack = (*stack)->next;
	moved->next = NULL;
	ft_lstadd_back(stack, moved);
}

static void	reverse_rotate(t_list **stack)
{
	size_t	size;
	t_list	*moved;
	t_list	*last;

	size = ft_lstsize(*stack);
	if (size < 2)
		return ;
	last = ft_lstgeti(*stack, size - 2);
	moved = last->next;
	last->next = NULL;
	ft_lstadd_front(stack, moved);
}

void	execute(char *action, t_list **stack_a, t_list **stack_b)
{
	if (ft_strcmp("sa", action) == 0 || ft_strcmp("ss", action) == 0)
		swap(stack_a);
	if (ft_strcmp("sb", action) == 0 || ft_strcmp("ss", action) == 0)
		swap(stack_b);
	if (ft_strcmp("pa", action) == 0)
		push(stack_b, stack_a);
	if (ft_strcmp("pb", action) == 0)
		push(stack_a, stack_b);
	if (ft_strcmp("ra", action) == 0 || ft_strcmp("rr", action) == 0)
		rotate(stack_a);
	if (ft_strcmp("rb", action) == 0 || ft_strcmp("rr", action) == 0)
		rotate(stack_b);
	if (ft_strcmp("rra", action) == 0 || ft_strcmp("rrr", action) == 0)
		reverse_rotate(stack_a);
	if (ft_strcmp("rrb", action) == 0 || ft_strcmp("rrr", action) == 0)
		reverse_rotate(stack_b);
	ft_printf("%s\n", action);
}
