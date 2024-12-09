/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:37:03 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/12/09 16:08:30 by dvan-hum         ###   ########.fr       */
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
	filter_redundant(get_out(), data->size);
	lst = *get_out();
	while (lst)
	{
		ft_printf("%s\n", lst->content);
		lst = lst->next;
	}
}

int	is_opposite(char *s1, char *s2)
{
	return ((ft_strcmp(s1, "pa") == 0 && ft_strcmp(s2, "pb") == 0)
		|| (ft_strcmp(s1, "pb") == 0 && ft_strcmp(s2, "pa") == 0)
		|| (ft_strcmp(s1, "ra") == 0 && ft_strcmp(s2, "rra") == 0)
		|| (ft_strcmp(s1, "rra") == 0 && ft_strcmp(s2, "ra") == 0)
		|| (ft_strcmp(s1, "rb") == 0 && ft_strcmp(s2, "rrb") == 0)
		|| (ft_strcmp(s1, "rrb") == 0 && ft_strcmp(s2, "rb") == 0));
}

char	*get_equivalent(char *s1, char *s2)
{
	if (ft_strcmp(s1, "sa") == 0 && ft_strcmp(s2, "sb") == 0)
		return ("ss");
	if (ft_strcmp(s1, "sb") == 0 && ft_strcmp(s2, "sa") == 0)
		return ("ss");
	if (ft_strcmp(s1, "ra") == 0 && ft_strcmp(s2, "rb") == 0)
		return ("rr");
	if (ft_strcmp(s1, "rb") == 0 && ft_strcmp(s2, "ra") == 0)
		return ("rr");
	if (ft_strcmp(s1, "rra") == 0 && ft_strcmp(s2, "rrb") == 0)
		return ("rrr");
	if (ft_strcmp(s1, "rrb") == 0 && ft_strcmp(s2, "rra") == 0)
		return ("rrr");
	return (NULL);
}
