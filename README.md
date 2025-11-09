# POO-Faculdade

Aprendizados de POO na faculdade

## Rodar o programa

```
g++ -std=c++11 -o hello main.cpp
```

```
./hello
```

## 🐳 Compilando e Rodando com Docker

Você pode compilar e rodar este projeto inteiramente dentro de um container Docker. Isso elimina a necessidade de instalar o compilador `g++` ou o `make` na sua máquina local, garantindo um ambiente de build consistente.

**1. Arquivos Necessários**

Para que isso funcione, você precisará dos seus arquivos de código-fonte e de dois arquivos de configuração do Docker/Make.

- `main.cpp` (Seu código principal, que usa `std::cin` e `std::cout`)

- `fracao.cpp` (A implementação dos métodos da classe Fracao)

- `fracao.h` (A definição da classe Fracao)

- `Makefile` (As instruções de compilação)

- `Dockerfile` (As instruções para o Docker)

**Conteúdo do `Makefile`**

Este `Makefile` é crucial, pois ele que informa ao `g++` para compilar ambos os arquivos `.cpp` juntos.

```Makefile
# Makefile
CC = g++
# Adiciona a flag -static para a imagem 'scratch' funcionar
CFLAGS = -Wall -g -static

# Lista TODOS os arquivos .cpp do projeto
SRCS = main.cpp fracao.cpp
# O nome do programa executável final
EXE = meu_programa

# Alvo padrão: 'all'
all: $(EXE)

# Regra de compilação: Compila e linka todos os SRCS
$(EXE): $(SRCS)
	$(CC) $(CFLAGS) -o $(EXE) $(SRCS)

.PHONY: clean
clean:
	rm -f $(EXE)
```

**Conteúdo do `Dockerfile`**

Este `Dockerfile` usa um "multi-stage build". Ele primeiro usa uma imagem grande (`gcc`) para compilar o código, e depois copia apenas o executável final para uma imagem 100% vazia (`scratch`), resultando em uma imagem final minúscula.

```Dockerfile
# Dockerfile

# === Estágio 1: Compilação (Builder) ===
# Usa a imagem do GCC que já vem com 'g++' e 'make'
FROM gcc:latest AS builder

# Cria o diretório de trabalho
WORKDIR /usr/src/app

# Copia todos os arquivos de código e o Makefile
# O '*' pega main.cpp, fracao.cpp, e fracao.h
COPY *.cpp *.h Makefile ./

# Executa o make. O Makefile cuida da compilação
RUN make

# === Estágio 2: Execução (Runtime) ===
# Usa a imagem 'scratch' (vazia) para a imagem final
FROM scratch

# Copia *apenas* o executável compilado ('meu_programa') do estágio anterior
COPY --from=builder /usr/src/app/meu_programa .

# Define o comando padrão para rodar o programa
CMD ["./meu_programa"]
```

**2. Como Usar**

Com os 5 arquivos na mesma pasta, abra seu terminal e siga os passos:

**1. Construa (Build) a Imagem Docker:**

Dê um nome (tag) para sua imagem, por exemplo, `app-fracao`.

```Bash
docker build -t app-fracao .
```

**2. Execute (Run) o Container:**

A forma de executar depende se o seu `main.cpp` precisa ou não de entradas do usuário (`std::cin`).

**A) Para Execução Interativa (Usando `std::cin`)**

Se seu programa pede dados ao usuário (como `std::cin >> ...` ou `std::getline`), use as flags `-it` para conectar seu terminal ao container. A flag `--rm` apaga o container automaticamente após o uso.

```Bash
docker run -it --rm app-fracao
```

O terminal irá parar e esperar que você digite os dados, exatamente como se estivesse rodando localmente.

**B) Para Execução Simples (Apenas std::cout)**

Se seu programa apenas imprime informações sem pedir entradas, você pode rodar sem as flags interativas:

```Bash
docker run --rm app-fracao
```
