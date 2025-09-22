CC = g++
CFLAGS = -Wall -g
CPP_SRCS = main.cpp aluno.cpp
CPP_EXE = aluno # New executable name

# Alvo padrão
all: run_cpp

# Phony targets
.PHONY: all run_cpp clean

# New target to compile and run the C++ file
$(CPP_EXE): $(CPP_SRCS)
	$(CC) $(CFLAGS) -o $(CPP_EXE) $(CPP_SRCS)

# Novo alvo para rodar o executável
run_cpp: $(CPP_EXE)
	./$(CPP_EXE)

# Limpeza
clean:
	rm -f $(CPP_EXE)