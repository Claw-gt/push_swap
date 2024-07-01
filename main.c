/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:10:25 by clagarci          #+#    #+#             */
/*   Updated: 2024/07/01 18:41:43 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc > 1 && argc <= 100) //el número de args debe ser mayor que 1, pues el primero es el ejecutable
	{
		to_number(argc, argv);		
		//check_duplicates(argv);
	}
	return (0);
}
