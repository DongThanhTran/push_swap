# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dtran <dtran@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2022/02/28 13:28:19 by dtran         #+#    #+#                  #
#    Updated: 2022/05/27 15:11:00 by dtran         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
LIBFT_DIR	=	./libft
LIBFT		=	./libft/libft.a
INCLUDE		=	-I ./libft
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

SRCS	=	main.c \
			operations/push.c \
			operations/rotate.c \
			operations/swap.c \
			operations/reverse.c \
			utils/utils.c \
			utils/quicksort.c \
			utils/is_sorted.c \

OBJ		=	$(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $^ $(CFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(INCLUDE) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all, bonus, clean, fclean, re
