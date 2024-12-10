/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:12:59 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/12/10 14:58:25 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sort(t_list *stack)
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

static void	push_swap(t_data *data)
{
	if (data->size <= 5)
		little_sort(&data->stack, &data->stack_b, data->size);
	else
		big_sort(&data->stack, &data->stack_b, data->size);
	print_execution(data);
	ft_lstclear(get_out(), free);
}

int	main(int argc, char **argv)
{
	t_data	data;

	init_stacks(argc, argv, &data.stack, &data.stack_b);
	data.size = ft_lstsize(data.stack);
	lst_to_index(data.stack, data.size);
	if (!is_sort(data.stack))
		push_swap(&data);
	ft_lstclear(&data.stack, NULL);
	ft_lstclear(&data.stack_b, NULL);
}
