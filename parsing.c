/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:25:57 by clagarci          #+#    #+#             */
/*   Updated: 2024/07/01 18:38:55 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>
//int	check_spaces(char **argv)

int *to_number(int argc, char **argv)
{
	int i;
    int j;
    int *num_array;

    j = 0;
	i = 0;
    // num_array = (int *)malloc(sizeof(int) * (argc - 1));
    // if (num_array == NULL)
    //     return (NULL);
	while (i++ < argc)
	{
        write(1, argv[i], sizeof(argv[i]));
		num_array[j] = ft_atoi(argv[i]);
	}
	return (num_array);
}

int check_duplicates()
{
    return (0);
}
