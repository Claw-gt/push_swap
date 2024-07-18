/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:17:30 by clagarci          #+#    #+#             */
/*   Updated: 2024/07/18 15:53:25 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
}					t_stack;

int to_number(int argc, char **argv);

int *parse_input (int argc, char *argv[]);

int	check_duplicates(int *array, int argc);

int partition(int *array, int low, int high);

void quick_sort(int *array, int low, int high);

int find_number(int *array, int number);

void stack_indexing(t_stack **stack, int *array);

void	ft_stckadd_back(t_stack **lst, t_stack *new);

t_stack	*ft_stcknew(int content);

t_stack	*ft_stcklast(t_stack *lst);

void sa(t_stack **stack_a);

void sb(t_stack **stack_b);

void ss(t_stack **stack_a, t_stack **stack_b);

void pa(t_stack **stack_a, t_stack **stack_b);

void pb(t_stack **stack_a, t_stack **stack_b);

void ra(t_stack **stack_a);

void rb(t_stack **stack_b);

void rr(t_stack **stack_a, t_stack **stack_b);

void rra(t_stack **stack_a);

void rrb(t_stack **stack_b);

void rrr(t_stack **stack_a, t_stack **stack_b);

t_list	*ft_lstnew(void *content);

t_list	*ft_lstlast(t_list *lst);

void	ft_lstadd_back(t_list **lst, t_list *new);
#endif
