#include <iostream>
using namespace std;

class MeuInt
{
private:
    int numero;

public:
    // Construtor
    MeuInt(int numero = 0);

    // Set e Get
    void setNumero(int numero);
    int getNumero() const;

    //================================Operadores membros da classe=================
    // Un�rios
    MeuInt &operator++();         // pr�
    const MeuInt operator++(int); // p�s
    MeuInt &operator--();         // pr�
    const MeuInt operator--(int); // p�s

    // MeuInt com MeuInt
    const MeuInt operator+(const MeuInt &o2) const;
    const MeuInt operator-(const MeuInt &o2) const;
    const MeuInt operator*(const MeuInt &o2) const;
    const MeuInt operator/(const MeuInt &o2) const;
    bool operator>(const MeuInt &o2) const;
    bool operator<(const MeuInt &o2) const;
    bool operator==(const MeuInt &o2) const;

    // MeuInt com Int
    const MeuInt operator+(int o2) const;
    const MeuInt operator-(int o2) const;
    const MeuInt operator*(int o2) const;
    const MeuInt operator/(int o2) const;
    bool operator>(int o2) const;
    bool operator<(int o2) const;
    bool operator==(int o2) const;

    //================================Operadores NAO membros da classe
    // Int com MeuInt
    friend const MeuInt operator+(int o1, const MeuInt &o2);
    friend const MeuInt operator-(int o1, const MeuInt &o2);
    friend const MeuInt operator*(int o1, const MeuInt &o2);
    friend const MeuInt operator/(int o1, const MeuInt &o2);
    friend bool operator>(int o1, const MeuInt &o2);
    friend bool operator<(int o1, const MeuInt &o2);
    friend bool operator==(int o1, const MeuInt &o2);

    // Fluxo de entrada e sa?da
    friend ostream &operator<<(ostream &saida, const MeuInt &num);
    friend istream &operator>>(istream &entrada, MeuInt &num);
};

MeuInt::MeuInt(int numero)
{
    setNumero(numero);
}

void MeuInt::setNumero(int numero)
{
    this->numero = numero;
}

int MeuInt::getNumero() const
{
    return this->numero;
}

//================================Operadores membros da classe===============
// Un�rios
MeuInt &MeuInt::operator++()
{ // pr�
    ++numero;
    return (*this);
}

const MeuInt MeuInt::operator++(int)
{ // p�s
    MeuInt copia(*this);
    ++numero;
    return copia;
}

MeuInt &MeuInt::operator--()
{ // pr�
    --numero;
    return (*this);
}

const MeuInt MeuInt::operator--(int)
{ // p�s
    MeuInt copia(*this);
    --numero;
    return copia;
}

// MeuInt com MeuInt

const MeuInt MeuInt::operator+(const MeuInt &o2) const
{
    return MeuInt(numero + o2.numero);
}

const MeuInt MeuInt::operator-(const MeuInt &o2) const
{
    return MeuInt(numero - o2.numero);
}

const MeuInt MeuInt::operator*(const MeuInt &o2) const
{
    return MeuInt(numero * o2.numero);
}

const MeuInt MeuInt::operator/(const MeuInt &o2) const
{
    return MeuInt(numero / o2.numero);
}

bool MeuInt::operator>(const MeuInt &o2) const
{
    if (numero > o2.numero)
        return true;
    else
        return false;
}
bool MeuInt::operator<(const MeuInt &o2) const
{
    if (numero < o2.numero)
        return true;
    else
        return false;
}

bool MeuInt::operator==(const MeuInt &o2) const
{
    if (numero == o2.numero)
        return true;
    else
        return false;
}

// MeuiInt com Int
const MeuInt MeuInt::operator+(int o2) const
{
    return MeuInt(this->numero + o2);
}

const MeuInt MeuInt::operator-(int o2) const
{
    return MeuInt(this->numero - o2);
}

const MeuInt MeuInt::operator*(int o2) const
{
    return MeuInt(this->numero * o2);
}

const MeuInt MeuInt::operator/(int o2) const
{
    return MeuInt(this->numero / o2);
}

bool MeuInt::operator>(int o2) const
{
    if (numero > o2)
        return true;
    else
        return false;
}
bool MeuInt::operator<(int o2) const
{
    if (numero < o2)
        return true;
    else
        return false;
}

bool MeuInt::operator==(int o2) const
{
    if (numero == o2)
        return true;
    else
        return false;
}

//================================Operadores N?O membros da classe (friend)====

// Int com MeuInt
const MeuInt operator+(int o1, const MeuInt &o2)
{
    return MeuInt(o1 + o2.numero);
}

const MeuInt operator-(int o1, const MeuInt &o2)
{
    return MeuInt(o1 - o2.numero);
}

const MeuInt operator*(int o1, const MeuInt &o2)
{
    return MeuInt(o1 * o2.numero);
}
const MeuInt operator/(int o1, const MeuInt &o2)
{
    return MeuInt(o1 / o2.numero);
}

bool operator>(int o1, const MeuInt &o2)
{
    if (o1 > o2.numero)
        return true;
    else
        return false;
}

bool operator<(int o1, const MeuInt &o2)
{
    if (o1 < o2.numero)
        return true;
    else
        return false;
}

bool operator==(int o1, const MeuInt &o2)
{
    if (o1 == o2.numero)
        return true;
    else
        return false;
}

// Operador de sa?da
ostream &operator<<(ostream &saida, const MeuInt &num)
{
    saida << num.numero;
    return saida;
}

// Operador de entrada
istream &operator>>(istream &entrada, MeuInt &num)
{
    entrada >> num.numero;
    return entrada;
}
