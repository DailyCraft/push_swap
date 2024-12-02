/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_filter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:50:20 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/12/02 13:50:44 by dvan-hum         ###   ########.fr       */
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

void	filter_opposite(void)
{
	t_list	**lst;
	int		modified;

	modified = 0;
	lst = get_out();
	while (*lst && (*lst)->next)
	{
		if (is_opposite((*lst)->content, (*lst)->next->content))
		{
			*lst = ft_lstdelone(*lst, free);
			*lst = ft_lstdelone(*lst, free);
			if (!*lst)
				return ;
			modified = 1;
		}
		lst = &(*lst)->next;
	}
	if (modified)
		filter_opposite();
}

static char	*get_equivalent(char *s1, char *s2)
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

void	filter_equivalent(void)
{
	t_list	**lst;
	int		modified;
	char	*equivalent;

	modified = 0;
	lst = get_out();
	while (*lst && (*lst)->next)
	{
		equivalent = get_equivalent((*lst)->content, (*lst)->next->content);
		if (equivalent)
		{
			ft_free_set((void **) &(*lst)->content, ft_strdup(equivalent));
			(*lst)->next = ft_lstdelone((*lst)->next, free);
			modified = 1;
		}
		lst = &(*lst)->next;
	}
	if (modified)
		filter_equivalent();
}
