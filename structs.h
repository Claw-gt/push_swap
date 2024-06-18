/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:17:36 by clagarci          #+#    #+#             */
/*   Updated: 2024/06/18 20:27:48 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_list
{
    int				content;
    struct s_list	*next;
    struct s_list	*prev;
}	t_list;

typedef struct s_stack
{
    int	*stack;
    int	size;
}	t_stack;

typedef struct s_data
{
    t_stack	a;
    t_stack	b;
}	t_data;
#endif