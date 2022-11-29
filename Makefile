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
FLAGS = 	-Wall -Wextra -Werror -c
DEBFLAGS =	-Wall -Wextra  -Werror -g -c
NAME =		yaxml.a
SRC_PATH =	./
INCLUDE =	./
SRCS =		yaxml.c yaxml_free.c
OBJECTS =	$(SRCS:.c=.o)
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
