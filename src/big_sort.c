/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 07:48:04 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/12/09 11:59:32 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*ft_range(int from, int to)
{
	int	*range;
	int	i;

	range = malloc((to - from) * sizeof(int));
	i = 0;
	while (i < to - from)
	{
		range[i] = from + i;
		i++;
	}
	return (range);
}

static void	send_b(t_list **stack, t_list **stack_b, int size, int part_size)
{
	int		send_count;

	send_count = 0;
	while (*stack)
	{
		if (ft_abs(size / 2 - (long)(*stack)->content)
			< (part_size + send_count) / 2)
		{
			execute("pb", stack, stack_b);
			if ((long)(*stack_b)->content < size / 2)
				execute("rb", NULL, stack_b);
			send_count++;
		}
		else
			execute("ra", stack, NULL);
	}
}

static void	rotate_b(t_list **stack_b, int size, int *range)
{
	char	*better;

	if (min_rotations(*stack_b, range + ft_max(size - 2, 0), ft_min(2, size))
		<= min_rotations(*stack_b, range + size - 1, 1))
	{
		better = better_rot(*stack_b, 'b',
				range + ft_max(size - 2, 0), ft_min(size, 2));
		while ((long)(*stack_b)->content < size - 2)
			execute(better, NULL, stack_b);
	}
	else
	{
		better = better_rot(*stack_b, 'b',
				range + size - 1, 1);
		while ((long)(*stack_b)->content < size - 1)
			execute(better, NULL, stack_b);
	}
}

static void	send_a(t_list **stack, t_list **stack_b, int size)
{
	int	*range;

	range = ft_range(0, size);
	while (*stack_b)
	{
		rotate_b(stack_b, size, range);
		execute("pa", stack, stack_b);
		if ((long)(*stack)->content == size - 1)
		{
			size--;
			if ((*stack)->next && (*stack)->next->content < (*stack)->content)
			{
				execute("sa", stack, NULL);
				size--;
			}
		}
	}
	free(range);
}

void	big_sort(t_list **stack, t_list **stack_b, int *bubble, int size)
{
	lst_to_index(*stack, bubble, size);
	send_b(stack, stack_b, size, 0.04 * size + 11.25);
	send_a(stack, stack_b, size);
}
