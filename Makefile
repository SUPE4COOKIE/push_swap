CFLAGS = -Wall -Wextra -Werror -MMD -MP
SRC = ft_atoi.c main.c moves.c radix.c small_sort.c stacks.c utils.c
OBJ = $(SRC:.c=.o)
NAME = push_swap
OBJDEPS = $(OBJ:.o=.d)

all: $(NAME)

$(NAME): $(OBJ)
	cc -o $(NAME) $(OBJ)

%.o: %.c
	cc $(CFLAGS) -o $@ -c $<

-include $(OBJDEPS)

clean:
	rm -f $(OBJ) $(OBJDEPS)
	$(MAKE) -C ft_printf/ clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re