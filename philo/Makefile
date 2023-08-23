# philosophers
NAME				=	philo

PHILO_SRC			=	utils.c \
						parsing.c \
						actions.c \
						philo.c
OBJS				=	$(PHILO_SRC:.c=.o)

# Compiler
CC					=	gcc
RM					=	rm -f
CFLAGS				=	-Wall -Werror -Wextra -pthread -g3 -fsanitize=thread

# Colours
RED					=	\033[0;31m
GREEN				=	\033[0;32m
YELLOW				=	\033[0;33m
BLUE				=	\033[0;34m
PURPLE				=	\033[0;35m
CYAN				=	\033[0;36m
WHITE				=	\033[0;37m
RESET				=	\033[0m

# Rules
all:		$(NAME)
			@printf "$(BLUE)==> $(CYAN)Philosophers compiled ✅\n\n$(RESET)"

$(NAME):	$(OBJS)
			@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
			@$(RM) $(OBJS)
			@printf "\n$(BLUE)==> $(RED)Removed Philosophers 🗑️\n$(RESET)"

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all
			@printf "$(BLUE)==> $(CYAN)Philosophers recompiled 🔄\n$(RESET)"

.PHONY:		all clean fclean re