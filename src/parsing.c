/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:49:16 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/12/13 21:58:39 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	populate_a(int argc, char **argv, t_list **stack)
{
	int		i;
	void	*temp;
	int		unclear;

	i = 1;
	while (i < argc)
	{
		temp = (void *)(long) ft_clear_atoi(argv[i], &unclear);
		if (unclear || ft_lstindex(*stack, temp, NULL) != -1)
		{
			ft_dprintf(2, "Error\n");
			ft_lstclear(stack, NULL);
			return (0);
		}
		ft_lstadd_back(stack, ft_lstnew(temp));
		i++;
	}
	return (1);
}

void	init_stacks(int argc, char **argv, t_list **stack_a, t_list **stack_b)
{
	if (argc == 1)
		exit(0);
	*stack_a = NULL;
	*stack_b = NULL;
	if (!populate_a(argc, argv, stack_a))
		exit(0);
}
