/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_sort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:06:36 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/12/02 19:43:02 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotations_count(t_list *stack, int *bubble, int size, int reverse)
{
	int	actions;
	int	i;
	int	count;

	actions = 0;
	if (!reverse)
		i = 0;
	else
		i = ft_lstsize(stack) - 1;
	count = 0;
	while (count < size && i >= 0 && i < ft_lstsize(stack))
	{
		if (array_chr(bubble, size, (long) ft_lstgeti(stack, i)->content))
			count++;
		actions++;
		if (!reverse)
			i++;
		else
			i--;
	}
	return (actions);
}

int	min_rotations(t_list *stack, int *bubble, int size)
{
	return (ft_min(
			rotations_count(stack, bubble, size, 0),
			rotations_count(stack, bubble, size, 1)
		));
}

char	*better_rot(t_list *stack, char name, int *bubble, int size)
{
	int			rot;
	const char	*rra = "rra";
	const char	*rrb = "rrb";

	rot = rotations_count(stack, bubble, size, 0);
	rot -= rotations_count(stack, bubble, size, 1);
	if (name == 'a')
		return ((char *) rra + (rot <= 0));
	else
		return ((char *) rrb + (rot <= 0));
}

void	do_until(t_list **stack, t_list **stack_b, int value, char *action)
{
	while ((!*stack || (long)(*stack)->content != value)
			&& (!*stack_b || (long)(*stack_b)->content != value))
		execute(action, stack, stack_b);
}
