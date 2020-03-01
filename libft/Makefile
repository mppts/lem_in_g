SRC_DIR			=	srcs
INCLUDES_DIR	=	includes
OBJ_DIR			=	obj

CHK_DIR			=	0_checkers
MEM_DIR			=	0_mem
STR_DIR			=	1_string
TONUM_DIR		=	1_tonum
GNL_DIR			=	2_get_next_line
LST_DIR			=	2_lst
PUT_DIR			=	2_put
STRCH_DIR		=	2_strchange
DSTR_DIR		=	3_dstr

CHK		=	ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c

GNL		=	ft_get_next_line.c\
			ft_get_next_line2.c

LST		=	ft_del.c \
            ft_lstadd.c \
            ft_lstdel.c \
            ft_lstdelone.c \
            ft_lstiter.c \
            ft_lstmap.c \
            ft_lstnew.c

MEM		=	ft_bzero.c \
            ft_memalloc.c \
            ft_memccpy.c \
            ft_memchr.c \
            ft_memcmp.c \
            ft_memcpy.c \
            ft_memdel.c \
            ft_memmove.c \
            ft_memset.c

PUT		=	ft_putchar.c \
            ft_putchar_fd.c \
            ft_putendl.c \
            ft_putendl_fd.c \
            ft_putnbr.c \
            ft_putnbr_fd.c \
            ft_putstr.c \
            ft_putstr_fd.c

STRCH	=	ft_itoa.c \
            ft_tolower.c \
            ft_toupper.c

STR		=	ft_strcat.c \
            ft_strchr.c \
            ft_strchrcount.c \
            ft_strclr.c \
            ft_strcmp.c \
            ft_strcpy.c \
            ft_strdel.c \
            ft_strdup.c \
            ft_strequ.c \
            ft_striter.c \
            ft_striteri.c \
            ft_strjoin.c \
            ft_strlcat.c \
            ft_strlcpy.c \
            ft_strlen.c \
            ft_strmap.c \
            ft_strmapi.c \
            ft_strncat.c \
            ft_strncmp.c \
            ft_strncpy.c \
            ft_strnequ.c \
            ft_strnew.c \
            ft_strnlen.c \
            ft_strnstr.c \
            ft_strrchr.c \
            ft_strsplit.c \
            ft_strstr.c \
            ft_strsub.c \
            ft_strtolower.c \
            ft_strtoupper.c \
            ft_strtrim.c

TONUM	=	ft_atoli.c \
            ft_atoi.c

DSTR	=	dstr.c\
			dstr2.c

FILES			+=	$(CHK) \
					$(GNL) \
					$(LST) \
					$(MEM) \
					$(PUT) \
					$(STRCH) \
					$(STR) \
					$(TONUM) \
					$(DSTR)


OBJ				=	$(FILES:%.c=%.o)
OBJS			=	$(FILES:%.c=./$(OBJ_DIR)/%.o)
DEPS = $(OBJS:.o=.d)

VPATH = ./$(SRC_DIR)/$(CHK_DIR)/

.PHONY: all clean fclean re dirs modules

FLAGS = -Wall -Werror -Wextra

NAME	= libft.a

all: $(NAME)

$(NAME): dirs modules
				@ar rc $(NAME) $(OBJS)
				@ranlib $(NAME)

modules:
		@$(MAKE) -s -C $(CHK_DIR)
		@echo -e "\033[0;32mCheckers module done\033[0m"
		@$(MAKE) -s -C$(MEM_DIR)
		@echo -e "\033[0;32mMemory module done\033[0m"
		@$(MAKE) -s -C $(STR_DIR)
		@echo -e "\033[0;32mString module done\033[0m"
		@$(MAKE) -s -C $(STRCH_DIR)
		@echo -e "\033[0;32mString changers module done\033[0m"
		@$(MAKE) -s -C $(TONUM_DIR)
		@echo -e "\033[0;32mNumber cast module done\033[0m"
		@$(MAKE) -s -C $(GNL_DIR)
		@echo -e "\033[0;32mGNL module done\033[0m"
		@$(MAKE) -s -C $(LST_DIR)
		@echo -e "\033[0;32mList module done\033[0m"
		@$(MAKE) -s -C $(PUT_DIR)
		@echo -e "\033[0;32mWriters module done\033[0m"
		@$(MAKE) -s -C $(DSTR_DIR)
		@echo -e "\033[0;32mDynamic string module done\033[0m"

clean:
				@rm -f $(OBJS)
				@rm -f $(OBJ)
				@rm -rf $(OBJ_DIR)

fclean: clean
				@rm -f $(NAME)

re: fclean all