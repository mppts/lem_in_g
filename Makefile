NAME = lem-in

.PHONY : all clean fclean re directories

DIR_SRC = srcs/
DIR_INC = includes/
DIR_OBJ = obj/

LIB = libft.a
LIB_HEAP = libbinheap.a
DIR_OBJ = obj/
DIR_LIB	= $(LIB:.a=/)
DIR_LIB_HEAP = $(LIB_HEAP:.a=/)
LIB_INCLUDES = $(LIB:.a=/includes/)
LIB_HEAP_INCLUDES = $(LIB_HEAP:.a=/includes/)

SOURCE = \
         dijkstra.c\
         main.c\
         man_err.c\
         parse_hash.c\
         parse_links.c\
         parse_map.c\
         parse_room.c\
         parse_utils.c
#         solver.c

HEADERS = lem_in.h libft.h binary_heap.h
#FLAGS = -Wall -Wextra -Werror
FLAGS = 
OBJ = $(SOURCE:%.c=%.o)
OBJS = $(SOURCE:%.c=$(DIR_OBJ)%.o)
SRCS = $(SOURCE:%.c=$(DIR_SRC)%.c)

all: $(NAME)

$(NAME): $(LIB) $(LIB_HEAP) directories $(OBJS)
	gcc $(FLAGS) -o $(NAME) $(OBJS) -L$(DIR_LIB) -lft -L$(DIR_LIB_HEAP) -lbinheap

directories:
	mkdir -p $(DIR_OBJ)

$(LIB):
	$(MAKE) -C $(DIR_LIB)

$(LIB_HEAP):
	$(MAKE) -C $(DIR_LIB_HEAP)

$(DIR_OBJ)%.o: $(DIR_SRC)%.c
	gcc $(FLAGS) -o $@ -c $< -I$(DIR_INC) -I$(LIB_INCLUDES) -I$(LIB_HEAP_INCLUDES)

clean:
	rm -f $(DIR_OBJ)*.o
	rm -rf $(DIR_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
