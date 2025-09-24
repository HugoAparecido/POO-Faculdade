#include <cstdlib>
#include <iostream>

using namespace std;

class caneta
{
private:
    int cor_atual;
    bool falhando[4];
    bool escrevendo;

public:
    caneta();
    void muda_cor(int);
    void troca_refil(int);
    void escrever();
    void parar_escrever();
};

caneta::caneta()
{
    falhando[0] = false;
    falhando[1] = false;
    falhando[2] = false;
    falhando[3] = false;
    cor_atual = 0;
    escrevendo = false;
}

void caneta::muda_cor(int c)
{

    if (!escrevendo)
    {
        if (c >= 0 && c < 4)
            cor_atual = c;
    }
    else
        cout << " nao é possível mudar a cor enquanto escreve " << endl;
}

void caneta::escrever()
{
    int f;

    if (!escrevendo)
    {
        f = rand() % 100;

        if (f > 80)
            falhando[cor_atual] = true;

        if (cor_atual == 0)
            cout << " cor azul ";

        if (cor_atual == 1)
            cout << " cor verde ";

        if (cor_atual == 2)
            cout << " cor preta ";

        if (cor_atual == 3)
            cout << " cor vermelha ";

        if (falhando[cor_atual])
            cout << " falhando ..." << endl;
        else
        {
            cout << " escrevendo..." << endl;
            escrevendo = true;
        }
    }
}

void caneta::parar_escrever()
{
    escrevendo = false;
}

void caneta::troca_refil(int c)
{
    if (c >= 0 && c < 4)
    {
        if (!escrevendo)
        {
            if (falhando[c])
                falhando[c] = false;
            else
                cout << " esta cor não está falhando... refil nao trocado" << endl;
        }
        else
            cout << " nao é possivel trocar o refil enquanto escreve..." << endl;
    }
}

int menu()
{
    int opcao;

    opcao = 10;

    while (opcao < 1 || opcao > 7)
    {
        cout << " 1. escrever em azul " << endl;
        cout << " 2. escrever em verde " << endl;
        cout << " 3. escrever em preto " << endl;
        cout << " 4. escrever em vermelho " << endl;
        cout << " 5. parar de escrever " << endl;
        cout << " 6. trocar refil " << endl;
        cout << " 7. sair " << endl;
        cin >> opcao;
    }
    return opcao;
}
int main(int argc, char *argv[])
{
    int op, cor;
    caneta x;

    op = menu();

    while (op != 7)
    {
        if (op == 1)
        {
            x.muda_cor(0);
            x.escrever();
        }
        if (op == 2)
        {
            x.muda_cor(1);
            x.escrever();
        }
        if (op == 3)
        {
            x.muda_cor(2);
            x.escrever();
        }
        if (op == 4)
        {
            x.muda_cor(3);
            x.escrever();
        }
        if (op == 5)
        {
            x.parar_escrever();
        }
        if (op == 6)
        {
            cout << " 0. Azul " << endl;
            cout << " 1. Verde " << endl;
            cout << " 2. Preta " << endl;
            cout << " 3. Vermelha " << endl;
            cout << " Qual cor ? ";
            cin >> cor;
            x.troca_refil(cor);
        }

        op = menu();
    }

    system("PAUSE");
    return EXIT_SUCCESS;
}