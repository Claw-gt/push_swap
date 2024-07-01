/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:14:23 by clagarci          #+#    #+#             */
/*   Updated: 2024/02/04 11:39:33 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	leaks(void){
	system("leaks -q a.out");
}

int	main(void)
{
	atexit(leaks);
//	printf("Input:%d Sol:%d\n",'h', isalpha('h'));
//	printf("Input:%c Sol:%d\n",'a',	ft_isalpha('a'));
				
//	printf("Input:%d Sol:%d\n", 53, isdigit(53));
//	printf("Input:%d Sol:%d\n", 53, ft_isdigit(53));

//	printf("Input:%d Sol:%d\n", 170, isalnum(170));
//	printf("Input:%d Sol:%d\n", 170, ft_isalnum(170));

//	printf("Input:%d Sol:%d\n", 0, isalnum(0));
//	printf("Input:%d Sol:%d\n", 0, ft_isalnum(0));

//	printf("Input:%d Sol:%d\n", 34, isprint(34));
//	printf("Input:%d Sol:%d\n", 34, ft_isprint(34));

//	printf("Input:%s Sol:%zu\n", "hola", strlen("hola"));
//	printf("Input:%s Sol:%zu\n", "hola", ft_strlen("hola"));

	char dest[] = "mundo";
	//char src[] = "hola";
	printf("length: %lu\n", ft_strlcpy(dest, "\0", 0));
	//printf("dest: %s", dest);
	//printf("length: %lu\n",strlcat(dest, src, 0));
	//printf("dest: %s", dest);
	//printf("length: %lu\n",ft_strlcat(dest, src, 0));
	//printf("dest: %s", dest);
	//ft_strlcat(dest, src, 0);*/

	/*//char buffer[5];
	char buffer2[5];
	//memset(buffer, 'a', 3);
	ft_memset(buffer2, 'a', 5);
	//printf("%s\n", buffer);
	printf("%s\n", buffer2);
	ft_bzero(buffer2 + 3, 1);
	printf("%s\n", buffer2);*/

	//char str1[5];
	//char csrc[100] = "Holaaquetal";
	//char *first, *second;
	//first = csrc;
	//second = csrc;
	//char str2[] = "Learning";
	//memcpy(0, str2, sizeof(str2));
//	printf("memcpy: %s\n", str1);
	//memcpy(csrc + 5, csrc, strlen(csrc) + 1);
	//printf("%s\n", csrc);
	//ft_memcpy(first + 8, first, 10);
	//printf("ft_memcpy: %s\n", first);
	//void *result = ft_memcpy(str1, str2, 5);
	//write(1, (char *)result, 5);
	//printf("%s\n", (char *)result);
	//printf("%s\n", str2);
	//printf("ft_memmove: %s\n", second);
	//ft_memcpy(str2+3, str2, sizeof(str2));
	//printf("ft_memcpy: %s\n", str2);
	//ft_memmove(str2+10, str2, sizeof(str2));
	//printf("ft_memmove: %s\n", str2);

	/*char str[5] = "World";
	char *toCpy = (char *)malloc(sizeof(char) * 4);
	toCpy = "hola";
	//printf("length %ld new: %s\n", ft_strlcpy(str, toCpy, 3), str);
	printf("%ld", ft_strlen(toCpy));
	printf("length %ld new: %s\n", ft_strlcat(str, toCpy, 2), str);*/

	//printf("%s",strchr("holea", 'e'));
	//printf("%s", ft_strchr("", '\0'));
	
	//printf("%s\n", strnstr("aaxx", "xx", 5));
	//printf("%s\n", ft_strnstr("aaxx", "xx", 5));
	
	//printf("%lu\n", strlcat("hello", NULL, 0));
	/*char	dest[15];
	ft_memset(dest, 'r', 15);
	printf("%zu", strlcat(dest, "lorem ipsum dolor sit amet", 5));
	write(1, "\n", 1);
	write(1, dest, 15);*/
	//printf("%d\n", atoi("+ 123"));
	//printf("%d\n", ft_atoi("  +123"));
	
//	printf("%p\n", calloc(8539, sizeof(int)));
	//printf("%s\n", (char *)ft_calloc(8539, sizeof(int)));
	/*char	find = 'h';
	char	str[] = "aloha";
	printf("%s\n", ft_memchr(str, find, ft_strlen((str))));*/
	return (0);
}
