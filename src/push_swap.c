/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:12:59 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/12/03 16:36:53 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_efficiency(t_sort_func sort, t_data *data)
{
	t_list	*dup;
	int		iterations;

	dup = lstdup(data->stack);
	sort(&dup, &data->stack_b, data->bubble, data->size);
	filter_opposite();
	filter_equivalent();
	iterations = ft_lstsize(*get_out());
	ft_lstclear(&dup, NULL);
	ft_lstclear(get_out(), free);
	return (iterations);
}

static void	push_swap(t_data *data)
{
	int			most_efficient;
	t_sort_func	effficient;
	int			temp;

	most_efficient = get_efficiency(part_sort, data);
	effficient = part_sort;
	temp = get_efficiency(radix_sort, data);
	if (temp < most_efficient)
	{
		effficient = radix_sort;
		most_efficient = temp;
	}
	if (data->size < 5)
	{
		temp = get_efficiency(little_sort, data);
		if (temp < most_efficient || 1)
		{
			effficient = little_sort;
			most_efficient = temp;
		}
	}
	effficient(&data->stack, &data->stack_b, data->bubble, data->size);
	print_execution(data);
	ft_lstclear(get_out(), free);
}

int	main(int argc, char **argv)
{
	t_data	data;

	init_stacks(argc, argv, &data.stack, &data.stack_b);
	data.size = ft_lstsize(data.stack);
	data.bubble = lst_array(data.stack, data.size);
	array_sort(data.bubble, data.size);
	push_swap(&data);
	ft_lstclear(&data.stack, NULL);
	ft_lstclear(&data.stack_b, NULL);
	free(data.bubble);
}
