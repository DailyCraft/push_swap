/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_filter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:50:20 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/12/09 16:06:54 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static int	remove_ra(t_list **lst, int size)
{
	t_list	*ra;
	int		i;

	ra = *lst;
	i = 0;
	while (ra && ft_strcmp(ra->content, "ra") == 0)
	{
		i++;
		if (i == size - 1)
		{
			while (*lst != ra)
				*lst = ft_lstdelone(*lst, free);
			ft_free_set(&ra->content, ft_strdup("rra"));
			ra = NULL;
			break ;
		}
		ra = ra->next;
	}
	return (i);
}

void	filter_redundant(t_list **out, int size)
{
	int		i;

	while (*out)
	{
		if (ft_strcmp((*out)->content, "ra") != 0)
		{
			out = &(*out)->next;
			continue ;
		}
		i = remove_ra(out, size);
		if (i < size - 1)
		{
			out = &(*out)->next;
		}
	}
}
