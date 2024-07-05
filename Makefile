# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 19:23:32 by clagarci          #+#    #+#              #
#    Updated: 2024/07/05 18:16:44 by clagarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBS = -l:libft.a -l:libftprintf.a

MY_SOURCES = main.c parsing.c

MY_OBJECTS = $(MY_SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -I./libft -I./printf
LDFLAGS = -L./libft -L./printf

GREEN = \033[0;32m
RED = \033[0;31m

all: $(NAME)

$(NAME): $(MY_OBJECTS)
		@make -C libft --no-print-directory
		@make -C printf --no-print-directory
		$(CC) $(CFLAGS) $(MY_OBJECTS) -o $(NAME) $(LDFLAGS) $(LIBS) 
		@echo "\n Compilation of $(NAME):  $(GREEN)SUCCESS!"
clean:
	rm -f $(MY_OBJECTS)
	@echo "\nObjects files of push_swap deleted!"
	@make clean -C libft --no-print-directory
	@echo "\nObjects files of libft deleted!"
	@make clean -C printf --no-print-directory
	@echo "\nObjects files of printf deleted!"

fclean: clean
	rm -f $(NAME)
	@echo "\n$(NAME) deleted!"
	@make fclean -C libft --no-print-directory
	@make fclean -C printf --no-print-directory


re: fclean all

.PHONY: all clean fclean re