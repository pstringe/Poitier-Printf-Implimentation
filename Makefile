NAME = libftprintf.a
TEST = ft_printf
MAIN = main.o
DNAME = debug
SRCS_DIR = ./srcs/
INCLUDES = ./includes/
RM = /bin/rm -f

FILES = ft_printf\
	   algo\
	   parse\
	   init\
	   help\
	   string\
	   digit\
	   pointer\
	   uch\
	   unicode\
	   usi\
	   num_extract\
	   num_convert\
	   num_flags\
	   num_mod\
	   not\
	   wide_string\
	   char

CFILES = $(patsubst %, $(SRCS_DIR)%.c, $(FILES))
OFILES = $(patsubst %, %.o, $(FILES))
CFLAGS = -Wall -Wextra

#libft
LFT = ./libft/
LFT_FILES = ft_putchar\
			ft_is_whitespace\
			ft_strchr\
			ft_strlcat\
			ft_isdigit\
			ft_putstr\
		   	ft_strlen\
		   	ft_strdup\
		   	ft_strjoin \
			ft_atoi\
			ft_bzero\
			ft_memalloc\
			ft_memcpy\
			ft_memdel\
			ft_memset\
			ft_strcpy\
			ft_strncmp\
			ft_strnew

LFT_CFILES = $(patsubst %, $(LFT)%.c, $(LFT_FILES))
LFT_OFILES = $(patsubst %, %.o, $(LFT_FILES))
LFT_LIB = $(addprefix $(LFT), ft.a)
LFT_INC = -I $(LFT)

all: $(LFT_LIB) $(NAME)
test: $(LFT_LIB) $(TEST)
debug: $(DNAME)

$(LFT_LIB):
	@make -C $(LFT)

$(OFILES):
	@gcc $(CFLAGS) -c -I$(INCLUDES) $(LFT_INC) $(LFT_CFILES) $(CFILES)
$(MAIN): srcs/main.c
	@gcc $(CFLAGS) -c -I$(INCLUDES) $(LFT_INC) srcs/main.c
$(DNAME): fclean
	@gcc $(CFLAGS) -g -I $(INCLUDES) $(LFT_INC) $(LFT_CFILES) $(CFILES) srcs/main.c -o debug

$(NAME): $(OFILES)
	@ar rc $(NAME) $(OFILES) $(LFT_OFILES)
	@ranlib $(NAME)

$(TEST): fclean $(MAIN) $(OFILES)
	@gcc -g $(MAIN) $(OFILES) $(LFT_OFILES) -o $(TEST)

clean:
	@make -C $(LFT) clean
	@$(RM) $(OFILES)
	@$(RM) $(LFT_OFILES)
	@$(RM) main.o

fclean: clean
	@make -C $(LFT) fclean
	@$(RM) $(NAME)
	@$(RM) $(TEST)
	@$(RM) $(DNAME)
	@$(RM) -rf $(DNAME).dSYM

re: fclean all

.PHONY: all clean fclean re
