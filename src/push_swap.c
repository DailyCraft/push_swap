/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:12:59 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/12/09 16:24:22 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	push_swap(&data);
	ft_lstclear(&data.stack, NULL);
	ft_lstclear(&data.stack_b, NULL);
}
