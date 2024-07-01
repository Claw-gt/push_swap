/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:25:57 by clagarci          #+#    #+#             */
/*   Updated: 2024/07/01 17:22:22 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
//int	check_spaces(char **argv)

int to_number(int argc, char **argv)
{
	int i;

	i = 0;
	while (i++ < argc)
	{
		ft_atoi(argv[i]);
	}
	return (0);
}

int check_duplicates()
{
    return (0);
}
