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

# Copia *apenas* o executável compilado ('figuras') do estágio anterior
COPY --from=builder /usr/src/app/figuras .

# Define o comando padrão para rodar o programa
CMD ["./figuras"]