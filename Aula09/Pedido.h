#include <string>

using namespace std;

class Pedido
{
public:
    Pedido(string nome = "desconhecido", int qtdItens = 0);
    int GetID() const;
    string GetNome() const;
    int GetNmroItens() const;
    bool SetItem(unsigned int pos, string val);
    bool GetItem(unsigned int pos, string &val) const;
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