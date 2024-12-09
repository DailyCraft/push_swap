/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:06:36 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/12/09 14:12:25 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotations_count(t_list *stack, int *values, int size, int reverse)
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
		if (array_chr(values, size, (long) ft_lstgeti(stack, i)->content))
			count++;
		actions++;
		if (!reverse)
			i++;
		else
			i--;
	}
	return (actions);
}

int	min_rotations(t_list *stack, int *values, int size)
{
	return (ft_min(
			rotations_count(stack, values, size, 0),
			rotations_count(stack, values, size, 1)
		));
}

char	*better_rot(t_list *stack, char name, int *values, int size)
{
	int			rot;
	const char	*rra = "rra";
	const char	*rrb = "rrb";

	rot = rotations_count(stack, values, size, 0);
	rot -= rotations_count(stack, values, size, 1);
	if (name == 'a')
		return ((char *) rra + (rot <= 0));
	else
		return ((char *) rrb + (rot <= 0));
}
