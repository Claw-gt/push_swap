/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:25:57 by clagarci          #+#    #+#             */
/*   Updated: 2024/07/02 17:10:13 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "printf/ft_printf.h"
#include <stdio.h>
//int	check_spaces(char **argv)

int	ft_atoi_optim(const char *nptr)
{
	int	i;
	int	minus;
	int	num;

	minus = 0;
	i = 0;
	num = 0;
	while (nptr[i] == ' ' || (nptr[i] > 8 && nptr[i] < 14))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			minus = 1;
		i++;
	}
	while (nptr[i] != '\0' && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		num *= 10;
		num += nptr[i] - '0';
		i++;
	}
    if (nptr[i] != 32 && (nptr[i] < '0' || nptr[i] > '9'))
	{
        return (-1);
	}
	if (minus)
		num *= -1;
	printf("num: %d\n", num);
	return (num);
}

// int *to_number(int argc, char **argv)
// {
// 	int i;
//     int j;
//     int *num_array;

//     j = 0;
// 	i = 0;
//     num_array = (int *)malloc(sizeof(int) * (argc - 1));
//     if (num_array == NULL)
// 	{
//         return (NULL);
// 	}
// 	while (i++ < argc)
// 	{
//         write(1, argv[i], sizeof(argv[i]));
// 		num_array[j] = ft_atoi(argv[i]);
// 	}
// 	return (num_array);
// }

void	*print_errors(void)
{
    //ft_printf("Error\n");
	printf("Error\n");
	return (NULL);
}

void	*parse_input (int argc, char *argv[])
{
	int	i;
	//int	j;

	//j = 0;
	i = 1;
    if (argc < 2)
        print_errors();
    else
	{
		/*Comprobar que los argumentos sean números enteros no mezclados con letras. Atoi optimizado*/
		printf("num args: %d\n", argc);
		while (i < argc)
		{
			printf("args:%s",argv[i]);
			/*Comprobar primero que los argumentos solo incluyan '"' " " '-' '+' o números?*/
			if (ft_atoi_optim(argv[i]) == -1)
				return (print_errors());
			i++;
		}
	}
	return (0);
}

int	check_duplicates()
{
    return (0);
}
