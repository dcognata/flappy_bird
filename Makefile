NAME = flappy_bird

CC = clang

LIBS = -lSDL2 -lSDL2_image
FLAGS = -Wall -Wextra# -Werror
INCLUDES = -Iinclude/flappy_bird.h

SRCS = main.c \
		tools.c \
		init.c \
		game.c \
		menu.c \

SRCO = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME):
	@echo "\033[1;30mFLAPPY BIRD : Sources compiling...\033[0m"
	@$(CC) $(FLAGS) $(INCLUDES) -c $(SRCS)
	@$(CC) $(FLAGS) -o $(NAME) $(SRCO) $(LIBS)
	@echo "\033[0;36mFLAPPY BIRD compile with success !\033[0m"

clean:
	@/bin/rm -f $(SRCO)
	@echo "\033[0;36mObjects removed...\033[0m"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\033[0;36mFLAPPY BIRD binary removed...\033[0m"

re: fclean all