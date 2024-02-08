CFLAGS = -Wall -Wextra -Werror -MMD -MP
SRC = ft_atoi.c main.c moves.c radix.c small_sort.c stacks.c utils.c
OBJ = $(SRC:.c=.o)
NAME = push_swap
OBJDEPS = $(OBJ:.o=.d)
FT_PRINTF = ft_printf/libftprintf.a
FT_PRINTF_SRC = $(wildcard ft_printf/*.c)
FT_PRINTF_OBJ = $(FT_PRINTF_SRC:.c=.o)
FT_PRINTF_DEPS = $(FT_PRINTF_OBJ:.o=.d)

all: $(NAME)

$(NAME): $(FT_PRINTF) $(OBJ)
	cc -o $(NAME) $(OBJ) $(FT_PRINTF)

%.o: %.c
	cc $(CFLAGS) -o $@ -c $<

$(FT_PRINTF): $(FT_PRINTF_SRC)
	$(MAKE) -C ft_printf/

-include $(OBJDEPS)
-include $(FT_PRINTF_DEPS)

clean:
	rm -f $(OBJ) $(OBJDEPS)
	$(MAKE) -C ft_printf/ clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ft_printf/ fclean

re: fclean all

.PHONY: all clean fclean re