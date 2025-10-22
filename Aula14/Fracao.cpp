#include <iostream>

using namespace std;

class Fracao
{
public:
    Fracao();
    Fracao(int n, int d);
    Fracao(int n);

    void SetNum(int n);
    void SetDen(int d);
    int GetNum() const;
    int GetDen() const;

    void Mostrar() const;

    Fracao operator+(const Fracao &f2) const;
    Fracao operator-(const Fracao &f2) const;
    Fracao operator+(int num) const;
    Fracao operator-(int num) const;
    friend Fracao operator+(int num, const Fracao &o1);
    friend Fracao operator-(int num, const Fracao &o1);

    Fracao operator*(const Fracao &f2) const;
    Fracao operator*(int num) const;
    friend Fracao operator*(int num, const Fracao &o1);

    Fracao operator++(int);
    Fracao &operator++();

    Fracao operator--(int);
    Fracao &operator--();

    bool operator>(const Fracao &f2) const;
    bool operator>(int num) const;
    friend bool operator>(int num, const Fracao &o1);

    bool operator>=(const Fracao &f2) const;

    friend bool operator<(const Fracao &fe, const Fracao &fd);

    friend ostream &operator<<(ostream &output, const Fracao &fracao);
    friend istream &operator>>(istream &input, Fracao &fracao);

private:
    int num;
    int den;
    int Mmc(int a, int b) const;
};

Fracao::Fracao()
{
    SetNum(0);
    SetDen(1);
}

Fracao::Fracao(int n, int d)
{
    SetNum(n);
    SetDen(d);
}

Fracao::Fracao(int n)
{
    SetNum(n);
    SetDen(1);
}

void Fracao::SetNum(int n)
{
    num = n;
}

void Fracao::SetDen(int d)
{
    den = (d != 0) ? d : 1;
}

int Fracao::GetNum() const
{
    return num;
}

int Fracao::GetDen() const
{
    return den;
}

void Fracao::Mostrar() const
{
    cout << GetNum() << "/" << GetDen() << endl;
}

int Fracao::Mmc(int a, int b) const
{
    int temp, a_ = a, b_ = b;
    while (b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }
    return (a_ / a) * b_;
}

Fracao Fracao::operator+(const Fracao &f2) const
{
    int novo_den = Mmc(this->den, f2.den);
    int novo_num = (this->num * (novo_den / this->den)) + (f2.num * (novo_den / f2.den));
    return Fracao(novo_num, novo_den);
}

Fracao Fracao::operator-(const Fracao &f2) const
{
    int novo_den = Mmc(this->den, f2.den);
    int novo_num = (this->num * (novo_den / this->den)) - (f2.num * (novo_den / f2.den));
    return Fracao(novo_num, novo_den);
}

Fracao Fracao::operator*(const Fracao &f2) const
{
    return Fracao(this->GetNum() * f2.GetNum(), this->GetDen() * f2.GetDen());
}

Fracao Fracao::operator+(int numero) const
{
    return *this + Fracao(numero);
}

Fracao Fracao::operator-(int numero) const
{
    return *this - Fracao(numero);
}

Fracao Fracao::operator*(int num) const
{
    return Fracao(GetNum() * num, GetDen());
}

Fracao &Fracao::operator++()
{
    num += den;
    return *this;
}

Fracao Fracao::operator++(int)
{
    Fracao temp(*this);
    num += den;
    return temp;
}

Fracao Fracao::operator--(int)
{
    Fracao temp(*this);
    num -= den;
    return temp;
}

Fracao &Fracao::operator--()
{
    num -= den;
    return *this;
}

Fracao operator+(int num, const Fracao &o1)
{
    return o1 + num;
}

Fracao operator-(int num, const Fracao &o1)
{
    return Fracao(num) - o1;
}

bool Fracao::operator>(const Fracao &f2) const
{
    return (this->GetNum() * f2.GetDen()) > (this->GetDen() * f2.GetNum());
}

bool Fracao::operator>(int num) const
{
    return *this > Fracao(num);
}

bool operator>(int num, const Fracao &o1)
{
    return Fracao(num) > o1;
}

bool Fracao::operator>=(const Fracao &f2) const
{
    return (this->GetNum() * f2.GetDen()) >= (this->GetDen() * f2.GetNum());
}

bool operator<(const Fracao &fe, const Fracao &fd)
{
    return (fe.GetNum() * fd.GetDen()) < (fe.GetDen() * fd.GetNum());
}

Fracao operator*(int num, const Fracao &o1)
{
    return o1 * num;
}

ostream &operator<<(ostream &output, const Fracao &fracao)
{
    output << fracao.GetNum() << "/" << fracao.GetDen();
    return output;
}

istream &operator>>(istream &input, Fracao &fracao)
{
    int num, den;
    cout << "Numerador: ";
    input >> num;
    cout << "Denominador: ";
    input >> den;

    fracao.SetNum(num);
    fracao.SetDen(den);

    return input;
}

int main()
{
    Fracao f_a(1, 4), f_b(1, 2);
    Fracao f_c(3);
    Fracao f_d;

    cout << f_a << endl;
    cout << f_b << endl;
    cout << f_c << endl;
    cout << f_d << endl;
    cout << endl;

    Fracao soma = f_a + f_b;
    cout << soma << endl;

    Fracao sub = f_b - f_a;
    cout << sub << endl;

    Fracao mult = f_a * f_b;
    cout << mult << endl;
    cout << endl;

    int k = 2;

    Fracao soma_int = f_a + k;
    cout << soma_int << endl;

    Fracao mult_int_esq = k * f_a;
    cout << mult_int_esq << endl;

    Fracao mult_int_dir = f_b * 3;
    cout << mult_int_dir << endl;
    cout << endl;

    Fracao f_maior(3, 5);
    Fracao f_menor(1, 2);

    cout << (f_maior > f_menor ? "Verdadeiro" : "Falso") << endl;
    cout << (f_menor < f_maior ? "Verdadeiro" : "Falso") << endl;
    cout << endl;

    Fracao f_inc(5, 4);

    Fracao pre_inc = ++f_inc;
    cout << f_inc << endl;

    Fracao pos_inc = f_inc++;
    cout << f_inc << endl;
    cout << pos_inc << endl;
    cout << endl;

    Fracao f_io;
    cin >> f_io;
    cout << f_io << endl;

    return 0;
}