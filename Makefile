# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 19:23:32 by clagarci          #+#    #+#              #
#    Updated: 2024/08/19 18:14:25 by clagarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBS = -lft
LIBDIR = libft/

MY_SOURCES = src/push_swap.c src/parsing.c src/operations/push.c src/operations/swap.c src/operations/rotate.c src/operations/reverse_rotate.c \
			src/linked_stacks.c src/utils.c src/indexing.c src/sorting/sort_three.c src/sorting/sort_more.c src/sorting/sort.c src/positioning.c src/sorting/optimize_moves.c

MY_OBJECTS = $(MY_SOURCES:.c=.o)

CC = gcc
CFLAGS += -Wall -Wextra -Werror -fsanitize=address
LDFLAGS = -L ./libft

GREEN = \033[0;32m
RED = \033[0;31m

all: $(NAME)

$(NAME): $(MY_OBJECTS)
		make -C $(LIBDIR)
		make bonus -C $(LIBDIR)
		$(CC) $(CFLAGS) $(MY_OBJECTS) -o $(NAME) $(LDFLAGS) $(LIBS)
		@echo "\n Compilation of $(NAME):  $(GREEN)SUCCESS!"

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(MY_OBJECTS)
	@echo "\nObjects files of push_swap deleted!"
	@make clean -C libft --no-print-directory
	@echo "\nObjects files of libft deleted!"

fclean: clean
	rm -f $(NAME)
	@echo "\n$(NAME) deleted!"
	@make fclean -C libft --no-print-directory

re: fclean all

.PHONY: all clean fclean re