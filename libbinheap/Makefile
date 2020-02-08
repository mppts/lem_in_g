NAME = libbinheap.a

.PHONY : all clean fclean re directories

DIR_SRC = srcs/
DIR_INC = includes/
DIR_OBJ = obj/

SOURCE = bin_free.c\
		 bin_get_root.c\
         bin_inc_key.c\
         bin_insert.c\
         bin_remove_root.c\
         bin_swap.c\
         binary_init.c\

HEADERS = binary_heap.h
FLAGS = -Wall -Wextra -Werror
OBJ = $(SOURCE:%.c=%.o)
OBJS = $(SOURCE:%.c=$(DIR_OBJ)%.o)
SRCS = $(SOURCE:%.c=$(DIR_SRC)%.c)
MKDIR_P = mkdir -p

all: $(NAME)

$(NAME): directories $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

directories:
	@$(MKDIR_P)  -p $(DIR_OBJ)

$(DIR_OBJ)%.o: $(DIR_SRC)%.c
	gcc $(FLAGS) -o $@ -c $< -I$(DIR_INC)

clean:
	rm -f $(DIR_OBJ)*.o
	rm -rf $(DIR_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all