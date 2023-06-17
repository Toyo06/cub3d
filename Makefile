NAME = cub3d

SRCS = GNL/get_next_line.c GNL/get_next_line_utils.c Utils/ft_strdup.c Utils/ft_strcmp.c \
	   Utils/ft_atoi.c Utils/ft_split.c Utils/ft_isdigit.c Utils/ft_strjoin.c main.c Utils/ft_putstr_fd.c \
	   Parsing/setarg.c Error/errormess.c utils/ft_colorcheck.c \
	   Parsing/setargbis.c Parsing/setargbistwo.c Parsing/mapprep.c Error/errormessmap.c Parsing/namecheck.c \

OBJECTS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g #-fsanitize=address

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

clean :
	rm -rf $(OBJECTS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
	rm -rf $(OBJECTS)

.PHONY: all clean fclean re
