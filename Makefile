# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qlefevre <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/07 16:19:21 by qlefevre          #+#    #+#              #
#    Updated: 2025/02/28 18:12:16 by quelefev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= push_swap
NAME2 	= my_checker
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -g2
RM 		= rm -rf
MAKEFLAGS	+= --no-print-directory

SRC_PATH = src/
OBJ_PATH = obj/
BONUS_PATH = bonus/

SRC			= actions.c \
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

B_SRC		= list_fonctions.c \
			rotate_commands.c \
			push_commands.c \
			swap_commands.c \
			check_error.c \
			get_next_line.c \
			get_next_line_utils.c \
			utils.c \
			fonctions.c \
			help_tri.c \
			double_commands.c

C_SRC		= checker.c

SRCS		= $(addprefix $(SRC_PATH), $(SRC))
OBJ			= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))
INCS		= -I ./includes/

B_SRCS		= $(addprefix $(SRC_PATH), $(B_SRC))
B_OBJ		= $(B_SRC:.c=.o)
B_OBJS		= $(addprefix $(OBJ_PATH), $(B_OBJ))

C_SRCS		= $(addprefix $(BONUS_PATH), $(C_SRC))
C_OBJ		= $(C_SRC:.c=.o)
C_OBJS		= $(addprefix $(OBJ_PATH), $(C_OBJ))

all: $(OBJ_PATH) $(NAME) 

$(OBJ_PATH)%.o: $(SRC_PATH)%.c 
		$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(OBJ_PATH)%.o: $(BONUS_PATH)%.c 
		$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(OBJ_PATH):
		mkdir $(OBJ_PATH)

$(NAME): $(OBJ_PATH) $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	
$(NAME2): $(OBJ_PATH) $(B_OBJS) $(C_OBJS)	
		$(CC) $(CFLAGS) $(B_OBJS) $(C_OBJS) -o $(NAME2)
		
bonus: $(NAME2)

clean:
	$(RM) $(OBJS) $(B_OBJS) $(OBJ_PATH)

fclean: clean
		$(RM) $(NAME) $(NAME2)

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


.PHONY: all clean fclean re bonus test2 test3 test5 test100 test500 test1000
