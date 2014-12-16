NAME	= libNoise.a

COMP	= gcc

RM	= rm -f

SRCDIR	= src/

INCDIR	= inc/

OBJDIR	= obj/

SRCS	= SimplexNoise.c \
	  TurbulenceNoise.c \
	  FBM_Noise.c \
	  RMF_Noise.c \
	  Perlin.c


OBJS	= $(addprefix $(OBJDIR), $(SRCS:.c=.o))

CFLAGS	= -O2 -march=native -std=c11

LDFLAGS	= -lm -I $(INCDIR)

dummy	:= $(shell test -d $(OBJDIR) || mkdir $(OBJDIR))

$(OBJDIR)%.o:	$(SRCDIR)%.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re