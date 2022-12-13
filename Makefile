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

CC =		gcc
CFLAGS := 	-Wall -Wextra -Werror
NAME :=		yaxml.a
OBJ_DIR =	obj
SRC_DIR =	src
INCLUDE =	-I include/ -I libft/
LIBFT =		./libft/libft.a
OBJS =		yaxml_doc.o yaxml_free.o yaxml_list.o yaxml_node.o
HEADER =	-I $(INCLUDE) -I libft/
OBJECTS =	$(addprefix $(OBJ_DIR)/, $(OBJS))

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) -c $(CFLAGS) -g -o $@ $< $(INCLUDE)

$(NAME): $(OBJECTS) $(LIBFT)
	ar rc $@ $^

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(LIBFT):
	@make -C libft/

clean:
	@rm -rf $(OBJ_DIR)
	@make -C libft/ clean

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT)

re: fclean all

tidy: all clean

.PHONY: all clean fclean re tidy
