#include <string>

using namespace std;

class Livro
{
public:
    void imprimir() const;
    void setTitulo(string titulo);
    string getTitulo() const;

private:
    string titulo;
};