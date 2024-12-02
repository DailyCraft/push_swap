/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:56:02 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/12/02 14:15:56 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	send_b(t_list **stack, t_list **stack_b, int *bubble, int size)
{
	char	*better;
	int		i;

	better = better_rotation(*stack, 'a', bubble, size);
	i = 0;
	while (i < size)
	{
		while (!array_chr(bubble, size, (long)(*stack)->content))
			execute(better, stack, NULL);
		execute("pb", stack, stack_b);
		i++;
	}
}

static void	send_a(t_list **stack, t_list **stack_b, int *bubble, int size)
{
	int		min;
	int		max;
	char	*better;

	while (*stack_b)
	{
		min = min_rotations(*stack_b, bubble, 1);
		max = ft_min(min_rotations(*stack_b, bubble + size - 1, 1),
				min_rotations(*stack_b, bubble + size - 2, 2));
		if (min < max)
		{
			do_until(stack, stack_b, bubble[0],
				better_rotation(*stack_b, 'b', bubble, 1));
			execute("pa", stack, stack_b);
			execute("ra", stack, stack_b);
			bubble++;
			size--;
		}
		else
		{
			better = better_rotation(*stack_b, 'b', bubble + size - 2, 2);
			while ((long)(*stack_b)->content != bubble[size - 1]
					&& (long)(*stack_b)->content != bubble[size - 2])
				execute(better, stack, stack_b);
			execute("pa", stack, stack_b);
			if ((long)(*stack)->content == bubble[size - 1])
			{
				size--;
				if (ft_lstgeti(*stack, 1) && (long) ft_lstgeti(*stack, 1)->content == bubble[size - 1])
				{
					execute("sa", stack, stack_b);
					size--;
				}
			}
		}
	}
}

static void	sort_part(t_list **stack, t_list **stack_b, int *bubble, int size, int *start)
{
	send_b(stack, stack_b, bubble, size);
	if (start)
		do_until(stack, stack_b, *start,
			better_rotation(*stack, 'a', start, 1));
	send_a(stack, stack_b, bubble, size);
}

void	part_sort(t_list **stack, t_list **stack_b, int *bubble, int size)
{
	int	i;
	int	part_size;
	int	*last;

	i = 0;
	part_size = 0.06 * size + 18.75;
	while (i + part_size < size)
		i += part_size;
	last = NULL;
	while (i >= 0)
	{
		sort_part(stack, stack_b, bubble + i, ft_min(part_size, size - i), last);
		last = bubble + i;
		i -= part_size;
	}
	do_until(stack, stack_b, bubble[0],
		better_rotation(*stack, 'a', bubble, 1));
}
