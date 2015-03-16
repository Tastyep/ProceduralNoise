NAME	= libNoise.a

COMP	= gcc

RM	= rm -f

SRCDIR	= src/

INCDIR	= inc/

OBJDIR	= obj/

LIBDIR	= lib/

COMPDIR = $(addprefix $(LIBDIR), $(NAME))

SRCS	= SimplexNoise.c \
	  TurbulenceNoise.c \
	  FBM_Noise.c \
	  RMF_Noise.c \
	  Perlin.c

OBJS	= $(addprefix $(OBJDIR), $(SRCS:.c=.o))

CFLAGS	= -O2 -march=native -std=c11

LDFLAGS	= -lm -I $(INCDIR)

dummy	:= $(shell test -d $(OBJDIR) || mkdir $(OBJDIR)) \
	   $(shell test -d $(LIBDIR) || mkdir $(LIBDIR))

$(OBJDIR)%.o:	$(SRCDIR)%.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ -c $<

$(COMPDIR): $(OBJS)
	ar rcs $(COMPDIR) $(OBJS)
	cp -f $(INCDIR)/libNoise.h $(LIBDIR)

all: $(COMDIR)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)
	$(RM) -r $(LIBDIR)

re:	fclean all

.PHONY: all clean fclean re
