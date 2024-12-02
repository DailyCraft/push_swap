/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:52:23 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/12/02 11:48:32 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	is_legal(char *line)
{
	return (
		ft_strcmp(line, "sa") == 0
		|| ft_strcmp(line, "sb") == 0
		|| ft_strcmp(line, "ss") == 0
		|| ft_strcmp(line, "pa") == 0
		|| ft_strcmp(line, "pb") == 0
		|| ft_strcmp(line, "ra") == 0
		|| ft_strcmp(line, "rb") == 0
		|| ft_strcmp(line, "rr") == 0
		|| ft_strcmp(line, "rra") == 0
		|| ft_strcmp(line, "rrb") == 0
		|| ft_strcmp(line, "rrr") == 0
	);
}

static char	*sort_status(t_list *stack, t_list *stack_b)
{
	if (stack_b)
		return ("KO");
	if (!stack || !stack->next)
		return ("OK");
	while (stack->next)
	{
		if ((long) stack->content >= (long) stack->next->content)
			return ("KO");
		stack = stack->next;
	}
	return ("OK");
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*line;

	init_stacks(argc, argv, &stack_a, &stack_b);
	line = get_next_line(0);
	while (line)
	{
		line = ft_free_set((void **) &line,
				ft_substr(line, 0, ft_strlen(line) - 1));
		if (!is_legal(line))
		{
			ft_printf("Invalid line: '%s'\n", line);
			ft_free_set((void **) &line, get_next_line(0));
			while (line)
				ft_free_set((void **) &line, get_next_line(0));
			ft_lstclear(&stack_a, NULL);
			ft_lstclear(&stack_b, NULL);
			return (0);
		}
		execute_hidden(line, &stack_a, &stack_b);
		ft_free_set((void **) &line, get_next_line(0));
	}
	ft_printf("%s\n", sort_status(stack_a, stack_b));
	(ft_lstclear(&stack_a, NULL), ft_lstclear(&stack_b, NULL));
}
