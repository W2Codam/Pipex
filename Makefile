# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lde-la-h <lde-la-h@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/10/26 18:09:51 by lde-la-h      #+#    #+#                  #
#    Updated: 2021/11/29 12:51:17 by lde-la-h      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# //= Variables =// #

NAME 	= pipex
CFLAGS	= -Wextra -Werror -Wall # -Wunreachable-code -O3 -g
GREEN	= \x1b[32m
RESET	= \033[0m
BOLD	= \e[1m
RED		= \x1b[31m

# Define the header location
HEADERS = -I ./include

# //= Files =// #

SRCS	=	src/pipex.c \
			src/ft_assert.c \
			src/utils/unix_utils.c \
			src/utils/ft_split.c \
			src/utils/ft_strlen.c \
			src/utils/ft_strdup.c \
			src/utils/ft_strlcpy.c \
			src/utils/ft_strclen.c \
			src/utils/ft_strnstr.c \
			src/utils/ft_substr.c \
			src/utils/ft_strjoin.c \
			src/utils/ft_memcpy.c \
			
OBJS	= ${SRCS:.c=.o}

# //= Rules =// #

## //= Compile =// #
all: $(NAME)

%.o: %.c
	@printf	"$(GREEN)$(BOLD)\rCompiling: $(notdir $<) 🔨$(RESET)"
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) -O3

$(NAME): $(OBJS) include/pipex.h
	@$(CC) $(OBJS) $(HEADERS) -o $@
	@echo "$(GREEN)Done ✅$(RESET)"

## //= Commands =// #

# Clean
clean:
	@echo "$(RED)Cleaning 🧹$(RESET)"
	@rm -f $(OBJS)

# Full clean
fclean: clean
	@rm -f $(NAME)

# Re-compile
re:	fclean all

## //= Misc =// #

# Phonies as not to confuse make, these are actual commands, not files.
.PHONY: all, clean, fclean, re, mlx, libft