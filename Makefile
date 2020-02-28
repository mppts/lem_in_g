NAME = lem-in

.PHONY : all clean fclean re directories

DIR_SRC = srcs/
DIR_INC = includes/
DIR_OBJ = obj/

LIB = libft.a
DIR_LIB	= $(LIB:.a=/)
LIB_INCLUDES = $(LIB:.a=/includes/)

SOURCE = \
         main.c\
         man_err.c\
         parse_hash.c\
         parse_links.c\
         parse_map.c\
         parse_room.c\
         parse_room2.c\
         parse_utils.c\
         solver.c\
         solver_initialization.c\
         solver_algorithm.c\
         solver_find_best_current_way.c\
         solver_bellman_ford_start_end.c\
         solver_bellman_ford_end_start.c\
         solver_auxiliary_works_algo.c\
         solver_auxiliary_works_algo_2.c\
         solver_bf_es_find_way.c\
         solver_bf_find_way.c\
         solver_find_way.c\
         solver_sufficienty_c.c\
         solver_sufficienty_c_common_rooms_calc.c\
         solver_algo_separation.c\
         writer_main.c\
         writer_main2.c


HEADERS =	lem_in.h \
			libft.h \

#FLAGS = -Wall -Wextra -Werror
FLAGS = 
OBJ = $(SOURCE:%.c=%.o)
OBJS = $(SOURCE:%.c=$(DIR_OBJ)%.o)
SRCS = $(SOURCE:%.c=$(DIR_SRC)%.c)

all: $(NAME)

$(NAME): $(LIB) directories $(OBJS)
	gcc $(FLAGS) -o $(NAME) $(OBJS) -L$(DIR_LIB) -lft

directories:
	mkdir -p $(DIR_OBJ)

$(LIB):
	$(MAKE) -C $(DIR_LIB)

$(DIR_OBJ)%.o: $(DIR_SRC)%.c
	gcc $(FLAGS) -MD -o $@ -c $< -I$(DIR_INC) -I$(LIB_INCLUDES) include $(wildcard *.d)

clean:
	rm -f $(DIR_OBJ)*.o
	rm -rf $(DIR_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
