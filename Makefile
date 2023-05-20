CC=clang-12
CFLAGS=-g -Wall -Wextra -Wshadow -pedantic -lm -lglut -lGLU -lGL

SRC=src
OBJ=obj
SRCS=$(wildcard $(SRC)/*.c)
OBJS=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))

BINDIR=bin
BIN=$(BINDIR)/Connect4
ZIPNAME=Connect4

all:$(BIN)

release: CFLAGS=-g -Wall -Wextra -Wshadow -pedantic -fstack-usage -O2 -DNDEBUG
release: clean
release: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJ)/%.o: $(SRC)/%.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r $(BINDIR)/* $(OBJ)/*

submit:
	$(RM) $(ZIPNAME)
	zip $(ZIPNAME) $(BIN)
