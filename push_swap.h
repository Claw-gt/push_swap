/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:17:30 by clagarci          #+#    #+#             */
/*   Updated: 2024/07/17 18:17:29 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

int to_number(int argc, char **argv);

int *parse_input (int argc, char *argv[]);

int	check_duplicates(int *array, int argc);

void sa(t_list **stack_a);

void sb(t_list **stack_b);

void ss(t_list **stack_a, t_list **stack_b);

void pa(t_list **stack_a, t_list **stack_b);

void pb(t_list **stack_a, t_list **stack_b);

void ra(t_list **stack_a);

void rb(t_list **stack_b);

void rr(t_list **stack_a, t_list **stack_b);

void rra(t_list **stack_a);

void rrb(t_list **stack_b);

void rrr(t_list **stack_a, t_list **stack_b);

t_list	*ft_lstnew(void *content);

t_list	*ft_lstlast(t_list *lst);

void	ft_lstadd_back(t_list **lst, t_list *new);
#endif
