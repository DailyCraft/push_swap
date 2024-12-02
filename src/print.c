/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:37:03 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/12/02 13:50:39 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	**get_out(void)
{
	static t_list	*out = NULL;

	return (&out);
}

void	print_execution(void)
{
	t_list	*lst;

	filter_opposite();
	filter_equivalent();
	lst = *get_out();
	while (lst)
	{
		ft_printf("%s\n", lst->content);
		lst = lst->next;
	}
}
