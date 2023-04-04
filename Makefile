# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: kposthum <kposthum@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/06 16:04:34 by kposthum      #+#    #+#                  #
#    Updated: 2023/04/04 13:33:39 by kposthum      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC := gcc -Wall -Werror -Wextra
NAME := so_long
SRCS := main.c	so_long.c	so_parse.c	so_maps.c	so_utils.c	so_hooks.c\
	so_moved.c	so_images.c	so_textures.c	so_walks.c	so_more.c
LIBMLX	:= ./libs/MLX42

HEADERS	:= -I ./include -I $(LIBMLX)/include -I ./libs/libft -I ./libs/get_next_line
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -pthread -lm -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
LIBFT := ./libs/libft/libft.a
GNL := ./libs/get_next_line/gnl.a
SRCDIR := ./src
OBJDIR := ./obj
OBJS :=	$(addprefix $(OBJDIR)/,$(SRCS:.c=.o))
SRCS := $(addprefix $(SRCDIR)/,$(SRCS))

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(GNL)
	@echo Making $(NAME)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) $(LIBFT) $(GNL) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@echo Compiling $<
	@$(CC) $(HEADERS) -c $< -o $@

$(OBJDIR):
	@mkdir -p $@

$(LIBFT):
	@$(MAKE) -C ./libs/libft

$(GNL):
	@$(MAKE) -C ./libs/get_next_line

$(LIBMLX):
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

clean:
	@echo Removing object files so_long
	@rm -f $(OBJS)
	@rm -rf $(OBJDIR)
	@echo Removing MLX build 
	@rm -rf $(LIBMLX)/build
	@$(MAKE) clean -C ./libs/libft
	@$(MAKE) clean -C ./libs/get_next_line
	
fclean: clean
	@echo Removing $(NAME)
	@rm -f $(NAME)
	@$(MAKE) fclean -C ./libs/libft
	@$(MAKE) fclean -C ./libs/get_next_line

re:		fclean all

.PHONY: libft gnl libmlx clean fclean all re src obj