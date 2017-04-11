CC=gcc
LFLAGS=-Werror -Wall -Wextra -Wpedantic -g -O0
CFLAGS = -I $(HEADIR) $(LFLAGS) -c
LIB = shiftcypher.h simplin.h
OBJ = main.o shiftcypher.o simplin.o
OBJS = $(addprefix $(OBJDIR)/,$(OBJ))
OBJDIR = obj
SRCDIR = src
HEADIR = inc
BINDIR = bin

all: shiftcypher

shiftcypher: $(OBJ)
	$(CC) $(LFLAGS) $(OBJS) -o $(BINDIR)/$@

main.o:$(addprefix $(SRCDIR)/,$(OBJ:.o=.c)) $(addpreifx $(HEADIR)/, $(LIB))
	$(CC) $(CFLAGS) $(SRCDIR)/$(@:.o=.c) -o $(OBJDIR)/$@

shiftcypher.o:$(SRCDIR)/$(@:.o=.c) $(HEADIR)/$(@:.o=.h)
	$(CC) $(CFLAGS) $(SRCDIR)/$(@:.o=.c) -o $(OBJDIR)/$@

simplin.o:$(SRCDIR)/$(@:.o=.c) $(HEADIR)/$(@:.o=.h)
	$(CC) $(CFLAGS) $(SRCDIR)/$(@:.o=.c) -o $(OBJDIR)/$@

clean:
	rm $(OBJS) $(BINDIR)/shiftcypher
