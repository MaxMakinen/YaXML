# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmakinen <mmakinen@hive.fi>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/19 10:28:04 by mmakinen          #+#    #+#              #
#    Updated: 2022/06/20 16:59:47 by mmakinen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =		clang
FLAGS := 	-Wall -Wextra -Werror -c
DEBFLAGS :=	-Wall -Wextra -Werror -g -c
NAME :=		libft.a
SRC_PATH =	./
INCLUDE =	./
SRCS :=		ft_calloc.c ft_strsub.c ft_lstadd.c ft_lstiter.c ft_lstmap.c	\
ft_strchr.c ft_lstnew.c ft_lstdel.c ft_lstdelone.c ft_strlcpy.c	ft_isprint.c\
ft_memdel.c ft_putstr_fd.c ft_strjoin.c ft_strnstr.c ft_isspace.c			\
ft_memmove.c ft_strcat.c ft_strlcat.c ft_strrchr.c ft_atoi.c ft_isupper.c	\
ft_memset.c ft_strclr.c ft_strlen.c ft_strsplit.c ft_bzero.c ft_isxdigit.c	\
ft_putchar.c ft_strcmp.c ft_strmap.c ft_strstr.c ft_isalnum.c ft_itoa.c		\
ft_putchar_fd.c ft_strcpy.c ft_strmapi.c ft_isalpha.c ft_memalloc.c			\
ft_putendl.c ft_strdel.c ft_strncat.c ft_strtrim.c ft_isascii.c ft_memccpy.c\
ft_putendl_fd.c ft_strdup.c ft_strncmp.c ft_isblank.c ft_memchr.c	\
ft_putnbr.c ft_strequ.c ft_strncpy.c ft_tolower.c ft_isdigit.c ft_memcmp.c	\
ft_putnbr_fd.c ft_striter.c ft_strnequ.c ft_toupper.c ft_islower.c			\
ft_memcpy.c ft_putstr.c ft_striteri.c ft_strnew.c ft_arrfree.c ft_ispunct.c \
ft_swapchr.c ft_swapint.c ft_swapptr.c get_next_line.c ft_isbdigit.c		\
ft_isodigit.c ft_isdigit_base.c ft_abs.c ft_closefd.c ft_openfd.c ft_error.c\
ft_isnumber.c ft_isprefix.c ft_lerp.c ft_norm.c ft_itoa_base.c ft_pow.c \
ft_realloc.c
OBJECTS :=	$(SRCS:.c=.o)
HEADER =	-I $(INCLUDE)

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rc $@ $^

$(OBJECTS):
	@$(CC) $(FLAGS) $(SRCS) $(HEADER)

debug_objects:
	@$(CC) $(DEBFLAGS) $(SRCS) $(HEADER)

debug_lib: debug_objects
	@ar rc $(NAME) $(OBJECTS)

debug: fclean debug_lib
	@echo "Debug mode"
	@-rm -f $(OBJECTS)

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

tidy: all clean

.PHONY: all clean fclean re
