NAME = fillit
SRC = ./srcs
INC = ./includes
OBJ = .
LIST_SRC = $(SRC)/main.c $(SRC)/ft_check_file.c $(SRC)/ft_get_file.c $(SRC)/ft_fill_lst.c $(SRC)/ft_resolve.c

LIST_OBJ = $(LIST_SRC:$(SRC)/%.c=$(OBJ)/%.o)
CFLAG = -Wall -Wextra -Werror
LIFT = libft.a
LIFTPATH = ./libft/
INC_LIFTPATH  = $(LIFTPATH)

all : $(NAME)

$(LIBFT) : $(LIFT)
		make -C  $(LIBFTPATH)

$(NAME) : $(LIBFT) $(LIST_SRC) 
		gcc $(CFLAG) -I $(INC) -I $(INC_LIFTPATH) $(LIST_SRC) -L$(LIFTPATH) -lft -o $(NAME)

clean :
		/bin/rm -f  $(LIST_OBJ)

fclean : clean
		/bin/rm -f $(NAME)

re : fclean all
