NAME= libft.a

FLAGS=-Wall -Wextra -Werror

DISPLAY=display/ft_putnbr.c \
	display/ft_putnbr_fd.c \
	display/ft_putchar.c \
	display/ft_putchar_fd.c \
	display/ft_putstr.c \
	display/ft_putstr_fd.c \
	display/ft_putendl_fd.c
CHECKER=checker/ft_isalnum.c \
	checker/ft_isalpha.c \
	checker/ft_isascii.c \
	checker/ft_isdigit.c \
	checker/ft_isprint.c
CONVERT=convert/ft_tolower.c \
	convert/ft_toupper.c \
	convert/ft_atoi.c \
	convert/ft_itoa.c
MEMORY=memory/ft_bzero.c \
	memory/ft_calloc.c \
	memory/ft_memcpy.c \
	memory/ft_memchr.c \
	memory/ft_memcmp.c \
	memory/ft_memmove.c \
	memory/ft_memset.c
STRING=string/ft_strchr.c \
	string/ft_strlcat.c \
	string/ft_strlcpy.c \
	string/ft_strlen.c \
	string/ft_strdup.c \
	string/ft_strnstr.c \
	string/ft_strrchr.c \
	string/ft_strncmp.c \
	string/ft_strjoin.c \
	string/ft_substr.c \
	string/ft_split.c \
	string/ft_strtrim.c \
	string/ft_strmapi.c


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