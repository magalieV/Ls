##
## EPITECH PROJECT, 2019
## my_ls
## File description:
## __DESCRIPTION__
##

CC	=	@gcc

MAKEFLAGS	+=	--no-print-directory

RM	=	rm -f

ECHO		=	/bin/echo -e
DEFAULT		=	"\033[00m"
GREEN		=	"\033[1;32m"
YELLOW		=	"\033[0;01;033m"
TEAL		=	"\033[1;01;35m"
RED			=	"\033[1;01;31m"

NAME	=	my_ls

CFLAGS	+= -I./include

SRCS	=	src/display/display.c						\
			src/flag_option/d_option.c					\
			src/flag_option/l_option.c					\
			src/flag_option/l_option_two.c				\
			src/flag_option/time_option.c				\
			src/flag_option/r_option.c					\
			src/lenght/size.c							\
			src/list/list_two.c							\
			src/list/list.c								\
			src/ls/flag.c								\
			src/ls/main.c								\
			src/ls/ls.c									\
			src/secu/secu.c								\
			src/transfo_string/change_str.c				\
			src/transfo_string/my_str_to_word_array.c	\
			src/transfo_string/change_string.c			\
			src/secu/secu_list.c

OBJS	=	$(SRCS:.c=.o)

all		:	title $(NAME) endt
			@echo ""

title		:
			@$(ECHO) $(YELLOW)"\n → Projet : my_ls\n" $(DEFAULT)

endt:
			@$(ECHO) $(RED)"\n → [MY LS CREATE]\n" $(DEFAULT)

$(NAME)		:	$(OBJS)
			@$(CC) $(OBJS) -o $(NAME) $(CFLAGS) &&			\
			$(ECHO) $(GREEN) "[OK]" $(TEAL) $(NAME) $(DEFAULT) ||	\
			$(ECHO) $(RED) "[KO]" $(TEAL) $(NAME) $(DEFAULT)
			@make clean

.c.o		:
			@$(CC) $(CFLAGS) -c $< -o $@ &&				\
			$(ECHO) $(GREEN) "[OK]" $(TEAL) $< $(DEFAULT) ||	\
			$(ECHO) $(RED) "[KO]" $(TEAL) $< $(DEFAULT)

clean:
			@$(RM) $(OBJS)

fclean:			clean
			@$(RM) $(NAME)

re		:	fclean all

.PHONY	: all clean fclean re
