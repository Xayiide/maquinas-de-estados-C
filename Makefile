CC     = gcc
CFLAGS = -Wall -O0 -g3

TRGT = maquinas
SRCS = maquinas.c
OBJS = $(SRCS:.c=.o)

.PHONY: all debug clean re

all: $(TRGT)
	@rm -f $(OBJS)

debug: all

debug: DEBUG=-DDEBUG

$(TRGT): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TRGT)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	@rm -f $(TRGT) $(OBJS)
	@echo "clean"

re: clean all
