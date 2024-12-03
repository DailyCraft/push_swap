/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:37:03 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/12/03 16:37:33 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	**get_out(void)
{
	static t_list	*out = NULL;

	return (&out);
}

void	print_execution(t_data *data)
{
	t_list	*lst;

	filter_opposite();
	filter_equivalent();
	filter_redundant(data->size);
	lst = *get_out();
	while (lst)
	{
		ft_printf("%s\n", lst->content);
		lst = lst->next;
	}
}
