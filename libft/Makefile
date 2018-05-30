# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkrause- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/28 21:23:58 by dkrause-          #+#    #+#              #
#    Updated: 2018/02/28 21:24:01 by dkrause-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
PATH_SRC = ./
PATH_OBJ = ./

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I ./includes/

SRC = 	$(PATH_SRC)ft_strlen.c \
		$(PATH_SRC)ft_strdup.c \
		$(PATH_SRC)ft_strcpy.c\
	  	$(PATH_SRC)ft_strncpy.c \
	  	$(PATH_SRC)ft_strcat.c \
	  	$(PATH_SRC)ft_strncat.c \
	  	$(PATH_SRC)ft_strlcat.c \
	  	$(PATH_SRC)ft_strchr.c \
	  	$(PATH_SRC)ft_strrchr.c\
	  	$(PATH_SRC)ft_isalpha.c \
	  	$(PATH_SRC)ft_isdigit.c \
	  	$(PATH_SRC)ft_isalnum.c\
	  	$(PATH_SRC)ft_isascii.c \
	  	$(PATH_SRC)ft_isprint.c \
	  	$(PATH_SRC)ft_toupper.c \
	  	$(PATH_SRC)ft_tolower.c \
	  	$(PATH_SRC)ft_strstr.c \
	  	$(PATH_SRC)ft_memset.c \
	  	$(PATH_SRC)ft_bzero.c \
	  	$(PATH_SRC)ft_memcpy.c \
	  	$(PATH_SRC)ft_memccpy.c\
	  	$(PATH_SRC)ft_memmove.c \
	  	$(PATH_SRC)ft_memchr.c \
	  	$(PATH_SRC)ft_memcmp.c \
	  	$(PATH_SRC)ft_strcmp.c \
	  	$(PATH_SRC)ft_strncmp.c \
	  	$(PATH_SRC)ft_strnstr.c\
	  	$(PATH_SRC)ft_atoi.c \
	  	$(PATH_SRC)ft_memalloc.c \
	  	$(PATH_SRC)ft_memdel.c \
	  	$(PATH_SRC)ft_strnew.c \
	  	$(PATH_SRC)ft_strdel.c \
	  	$(PATH_SRC)ft_strclr.c \
	  	$(PATH_SRC)ft_striter.c \
	  	$(PATH_SRC)ft_striteri.c \
	  	$(PATH_SRC)ft_strmap.c \
	  	$(PATH_SRC)ft_strmapi.c \
	  	$(PATH_SRC)ft_strequ.c \
	  	$(PATH_SRC)ft_strnequ.c \
	  	$(PATH_SRC)ft_strsub.c \
	  	$(PATH_SRC)ft_strjoin.c \
	  	$(PATH_SRC)ft_strtrim.c \
	  	$(PATH_SRC)ft_strsplit.c \
	  	$(PATH_SRC)ft_itoa.c \
	  	$(PATH_SRC)ft_putchar.c \
	  	$(PATH_SRC)ft_putstr.c \
	  	$(PATH_SRC)ft_putendl.c \
	  	$(PATH_SRC)ft_putnbr.c \
	  	$(PATH_SRC)ft_putchar_fd.c \
	  	$(PATH_SRC)ft_putstr_fd.c \
	  	$(PATH_SRC)ft_putendl_fd.c \
	  	$(PATH_SRC)ft_putnbr_fd.c \
	  	$(PATH_SRC)ft_lstnew.c \
	  	$(PATH_SRC)ft_lstdelone.c \
	  	$(PATH_SRC)ft_lstdel.c \
	  	$(PATH_SRC)ft_lstadd.c \
	  	$(PATH_SRC)ft_lstiter.c \
	  	$(PATH_SRC)ft_lstmap.c \
		$(PATH_SRC)get_next_line.c \
		$(PATH_SRC)ft_isspace.c \
		$(PATH_SRC)ft_strjoinfree.c \
		$(PATH_SRC)ft_lltoa_base.c \
		$(PATH_SRC)ft_memjoin.c \
		$(PATH_SRC)ft_strjoin_free.c \
		$(PATH_SRC)ft_strncat_nocpy.c \
		$(PATH_SRC)ft_strunicode.c \
		$(PATH_SRC)ft_ulltoa_base.c \


OBJ = $(patsubst %.c,%.o,$(SRC))

all: $(NAME)

$(NAME): $(OBJ)
#	$(CC) -Wall -Wextra -Werror -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
