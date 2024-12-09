/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:10:15 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/12/09 16:23:58 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>

typedef struct s_data
{
	t_list	*stack;
	t_list	*stack_b;
	int		size;
}	t_data;

t_list	*lstdup(t_list *lst);
int		*array_chr(int *array, int size, int value);
void	lst_to_index(t_list *stack, int size);

void	execute(char *action, t_list **stack_a, t_list **stack_b);

void	init_stacks(int argc, char **argv, t_list **stack_a, t_list **stack_b);

int		rotations_count(t_list *stack, int *values, int size, int reverse);
int		min_rotations(t_list *stack, int *values, int size);
char	*better_rot(t_list *stack, char name, int *values, int size);

void	big_sort(t_list **stack, t_list **stack_b, int size);
void	little_sort(t_list **stack, t_list **stack_b, int size);

void	filter_opposite(void);
void	filter_equivalent(void);
void	filter_redundant(t_list **out, int size);

t_list	**get_out(void) __attribute__((weak));
void	print_execution(t_data *data);
int		is_opposite(char *s1, char *s2);
char	*get_equivalent(char *s1, char *s2);

#endif