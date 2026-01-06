NAME        := push_swap
BONUS_NAME  := checker

CC          := cc
CFLAGS      := -Wall -Wextra -Werror
DEPFLAGS    := -MMD -MP
INCLUDES    := -I.

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
	bucket_sort.c \
	radix_sort.c \
	adaptive_sort.c \
	init_index.c \
	bench.c \
	ft_printf.c \
	utils_printf.c

SRCS_BONUS  := \
	checker.c \
	get_next_line.c \
	get_next_line_utils.c

SRCS_SHARED := \
	fill_stack.c \
	stack_functions.c \
	utils.c \
	error.c \
	push.c \
	swap.c \
	rotate.c \
	reverse_rotate.c \
	init_index.c \
	ft_printf.c \
	utils_printf.c

OBJS        := $(SRCS:.c=.o)
DEPS        := $(SRCS:.c=.d)

BONUS_OBJS  := $(SRCS_BONUS:.c=.o) $(SRCS_SHARED:.c=.o)
BONUS_DEPS  := $(BONUS_OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(DEPFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(DEPS) $(BONUS_OBJS) $(BONUS_DEPS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

-include $(DEPS) $(BONUS_DEPS)

.PHONY: all bonus clean fclean re
