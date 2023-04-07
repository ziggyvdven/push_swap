# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 13:45:36 by zvandeven         #+#    #+#              #
#    Updated: 2023/04/06 20:52:13 by zvan-de-         ###   ########.fr        #
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

# Objects are all .o files
OBJS			= $(addprefix $(BINDIR), $(SRCS:.c=.o))
OBJ_FILES		= $(SRC_FILES:.c=.o)

# Directories
BINDIR			= bin/

# Includes
INCS			= -I ./includes/

# library and source files
LIBFT			= libft/libft.a
SRCS			= push_swap.c \
				checks.c \
				stacks.c \


#------------------------------------------------------------------------------#
#                                 RULES                                        #
#------------------------------------------------------------------------------#

all: $(NAME) 

$(NAME): $(BINDIR) $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(LIBFT) -o $@ $(OBJS)
		@echo "$(G)\n -- $(NAME) made 🐙 --$(RT)"

$(BINDIR):
	mkdir $(BINDIR)
	
$(BINDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) -c -o $@ $<
	
$(LIBFT):
	@$(MAKE) -C libft

clean:
	@$(RM) $(OBJS)
	@$(RM) -r $(BINDIR)
	@$(MAKE) -C libft clean

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C libft fclean

re: fclean all

.PHONY:		all bonus clean fclean re