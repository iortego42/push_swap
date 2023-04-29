NAME= Push_Swap

CC  = gcc
AR = ar
ARFLAGS = -rc
RM = rm -rf 
OBJDIR = build
SRCDIR = src
INCDIR = include 


LDFLAGS = -L $(LFTPATH) -l$(LFTNAME)
CFLAGS = -Wall -Wextra -Werror -I $(INCDIR) 

LFTPATH = libft
LFTNAME = ft
LFT = $(LFTPATH)/lib$(LFTNAME).a
CFLAGS += -I $(LFTPATH)/include


SRCS =	\
		push_swap.c \
		push_swap_algorithm.c \
		push_swap_data_analisys.c \
		push_swap_data_processing.c \
		push_swap_error.c \
		push_swap_init.c \
		push_swap_Ptools.c \
		push_swap_Ptools2.c \
		push_swap_specific_tools.c

OBJS := $(addprefix $(OBJDIR)/,$(SRCS:%.c=%.o))

all: $(NAME)

$(NAME): $(OBJS) $(LFT) 
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LDFLAGS) 

$(LFT): 
	make -C $(LFTPATH)	

$(OBJDIR): 
	mkdir $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	make fclean -C $(LFTPATH)
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:  re clean fclean all
