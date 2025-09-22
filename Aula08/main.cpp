#include <iostream>
#include "aluno.h"

using namespace std;

int main()
{
    double notas1[] = {8.5, 7.0, 9.0};
    Aluno aluno1("Joao", 3, notas1);

    cout << "Aluno: " << aluno1.GetNome() << ", RA: " << aluno1.GetRA() << endl;
    aluno1.ImprimeTodasNotas();

    double notas2[] = {6.5, 7.5};
    Aluno aluno2("Maria", 2, notas2);

    cout << "Aluno: " << aluno2.GetNome() << ", RA: " << aluno2.GetRA() << endl;
    aluno2.ImprimeTodasNotas();

    return 0;
}