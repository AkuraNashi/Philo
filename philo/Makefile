# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcamilo- <lcamilo-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 16:47:09 by lcamilo-          #+#    #+#              #
#    Updated: 2022/10/19 20:35:17 by lcamilo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# ------------  COLORS  ------------------------------------------------------ #
COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_ORANGE=\033[0;34m
COLOUR_END=\033[0m
COLOUR_YELLOW=\033[0;33m
COLOUR_CYAN=\033[0;36m

# ------------  PROJECT  ----------------------------------------------------- #
NAME		= philo

# ------------  DIRECTORIES  ------------------------------------------------- #
SRC_PATH		= src/
HEADERS			= includes

INC			= $(addprefix $HEADERS_LIB)

# ------------  FLAGS  ------------------------------------------------------- #
CFLAGS 		= -Wall -Wextra -Werror -fsanitize=address -I $(HEADERS)
CC			= @cc
RM			= rm -rf

# ------------  SOURCE FILES  ------------------------------------------------ #
SRC 		= 	main.c utils.c init.c

# ------------  FILEPATHS  --------------------------------------------------- #
OBJS				= ${SRC:.c=.o}
OBJS_DIR			= objs
DIRS				= objs
_OBJS				= $(addprefix $(OBJS_DIR)/, $(OBJS))

all: $(NAME)

$(NAME): $(_OBJS)
			@echo "$(COLOUR_CYAN)Compile..."
			$(CC) $(_OBJS) $(CFLAGS) -o $(NAME)
			@echo "$(COLOUR_RED)Philosophers are ready. $(COLOUR_END)"

$(OBJS_DIR)/%.o: $(SRC_PATH)/%.c
		@mkdir -p $(DIRS)
		${CC} $(CFLAGS) -c $< -o $@ -g3

clean:
			$(RM) ${OBJS}
			rm -rf $(OBJS_DIR)

fclean:		clean
			$(RM) $(NAME) *.a

re:			fclean all

.PHONY: re ignore fclean clean all $(LIBFT) $(NAME) $(PRINTF)