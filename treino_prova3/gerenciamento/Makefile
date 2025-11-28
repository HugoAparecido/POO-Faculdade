# Makefile
CC = g++
# Adiciona a flag -static para a imagem 'scratch' funcionar
CFLAGS = -Wall -g -static

# Lista TODOS os arquivos .cpp do projeto
SRCS = main.cpp PluginCalculo.cpp  PluginLog.cpp
# O nome do programa executável final
EXE = gerenciamento

# Alvo padrão: 'all'
all: $(EXE)

# Regra de compilação: Compila e linka todos os SRCS
$(EXE): $(SRCS)
	$(CC) $(CFLAGS) -o $(EXE) $(SRCS)

.PHONY: clean
clean:
	rm -f $(EXE)