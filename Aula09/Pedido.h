#include <string>

using namespace std;

class Pedido
{
public:
    Pedido(string nome, int qtdItens);
    int GetID() const;
    string GetNome() const;
    int GetNmroItens() const;
    bool SetItem(int pos, string val);
    bool GetItem(int pos, string &val) const;
    static int GetContPedidos();
    static int GetContItens();
    ~Pedido();

private:
    const unsigned int id;
    string nome;
    int unsigned nmroItens;
    string *ptrItens;
    static unsigned int cont_pedidos;
    static unsigned int cont_itens;
    static unsigned int prox_id;
};