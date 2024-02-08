CFLAGS = -Wall -Wextra -Werror -MMD -MP
SRC = ft_atoi.c main.c moves.c radix.c small_sort.c stacks.c utils.c
OBJ = $(SRC:.c=.o)
NAME = push_swap
OBJDEPS = $(OBJ:.o=.d)
FT_PRINTF = ft_printf/libftprintf.a

all: $(NAME)

$(NAME): $(FT_PRINTF) $(OBJ)
	cc -o $(NAME) $(OBJ) $(FT_PRINTF)

-include $(OBJDEPS)

%.o: %.c
	cc $(CFLAGS) -o $@ -c $<

$(FT_PRINTF):
	$(MAKE) -C ft_printf/

clean:
	rm -f $(OBJ) $(OBJDEPS)
	$(MAKE) -C ft_printf/ clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ft_printf/ fclean

re: fclean all

.PHONY: all clean fclean re