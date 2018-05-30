# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkrause- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/29 21:12:01 by dkrause-          #+#    #+#              #
#    Updated: 2018/05/29 21:12:02 by dkrause-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS_PATH = sources
SRCS_NAME =	ft_printf.c \
			ft_parse_format.c \
			handle_num.c \
			handle_char.c \
			handle_struc.c \
			get_va_arg.c \
			handle_flags.c \
			handle_precision.c

SRCS = $(addprefix $(SRCS_PATH)/,$(SRCS_NAME))

OBJS_PATH = objects
OBJS_NAME = $(SRCS_NAME:.c=.o)
OBJS = $(addprefix $(OBJS_PATH)/,$(OBJS_NAME))

INCLUDES_PATH = include
INCLUDES_NAME = ft_printf.h
INCLUDES = $(addprefix $(INCLUDES_PATH)/,$(INCLUDE_NAME))

#CFLAGS = -Wall -Werror -Wextra
LIB = libft/libft.a
	
.PHONY: all, clean, fclean, re

all: $(NAME)

libftcomp:
	@make all -C libft/

$(NAME): libftcomp $(OBJS) $(LIB)
	libtool -static -o $(NAME) $(LIB) $(OBJS)
	@echo "\033[32;1mCompilation completed!\033[0m"

$(OBJS): $(OBJS_PATH) $(SRCS) $(INCLUDES_PATH)
	@gcc -c $(SRCS)
	@mv $(OBJS_NAME) $(OBJS_PATH)

$(OBJS_PATH):
	@mkdir $(OBJS_PATH) 2> /dev/null || true

$(INCLUDES_PATH):
	@mkdir $(INCLUDES_PATH) 2> /dev/null || true
	@mv $(INCLUDE_NAME) $(INCLUDES_PATH)

clean:
	@make clean -C libft/
	@rm -f $(OBJS)
	@rmdir $(OBJS_PATH) 2> /dev/null || true
	@echo "\033[32;2m Cleaned successfully!\033[0m"

fclean: clean
	@make fclean -C libft/
	@rm -f $(NAME)
	@echo "\033[32;2m Fcleaned successfully!\033[0m"

re: fclean all
