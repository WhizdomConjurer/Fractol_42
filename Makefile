# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: puzzlesanalytik <puzzlesanalytik@studen    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/10 17:13:41 by puzzlesanal       #+#    #+#              #
#    Updated: 2025/11/10 17:19:48 by puzzlesanal      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fractol
CC := cc
CFLAGS := -Wall -Werror -Wextra -g -fsanitize=address

LIBMLX := ./Includes/MLX42
HEADERS := -I ./Includes -I $(LIBMLX)/Includes
LIBS := $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

SRC_PATH := src
OBJ_DIR := obj
LIBFT_PATH := ./Includes/libft
LIBFT := $(LIBFT_PATH)/libft.a

SRCS = $(SRC_PATH)/color.c \
       $(SRC_PATH)/engine.c \
	   $(SRC_PATH)/events.c \
	   $(SRC_PATH)/main.c \
	   $(SRC_PATH)/render.c \
	   $(SRC_PATH)/utils.c 

OBJS = $(SRCS:$(SRC_PATH)/%.c=$(OBJ_DIR)/%.o)

all: libmlx $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LIBS) -o $@ $(HEADERS)
	@echo "✅ Executable $@ created successfully!"

$(OBJ_DIR)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -I$(LIBFT_PATH) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build
	@make -C $(LIBMLX)/build -j4

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_PATH) clean
	@echo "🧹 Object files removed"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@echo "🧹 Executable removed"

re: fclean all

.PHONY: all clean fclean re libmlx