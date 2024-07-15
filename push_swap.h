/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:17:30 by clagarci          #+#    #+#             */
/*   Updated: 2024/07/15 18:50:04 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_stack
{
    int	*content;
	struct s_stack	*next;
    struct s_stack  *prev;
}	t_stack;

int to_number(int argc, char **argv);

int *parse_input (int argc, char *argv[]);

int	check_duplicates(int *array);
#endif
