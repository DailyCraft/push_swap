/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:49:16 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/12/10 09:41:05 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	secure_atoi(char *str, int *err)
{
	unsigned int	result;
	int				neg;

	result = 0;
	neg = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		if (result * 10 + *str - '0' > (unsigned) MAX_INT + (neg == -1))
			return (*err = 1, 0);
		result = result * 10 + *str - '0';
		str++;
	}
	if (*str)
		return (*err = 1, 0);
	return (result * neg);
}

static int	populate_a(int argc, char **argv, t_list **stack)
{
	int		i;
	void	*temp;
	int		err;

	i = 1;
	while (i < argc)
	{
		temp = (void *)(long) secure_atoi(argv[i], (err = 0, &err));
		if (err || ft_lstindex(*stack, temp, NULL) != -1)
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
