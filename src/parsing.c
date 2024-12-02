/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:49:16 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/12/02 11:27:38 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	*parse_elem(char *arg, int *err)
{
	int		result;
	char	*temp;

	result = ft_atoi(arg);
	temp = ft_itoa(result);
	if (ft_strcmp(arg, temp) != 0)
	{
		*err = 1;
		free(temp);
		return (0);
	}
	free(temp);
	return ((void *)(long) result);
}

static int	populate_a(int argc, char **argv, t_list **stack)
{
	int		i;
	void	*temp;
	int		err;

	i = 1;
	while (i < argc)
	{
		temp = parse_elem(argv[i], (err = 0, &err));
		if (err || ft_lstcontains(*stack, temp, NULL))
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
