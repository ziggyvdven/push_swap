# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 13:45:36 by zvandeven         #+#    #+#              #
#    Updated: 2023/04/19 13:09:46 by zvan-de-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RT	= \033[0m
G	= \033[0;32m

#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

# Program name
NAME 			= push_swap

# Compiler and flags
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -g

# others
RM				= rm -f
MAKE			= make

# Objects 
OBJS_PATH		= objs/
OBJS			= $(addprefix $(OBJS_PATH), $(SRCS_FILES:.c=.o))

# Sources
SRCS_PATH		= srcs/
SRCS			= $(addprefix $(SRCS_PATH), $(SRCS_FILES))

# Directories
BINDIR			= bin/

# Includes
INCLUDE_PATH	= includes/
INCS			= -I $(INCLUDE_PATH)
HEADER			= $(addprefix $(INCLUDES_PATH), $(HEADER_FILES))

# library and source files
LIBFT			= libft/libft.a
SRCS_FILES		= push_swap.c \
				checks.c \
				stacks.c \
				operations_a.c \
				operations_b.c \
				operations_ab.c\

#------------------------------------------------------------------------------#
#                                 RULES                                        #
#------------------------------------------------------------------------------#

all: $(NAME) 

$(NAME): $(OBJS_PATH) $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBFT) -I includes/push_swap.h
		@echo "$(G)\n -- $(NAME) made 🐙 --$(RT)"

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c 
	$(CC) $(CFLAGS) -o $@ -c $< 
	
$(OBJS_PATH):
	mkdir -p $(OBJS_PATH)
	
$(LIBFT):
	@$(MAKE) -C libft

clean:
	@rm -rf $(OBJS) $(OBJS_PATH)
	@$(MAKE) -C libft clean

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C libft fclean

re: fclean all

.PHONY:		all bonus clean fclean re