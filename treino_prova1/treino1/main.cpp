#include <iostream>
#include "Livro.h"

using namespace std;

int main()
{
    const Livro l1("978-0-261-10238-6", "O Senhor dos Aneis", "J.R.R. Tolkien", 1954);
    cout << "Título: " << l1.GetTitulo() << ", de " << l1.GetAutor() << endl;

    return 0;
}