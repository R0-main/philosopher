# Main
NAME				=	philo
CC					=	gcc

CFLAGS				=	-Wall -Werror -Wextra -Idependencies/ft_libc/includes -Iincludes -fPIE
RM					=	rm -rf
MAKE				=	make --no-print-directory -C

# Colors
RESET				=	\033[0m
BLACK				=	\033[0;30m
RED					=	\033[0;31m
GREEN				=	\033[1;32m
YELLOW				=	\033[0;33m
BLUE				=	\033[0;34m
PURPLE				=	\033[1;35m
CYAN				=	\033[1;36m
WHITE				=	\033[0;37m

# Symbols
OK					=	✓
FAIL				=	✗
INFO				=	ⓘ

# Sources and Objects
FT_LIBC 			= ./dependencies/ft_libc/ft_libc.a

SRCS				=	src/main.c\
							src/parsing/parsing.c\
							src/philosophers/create.c\
							src/philosophers/actions.c\
							src/philosophers/free.c\
							src/philosophers/starvation.c\
							src/philosophers/say.c\
							src/philosophers/thread.c\
							src/forks/create.c\
							src/forks/free.c\
							src/forks/link.c\
							src/timer/timer.c\
							src/waiter/thread.c\
							src/waiter/queue.c\
							src/waiter/ask.c\

SRC_COUNT			=	$(words $(SRCS))

OBJS				=	$(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

OBJ_DIR				=	objects

all : header $(NAME)

$(NAME) : $(FT_LIBC) $(OBJ_DIR)
		@$(CC) $(CFLAGS) $(OBJS) $(FT_LIBC) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
		@mkdir -p $(dir $@)
		@$(CC) $(CFLAGS) -c $< -o $@
		@printf "$(GREEN)$(OK)$(RESET)"

$(OBJ_DIR): $(OBJS)
		@if [ ! -d "$(OBJ_DIR)" ]; \
			then mkdir -p "$(OBJ_DIR)"; \
		fi
		@printf "]"
		@printf "\n"

$(FT_LIBC) :
	@if [ ! -e "$(shell dirname $@)" ]; then \
		git clone git@github.com:R0-main/ft_libc.git $(shell dirname $@); \
	fi;
	@$(MAKE) $(shell dirname $@) SAFE=1

header:
		@echo '		__________.__    .__.__                            .__'
		@echo '		\______   \  |__ |__|  |   ____  __________ ______ |  |__   ___________'
		@echo '		|     ___/  |  \|  |  |  /  _ \/  ___/  _ \\____ \|  |  \_/ __ \_  __ \'
		@echo '		|    |   |   Y  \  |  |_(  <_> )___ (  <_> )  |_> >   Y  \  ___/|  | \/'
		@echo '		|____|   |___|  /__|____/\____/____  >____/|   __/|___|  /\___  >__|'
		@echo '					\/                   \/      |__|        \/     \/'
		@printf  "\n"; \
		printf "Compiling Project : ["

clean :
		@$(RM) $(OBJ_DIR)
		@$(MAKE) $(shell dirname $(FT_LIBC)) fclean

fclean : clean
		@$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re header
