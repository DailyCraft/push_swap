/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:37:03 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/12/02 11:46:12 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_opposite(char *s1, char *s2)
{
	return ((ft_strcmp(s1, "pa") == 0 && ft_strcmp(s2, "pb") == 0)
		|| (ft_strcmp(s1, "pb") == 0 && ft_strcmp(s2, "pa") == 0)
		|| (ft_strcmp(s1, "ra") == 0 && ft_strcmp(s2, "rra") == 0)
		|| (ft_strcmp(s1, "rra") == 0 && ft_strcmp(s2, "ra") == 0)
		|| (ft_strcmp(s1, "rb") == 0 && ft_strcmp(s2, "rrb") == 0)
		|| (ft_strcmp(s1, "rrb") == 0 && ft_strcmp(s2, "rb") == 0));
}

void	print_execution(char *action)
{
	static char	*last = NULL;

	if (!last)
	{
		last = action;
		return ;
	}
	if (!action)
		ft_printf("%s\n", last);
	else if (ft_strcmp(action, "ra") == 0 && ft_strcmp(last, "rb") == 0)
		ft_printf("rr\n");
	else if (ft_strcmp(action, "rb") == 0 && ft_strcmp(last, "ra") == 0)
		ft_printf("rr\n");
	else if (ft_strcmp(action, "rra") == 0 && ft_strcmp(last, "rrb") == 0)
		ft_printf("rrr\n");
	else if (ft_strcmp(action, "rrb") == 0 && ft_strcmp(last, "rra") == 0)
		ft_printf("rrr\n");
	else if (!is_opposite(action, last))
	{
		ft_printf("%s\n", last);
		last = action;
	}
	if (last != action)
		last = NULL;
}

void	execute(char *action, t_list **stack_a, t_list **stack_b)
{
	execute_hidden(action, stack_a, stack_b);
	print_execution(action);
}
