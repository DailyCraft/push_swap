/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:10:15 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/12/02 11:14:15 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>

void	init_stacks(int argc, char **argv, t_list **stack_a, t_list **stack_b);

void	execute_hidden(char *action, t_list **stack_a, t_list **stack_b);
void	execute(char *action, t_list **stack_a, t_list **stack_b);
void	sort(t_list **stack, t_list **stack_b);
void	print_execution(char *action);

int		*lst_array(t_list *lst, int size);
void	array_sort(int *array, int size);
int		*array_chr(int *array, int size, int value);

int		rotations_count(t_list *stack, int *bubble, int size, int reverse);
int		min_rotations(t_list *stack, int *bubble, int size);
char	*better_rotation(t_list *stack, char name, int *bubble, int size);
void	do_until(t_list **stack, t_list **stack_b, int value, char *action);

#endif