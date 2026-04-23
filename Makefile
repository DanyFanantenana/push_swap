NAME = push_swap
CHECK = checker

ALL_SRCS = check_args.c ft_atoi.c ft_isdigit.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_split.c ft_strcmp.c \
		index.c instructions.c radix.c simple.c medium.c get_next_line.c \
		get_next_line_utils.c ft_putchar_fd.c ft_putstr_fd.c ft_bzero.c t_list.c utils.c \
		rotate.c revrotate.c \
		bench.c bench_utils.c bench_p_utils.c bench_r_utils.c bench_s_utils.c

SRCS = $(ALL_SRCS) main.c
CHECK_SRCS = $(ALL_SRCS) checker.c

OBJS = ${SRCS:.c=.o}
CHECK_OBJS = ${CHECK_SRCS:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror 
LDFLAGS = -lm

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

RM = rm -rf

all: ${NAME} ${CHECK}
${NAME}: ${OBJS}
	@${CC} ${CFLAGS} ${OBJS} ${LDFLAGS} -o ${NAME}

${CHECK}: ${CHECK_OBJS}
	@${CC} ${CFLAGS} ${CHECK_OBJS} ${LDFLAGS} -o ${CHECK}

clean:
	@${RM} ${OBJS}
	@${RM} ${CHECK_OBJS}

fclean: clean
	@${RM} ${NAME}
	@${RM} ${CHECK}

re: fclean all

.PHONY: all clean fclean re
