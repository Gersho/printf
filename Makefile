SRCS = ft_parse_convert.c ft_print_conversion.c  ft_parse_flags.c \
ft_print_i.c ft_parse_prec.c ft_printf.c \
ft_initialise_cdata.c ft_parse_width.c ft_print_prct.c ft_print_c.c \
ft_print_s.c ft_print_u.c \
debug_printf.c

OBJS	= $(SRCS:.c=.o)

NAME = libftprintf.a
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror
AR		= ar -cr

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I

$(NAME):	$(OBJS)
			make -C libft/
			cp libft/libft.a libftprintf.a
			$(AR) $(NAME) $(OBJS)

all: 		$(NAME)

clean:
			$(RM) $(OBJS)
			$(RM) $(OBJSBONUS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

bonus:		$(OBJSBONUS)
			$(AR) $(NAME) $(OBJSBONUS)
			
.PHONY:		bonus re fclean clean all