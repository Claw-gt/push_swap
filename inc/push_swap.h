/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:17:30 by clagarci          #+#    #+#             */
/*   Updated: 2024/08/20 17:33:35 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# ifndef DEBUG
#  define DEBUG 0
# endif
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				content;
	int				index;
	int				moves_a;
	int				moves_b;
	struct s_stack	*next;
}					t_stack;

int		stack_position(t_stack **stack, int number);

int		target_position(t_stack **stack_a, int stack_b_index);

int		initial_check(int argc, char **argv);

int		count_and_check(int num_args, char **argv);

int		find_max(t_stack *stack);

void	sort_stack(t_stack **stack_a);

void	*print_errors(void);

int		*parse_input(int arguments, int argc, char *argv[]);

int		check_duplicates(int *array, int arguments);

int		partition(int *array, int low, int high);

void	quick_sort(int *array, int low, int high);

int		find_number(int *array, int number);

void	stack_indexing(t_stack **stack, int *array);

void	ft_stckadd_back(t_stack **stck, t_stack *new);

t_stack	*ft_stcknew(int content);

t_stack	*ft_stcklast(t_stack *stck);

void	ft_stckclear(t_stack **stck);

int		ft_stcksize(t_stack *stck);

void	sa(t_stack **stack_a, int duplicate);

void	sb(t_stack **stack_b, int duplicate);

void	ss(t_stack **stack_a, t_stack **stack_b);

void	pa(t_stack **stack_a, t_stack **stack_b);

void	pb(t_stack **stack_a, t_stack **stack_b);

void	ra(t_stack **stack_a, int duplicate);

void	rb(t_stack **stack_b, int duplicate);

void	rr(t_stack **stack_a, t_stack **stack_b);

void	rra(t_stack **stack_a, int duplicate);

void	rrb(t_stack **stack_b, int duplicate);

void	rrr(t_stack **stack_a, t_stack **stack_b);

void	sort_three(t_stack **stack_a);

void	sort_more(t_stack **stack_a);

void	sort_stack(t_stack **stack_a);

int		check_sorted(t_stack *stack);

int		str_isdigit(char **string, int arguments);

int		ft_atoi_optim(const char *nptr, int *error_flag);

int		contains_num(char *string);

int		count_moves(int position, int size_stack);

t_stack	*find_optim(int init, int target, t_stack **stack_b, t_stack **stack_a);

void	moves(t_stack *optim_node, t_stack **stack_a, t_stack **stack_b);

void	*free_array(char **arr, int num);

void	print_stack(t_stack **stack_a);
#endif
