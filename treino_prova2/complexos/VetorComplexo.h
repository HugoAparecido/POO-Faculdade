#ifndef VETORCOMPLEXO
#define VETORCOMPLEXO

#include "Complexo.h"

class VetorComplexo
{
private:
    Complexo *elementos;
    int tamanhoTotal;
    int tamanhoAtual;

public:
    VetorComplexo(int tam);
    VetorComplexo(const VetorComplexo &outro);
    int GetTamanhoTotal() const;
    int GetTamanhoAtual() const;
    void SetComplexo(const Complexo complexo, int local);
    Complexo GetComplexo(int local) const;

    VetorComplexo &operator=(const VetorComplexo &outro);
    Complexo &operator[](int indice);

    ~VetorComplexo();
};

#endif
