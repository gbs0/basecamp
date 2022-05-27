NAME= libft.a

FLAGS=-Wall -Wextra -Werror

DISPLAY=display/ft_putnbr.c \
	display/ft_putchar.c \
	display/ft_putchar_fd.c \
	display/ft_putstr.c 
CHECKER=checker/ft_islower.c \
	checker/ft_isupper.c \
	checker/ft_isalnum.c \
	checker/ft_isalpha.c \
	checker/ft_isascii.c \
	checker/ft_isdigit.c \
	checker/ft_isprint.c
CONVERT=convert/ft_tolower.c \
	convert/ft_toupper.c \
	convert/ft_atoi.c
MEMORY=memory/ft_bzero.c \
	memory/ft_calloc.c \
	memory/ft_memccpy.c \
	memory/ft_memchr.c \
	memory/ft_memcmp.c \
	memory/ft_memmove.c \
	memory/ft_memset.c
STRING=string/ft_strchr.c \
	string/ft_strlcat.c \
	string/ft_strlcpy.c \
	string/ft_strlen.c \
	string/ft_strncmp.c \
	string/ft_strnstr.c \
	string/ft_strcmp.c 


SRC_PATH=./src/
SRC=$(DISPLAY) $(CHECKER) $(CONVERT) $(MEMORY) $(STRING)
SRCS=$(addprefix $(SRC_PATH), $(SRC))

OBJ= $(SRCS:.c=.o)

INC=-I./include

all: $(NAME)

$(NAME): $(OBJ)
	echo "Compiling lib..."
	ar rc $(NAME) $^
	ranlib $(NAME)

%.o: %.c
	gcc $(FLAGS) $(INC) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re