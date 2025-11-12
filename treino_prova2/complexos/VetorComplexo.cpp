#include "VetorComplexo.h"

#include <stdexcept>

VetorComplexo::VetorComplexo(int tam)
{
    tamanhoTotal = (tam > 0) ? tam : 0;
    if (tamanhoTotal != 0)
        elementos = new Complexo[tamanhoTotal];
    else
        elementos = nullptr;
    tamanhoAtual = 0;
}

VetorComplexo::VetorComplexo(const VetorComplexo &outro) : tamanhoAtual(outro.tamanhoAtual), tamanhoTotal(outro.tamanhoTotal), elementos(nullptr)
{
    if (tamanhoAtual > 0)
    {
        elementos = new Complexo[tamanhoTotal];
        for (int i = 0; i < tamanhoAtual; i++)
            this->elementos[i] = outro.elementos[i];
    }
}

int VetorComplexo::GetTamanhoTotal() const
{
    return tamanhoTotal;
}

int VetorComplexo::GetTamanhoAtual() const
{
    return tamanhoAtual;
}

void VetorComplexo::SetComplexo(const Complexo complexo, int local)
{
    elementos[local] = complexo;
    tamanhoAtual++;
}

Complexo VetorComplexo::GetComplexo(int local) const
{
    local = (local >= tamanhoTotal) ? 0 : local;
    return this->elementos[local];
}

VetorComplexo &VetorComplexo::operator=(const VetorComplexo &outro)
{
    if (this == &outro)
        return *this;

    delete[] elementos;

    tamanhoTotal = outro.tamanhoAtual;
    tamanhoAtual = outro.tamanhoAtual;
    elementos = nullptr;
    if (tamanhoTotal > 0)
    {
        elementos = new Complexo[tamanhoAtual];
        for (int i = 0; i < tamanhoAtual; i++)
            elementos[i] = outro.elementos[i];
    }

    return *this;
}

Complexo &VetorComplexo::operator[](int indice)
{
    if (indice < 0 || indice >= tamanhoAtual)
    {
        // Lança uma exceção padrão do C++
        throw std::out_of_range("Indice fora dos limites do VetorComplexo");
    }
    return elementos[indice];
}

VetorComplexo::~VetorComplexo()
{
    delete[] elementos;
}
