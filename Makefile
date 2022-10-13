# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qlefevre <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/07 16:19:21 by qlefevre          #+#    #+#              #
#    Updated: 2022/10/13 14:41:38 by qlefevre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra



SRCS		= actions.c \
			check_error.c \
			cost.c \
			double_commands.c \
			fonctions.c \
			help_tri.c \
			list_fonctions.c \
			manage_pile.c \
			push_commands.c \
			rotate_commands.c \
			swap_commands.c \
			tri.c \
			utils.c

OBJS		= $(SRCS:.c=.o)

RM 			:= rm -rf
MAKEFLAGS	+= --no-print-directory
all: $(NAME) 

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:

	$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: 
		$(MAKE) fclean
		$(MAKE) all

test2:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-100 -n 2))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test3:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-100 -n 3))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test5:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 5))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test100:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 100))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test500:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 500))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test1000:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 1000))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l


.PHONY: all clean fclean re test2 test3 test5 test100 test500 test1000
