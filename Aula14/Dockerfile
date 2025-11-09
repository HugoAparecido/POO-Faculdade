# === Estágio 1: Compilação (Build) ===
# Usamos uma imagem completa com o compilador GCC (g++)
FROM gcc:latest AS builder

# Define o diretório de trabalho dentro do container
WORKDIR /usr/src/app

# Copia o seu código-fonte para o diretório de trabalho
COPY Makefile .
COPY Fracao.cpp .

# Compila o programa C++
# -o meu_app: define o nome do executável de saída
# -static: "Embala" todas as bibliotecas necessárias no executável.
#          (Isso é crucial para a imagem final mínima funcionar)
RUN make

# === Estágio 2: Execução (Runtime) ===
# Usamos a imagem 'scratch', que é 100% vazia (0 MB).
# Nosso app funciona porque foi compilado como estático.
FROM scratch

# Copia *apenas* o programa compilado do estágio "builder"
COPY --from=builder /usr/src/app/fracao .

# Define o comando que será executado quando o container iniciar
CMD ["./fracao"]