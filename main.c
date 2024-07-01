/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:10:25 by clagarci          #+#    #+#             */
/*   Updated: 2024/07/01 17:26:00 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

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

int	main(int argc, char **argv)
{
	if (argc > 1) //el número de args debe ser mayor que 1, pue el primero es el ejecutable
	{
		to_number(argc, argv);		
		//check_duplicates(argv);
	}
	return (0);
}
