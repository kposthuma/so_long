# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: kposthum <kposthum@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/06 16:04:34 by kposthum      #+#    #+#                  #
#    Updated: 2023/03/09 10:49:14 by kposthum      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = gcc -Wall -Werror -Wextra
NAME = gnl.a
SRCS = 	get_next_line.c	get_next_line_utils.c
OBJS =  ${SRCS:.c=.o}

$(NAME): $(OBJS)
	@echo Making $(NAME)
	@ar -cr $(NAME) $(OBJS)

$(OBJS): %.o: %.c
	@echo Compiling object $<
	@$(CC) -c $^

all: $(NAME)

clean:
	@echo Removing object files get_next_line
	@rm -f $(OBJS)

fclean: clean
	@echo Removing $(NAME)
	@rm -f $(NAME)

re:		fclean all

.PHONY: clean fclean all re