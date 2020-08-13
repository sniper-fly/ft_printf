
# find . -type f -name *.c | grep -v git | grep -v lst |
#  awk '{print $0 " \\";}' >> Makefile
SRCS	=	./libft/ft_strchr.c \
			./libft/ft_split.c \
			./libft/ft_strtrim.c \
			./libft/ft_bzero.c \
			./libft/ft_strnstr.c \
			./libft/ft_strmapi.c \
			./libft/ft_isprint.c \
			./libft/ft_atoi.c \
			./libft/ft_strdup.c \
			./libft/ft_tolower.c \
			./libft/ft_toupper.c \
			./libft/ft_substr.c \
			./libft/ft_memchr.c \
			./libft/ft_putnbr_fd.c \
			./libft/ft_strlcpy.c \
			./libft/ft_itoa.c \
			./libft/ft_memset.c \
			./libft/ft_calloc.c \
			./libft/ft_strlen.c \
			./libft/ft_putchar_fd.c \
			./libft/ft_isascii.c \
			./libft/ft_memccpy.c \
			./libft/ft_strlcat.c \
			./libft/ft_putendl_fd.c \
			./libft/ft_memcmp.c \
			./libft/ft_strrchr.c \
			./libft/ft_putstr_fd.c \
			./libft/ft_isalpha.c \
			./libft/ft_strncmp.c \
			./libft/ft_isalnum.c \
			./libft/ft_memcpy.c \
			./libft/ft_memmove.c \
			./libft/ft_strjoin.c \
			./set_precision/set_precision_flag.c \
			./set_precision/set_precision.c \
			./set_precision/set_precision_asterisk.c \
			./ft_printf.c \
			./set_zero_minus_flag/set_zero_minus_flag.c \
			./parse_type/output_s.c \
			./parse_type/output_di.c \
			./parse_type/output_u.c \
			./parse_type/output_percent.c \
			./parse_type/output_xX.c \
			./parse_type/parse_type.c \
			./parse_type/put_it_xx_times.c \
			./parse_type/output_p.c \
			./parse_type/output_c.c \
			./set_width/set_width_asterisk.c \
			./set_width/set_width.c \

OBJS	=	$(SRCS:%.c=%.o)
NAME	=	libftprintf.a
CC		=	gcc
# CFLAGS	=	
RM		=	rm -f

all:		$(NAME)

$(NAME):	$(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	rm $(OBJS)

fclean:		clean
	rm $(NAME)

re:			fclean all

.PHONY:		all clean fclean 