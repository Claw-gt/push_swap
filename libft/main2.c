/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 19:39:47 by clagarci          #+#    #+#             */
/*   Updated: 2024/02/04 12:54:19 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>

void	leaks(void){
	system("leaks -q a.out");
}

char ft_strupcase(unsigned int i, char c)
{
	if (i == 0)
		return (c);
	if ((c <= 'z') && (c >= 'a'))
		c -= 32;
	return (c);
}

void ft_print(unsigned int i, char *c)
{
	printf("i: %d, c: %c\n", i, *c);
}
int main(void)
{

	atexit(leaks);
	//char	str[] = "hello !";
	char	str2[] = "hepu";
	//printf("%s\n", ft_substr(str, 6,20));
	//printf("%s\n", ft_strjoin(str, str2));
	char *trim = ft_strtrim("\0", str2);
	printf("%s\n", trim);
	free (trim);
	/*char **arr = ft_split(str, ' ');
	int n;
	for (n = 0; arr[n]; n++){
		printf("%s\n", arr[n]);
		free(arr[n]);
	}
	free(arr);*/
	//sleep(5);	
	/*int num = atoi("");
	printf("%d", num);*/
	//char *str = ft_itoa(-4324);
	//printf("final: %s\n", str);
	//free(str);
	/*char *str = "hola";
	char *result = ft_strmapi(str, ft_strupcase);
	free(result);
	printf("result: %s\n", result);
	ft_striteri(str, ft_print);*/
	//ft_putchar_fd('3', 1);
	//ft_putstr_fd("hola", 1);
	//ft_putendl_fd("hola", 1);
	//ft_putnbr_fd(-21474, 1);
	return (0);
}
