# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jquil <jquil@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 15:45:16 by jquil             #+#    #+#              #
#    Updated: 2023/01/26 11:44:10 by jquil            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Name		:=	push_swap

SRC_DIR		:=
SRCS		:=	\
		push_swap.c			\
		operate.c			\
		operate_double.c	\
		swap.c				\
		Libft/ft_lstadd_back.c		\
		Libft/ft_lstadd_front.c		\
		Libft/ft_lstnew.c			\
		printf/ft_printf.c
SRCS 		:=	$(SRCS:%=$(SRC_DIR)/%)
BUILD_DIR	:=	.build
OBJS		:=	$(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS		:=	$(OBJS:.o=.d)

CC			:=	clang
CFLAGS		:=	-Wall -Wextra -Werror -g3
CPPFLAGS	:=	-MMD -MP -I include
AR			:=	ar
ARFLAGS		:=	-r -c -s

#------------------------------------------------------------------

RM			:= rm -f
MAKEFLAGS	+= --no-print-directory
DIR_DUP		= mkdir -p $(@D)

#------------------------------------------------------------------

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	$(info CREATED $(NAME))

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	$(info CREATED $@)

-include $(DEPS)

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

#------------------------------------------------------------------

.PHONY: clean fclean re
.SILENT:
