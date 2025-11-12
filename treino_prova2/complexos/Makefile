# Makefile
CC = g++
# Adiciona a flag -static para a imagem 'scratch' funcionar
CFLAGS = -Wall -g -static

# Lista TODOS os arquivos .cpp do projeto
SRCS = Complexo.cpp main.cpp
# O nome do programa executável final
EXE = figuras

# Alvo padrão: 'all'
all: $(EXE)

# Regra de compilação: Compila e linka todos os SRCS
$(EXE): $(SRCS)
	$(CC) $(CFLAGS) -o $(EXE) $(SRCS)

.PHONY: clean
clean:
	rm -f $(EXE)