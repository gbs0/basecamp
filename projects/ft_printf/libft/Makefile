NAME=libft.a
NAME_B=libft_bonus.a

FLAGS=-Wall -Wextra -Werror

DISPLAY= ft_putnbr_fd.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c
CHECKER=ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c
CONVERT=ft_tolower.c \
	ft_toupper.c \
	ft_atoi.c \
	ft_itoa.c \
	ft_utoa.c
MEMORY=ft_bzero.c \
	ft_calloc.c \
	ft_memcpy.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memmove.c \
	ft_memset.c
STRING=ft_strchr.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strdup.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_strjoin.c \
	ft_substr.c \
	ft_split.c \
	ft_strtrim.c \
	ft_strmapi.c \
	ft_striteri.c
LIST=ft_lstadd_front.c \
	ft_lstadd_back.c \
	ft_lstclear.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstlast.c \
	ft_lstmap.c \
	ft_lstnew.c \
	ft_lstsize.c

SRC_PATH=./
SRC=$(DISPLAY) $(CHECKER) $(CONVERT) $(MEMORY) $(STRING) $(LIST)
SRCS=$(addprefix $(SRC_PATH), $(SRC))

OBJ= $(SRCS:.c=.o)

INC=-I./include

all: $(NAME)

$(NAME): $(OBJ)
	echo "Compiling lib..."
	ar rc $(NAME) $^
	ranlib $(NAME)

$(NAME_B): $(OBJ)
	echo "Compiling lib..."
	ar rc $(NAME_B) $^
	ranlib $(NAME_B)

%.o: %.c
	gcc $(FLAGS) $(INC) -o $@ -c $<

clean:
	rm -f $(OBJ)

bonus: $(NAME_B)

fclean: clean
	rm -f $(NAME) $(NAME_B)
	
re: fclean all

.PHONY: all bonus clean fclean re