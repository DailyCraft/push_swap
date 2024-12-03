/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:56:02 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/12/03 13:51:29 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	send_b(t_list **stack, t_list **stack_b, int *bubble, int size)
{
	char	*better;
	int		i;

	better = better_rot(*stack, 'a', bubble, size);
	i = 0;
	while (i < size)
	{
		while (!array_chr(bubble, size, (long)(*stack)->content))
			execute(better, stack, NULL);
		execute("pb", stack, stack_b);
		i++;
	}
}

static void	send_a_max(t_list **stack, t_list **stack_b, int *bubble, int *size)
{
	char	*better;

	better = better_rot(*stack_b, 'b',
			bubble + ft_max(0, *size - 2), ft_min(*size, 2));
	while ((long)(*stack_b)->content != bubble[*size - 1]
			&& (long)(*stack_b)->content != bubble[*size - 2])
		execute(better, stack, stack_b);
	execute("pa", stack, stack_b);
	if ((long)(*stack)->content == bubble[*size - 1])
	{
		if (ft_lstgeti(*stack, 1) && *size >= 2
			&& (long) ft_lstgeti(*stack, 1)->content == bubble[*size - 2])
		{
			execute("sa", stack, stack_b);
			(*size)--;
		}
		(*size)--;
	}
}

static void	send_a(t_list **stack, t_list **stack_b, int *bubble, int size)
{
	int	min;
	int	max;

	while (*stack_b)
	{
		min = min_rotations(*stack_b, bubble, 1);
		max = min_rotations(*stack_b, bubble + size - 1, 1);
		if (size >= 2)
			max = ft_min(max, min_rotations(*stack_b, bubble + size - 2, 2));
		if (min < max)
		{
			do_until(stack, stack_b, bubble[0],
				better_rot(*stack_b, 'b', bubble, 1));
			execute("pa", stack, stack_b);
			execute("ra", stack, stack_b);
			bubble++;
			size--;
		}
		else
			send_a_max(stack, stack_b, bubble, &size);
	}
}

void	part_sort(t_list **stack, t_list **stack_b, int *bubble, int size)
{
	int	i;
	int	part_size;
	int	*last;

	i = 0;
	part_size = (0.07 * size + 19.78) + 0.5;
	while (i + part_size < size)
		i += part_size;
	last = NULL;
	while (i >= 0)
	{
		send_b(stack, stack_b, bubble + i, ft_min(part_size, size - i));
		if (last)
			do_until(stack, stack_b, *last, better_rot(*stack, 'a', last, 1));
		send_a(stack, stack_b, bubble + i, ft_min(part_size, size - i));
		last = bubble + i;
		i -= part_size;
	}
	do_until(stack, stack_b, bubble[0],
		better_rot(*stack, 'a', bubble, 1));
}
