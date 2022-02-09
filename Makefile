NAME = push_swap

NAMEB = checker

SRCS = ft_checker.c ft_cmd.c ft_lst.c ft_lstcmd.c ft_output.c ft_split.c ft_utils.c ft_utils2.c ft_utils3.c push_swap.c

SRCSB = checker.c ft_utils.c ft_utils2.c ft_utils3.c ft_lst.c ft_split.c ft_checker.c ft_cmd.c ft_lstcmd.c ft_check_cmd.c ft_output.c

OBJS = ${SRCS:.c=.o}

OBJSB = ${SRCSB:.c=.o}

GCC = gcc
RM = rm -f

CFLAGS = -Wall -Wextra -Werror

HEAD	= push_swap.h

all:		${NAME}

# .c.o:
# 			${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS} ${HEAD}
			${GCC} ${CFLAGS} ${OBJS} -o ${NAME}

$(NAMEB):	${OBJSB} ${HEAD}
			${GCC} ${CFLAGS} ${OBJSB} -o ${NAMEB}

bonus:		${NAMEB}

clean:		
			rm -f ${OBJS} ${OBJSB}

fclean:		clean
			rm -f ${NAME} ${NAMEB}

re:			fclean all

.PHONY:		all clean fclean re bonus

