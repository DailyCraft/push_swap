/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:11:03 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/12/03 15:05:06 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap(t_list **stack)
{
	t_list	*second;
	t_list	*third;

	if (ft_lstsize(*stack) < 2)
		return (0);
	second = ft_lstgeti(*stack, 1);
	third = ft_lstgeti(*stack, 2);
	second->next = *stack;
	(*stack)->next = third;
	*stack = second;
	return (1);
}

static int	push(t_list **from, t_list **to)
{
	t_list	*moved;

	if (!*from)
		return (0);
	moved = *from;
	*from = (*from)->next;
	ft_lstadd_front(to, moved);
	return (1);
}

static int	rotate(t_list **stack)
{
	t_list	*moved;

	if (ft_lstsize(*stack) < 2)
		return (0);
	moved = *stack;
	*stack = (*stack)->next;
	moved->next = NULL;
	ft_lstadd_back(stack, moved);
	return (1);
}

static int	reverse_rotate(t_list **stack)
{
	size_t	size;
	t_list	*moved;
	t_list	*last;

	size = ft_lstsize(*stack);
	if (size < 2)
		return (0);
	last = ft_lstgeti(*stack, size - 2);
	moved = last->next;
	last->next = NULL;
	ft_lstadd_front(stack, moved);
	return (1);
}

void	execute(char *action, t_list **stack_a, t_list **stack_b)
{
	int	modified;
	
	modified = 0;
	if (ft_strcmp("sa", action) == 0 || ft_strcmp("ss", action) == 0)
		modified += swap(stack_a);
	if (ft_strcmp("sb", action) == 0 || ft_strcmp("ss", action) == 0)
		modified += swap(stack_b);
	if (ft_strcmp("pa", action) == 0)
		modified += push(stack_b, stack_a);
	if (ft_strcmp("pb", action) == 0)
		modified += push(stack_a, stack_b);
	if (ft_strcmp("ra", action) == 0 || ft_strcmp("rr", action) == 0)
		modified += rotate(stack_a);
	if (ft_strcmp("rb", action) == 0 || ft_strcmp("rr", action) == 0)
		modified += rotate(stack_b);
	if (ft_strcmp("rra", action) == 0 || ft_strcmp("rrr", action) == 0)
		modified += reverse_rotate(stack_a);
	if (ft_strcmp("rrb", action) == 0 || ft_strcmp("rrr", action) == 0)
		modified += reverse_rotate(stack_b);
	if (modified && get_out)
		ft_lstadd_back(get_out(), ft_lstnew(ft_strdup(action)));
}
