C=gcc
CFLAGS=-lm
SRC_DIR=.

# Lista de arquivos fonte
SRCS=$(wildcard $(SRC_DIR)/*.c)
# Lista de arquivos de cabeçalho
HDRS=$(wildcard $(SRC_DIR)/*.h)
# Lista de objetos correspondentes aos arquivos fonte
OBJS=$(patsubst $(SRC_DIR)/%.c, %.o, $(SRCS))

# Regra para construir o executável principal
main: $(OBJS)
	$(C) $(CFLAGS) -O3 -o $@ $^

# Regra para construir os objetos
%.o: %.c $(HDRS)
	$(C) $(CFLAGS) -c -o $@ $<

clean:
	rm -f main *.png *.o

.PHONY: clean

all: clean main

.PHONY: all
