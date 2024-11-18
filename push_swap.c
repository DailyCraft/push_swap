/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:12:59 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/11/18 22:53:50 by dvan-hum         ###   ########.fr       */
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
			return (0);
		}
		ft_lstadd_back(stack, ft_lstnew(temp));
		i++;
	}
	return (1);
}

/* static int	is_sort(t_list *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
} */

static void	push_swap(t_list **stack_a, t_list **stack_b)
{
	sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc == 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	if (!populate_a(argc, argv, &stack_a))
		return (0);
	push_swap(&stack_a, &stack_b);
	ft_lstclear(&stack_a, NULL);
	ft_lstclear(&stack_b, NULL);
}
