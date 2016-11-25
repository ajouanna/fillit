NAME = fillit
SRC = ./srcs
INC = ./includes
OBJ = .
LIST_SRC = $(SRC)/main.c $(SRC)/ft_check_file.c $(SRC)/ft_get_file.c\
		   $(SRC)/ft_fill_lst.c $(SRC)/ft_resolve.c $(SRC)/ft_maputil.c\
		   $(SRC)/ft_replace.c $(SRC)/ft_check_lst.c

LIST_OBJ = $(LIST_SRC:$(SRC)/%.c=$(OBJ)/%.o)
CFLAG = -Wall -Wextra -Werror
# CFLAG = -Wall -Wextra -Werror -g -O0
LIBFT = libft.a
LIBFTPATH = ./libft/
INC_LIBFTPATH  = $(LIBFTPATH)

all : $(NAME)

$(NAME) : $(LIST_SRC)
		make -C $(LIBFTPATH)
		gcc $(CFLAG) -I $(INC) -I $(INC_LIBFTPATH) $(LIST_SRC) -L$(LIBFTPATH) -lft -o $(NAME)

clean :
		/bin/rm -f  $(LIST_OBJ)

fclean : clean
		/bin/rm -f $(NAME)

re : fclean all
