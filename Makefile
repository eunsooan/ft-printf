NAME = libftprintf.a
CC = gcc
CFLAG = -Wall -Wextra -Werror

SRC = ft_printf.c \
	  ft_printf_numbers.c \
	  ft_printf_letters.c \
	  print_base.c

OBJ = $(SRC:.c=.o)

$(NAME) : $(OBJ)
	ar crus $(NAME) $?

%.o : %.c %.h
	$(CC) $(CFLAG) -c -o $@ $<

all : $(NAME)

clean :
	-rm -f $(OBJ)

fclean : clean
	-rm -f $(NAME)

re : fclean $(NAME)

.PHONY : all clean fclean re
