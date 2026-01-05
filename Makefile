NAME        := push_swap
CC          := cc
CFLAGS      := -Wall -Wextra -Werror
DEPFLAGS    := -MMD -MP

SRCS        := \
	main.c \
	fill_stack.c \
	stack_functions.c \
	utils.c \
	error.c \
	push.c \
	swap.c \
	rotate.c \
	reverse_rotate.c \
	selection_sort.c \
	radix_sort.c \
	adaptive_sort.c \
	init_index.c \
	bench.c \
	ft_printf.c \
	utils_printf.c

OBJS        := $(SRCS:.c=.o)
DEPS        := $(SRCS:.c=.d)

INCLUDES    := -I.

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(DEPFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
