#include <string>

using namespace std;

class Livro
{
public:
    Livro(string isbn, string titulo = "Sem título", string autor = "Sem autor", int ano = 0);
    // Getters
    string GetTitulo() const;
    string GetAutor() const;
    int GetAnoPublicacao() const;
    string GetIsbn() const;
    static int GetContadorLivros();
    // Setters
    void SetTtulo(string titulo);
    void SetAutor(string autor);
    void SetAnoPublicacao(int anoPublicacao);
    ~Livro();

private:
    string titulo;
    string autor;
    int anoPublicacao;
    const string isbn;
    static unsigned int contadorLivros;
};