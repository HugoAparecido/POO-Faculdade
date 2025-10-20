#include <iostream>

using namespace std;

class Fracao
{
public:
    Fracao()
    {
        SetNum(0);
        SetDen(1);
    }
    Fracao(int n, int d)
    {
        SetNum(n);
        SetDen(d);
    }
    Fracao(int n)
    {
        SetNum(n);
        SetDen(1);
    }
    void SetNum(int n);
    void SetDen(int d);
    int GetNum() const;
    int GetDen() const;
    void Mostrar();
    Fracao Mult(Fracao f2) const;
    Fracao operator*(int num) const
    {
        return Fracao(GetNum() * num, GetDen());
    };
    //friend Fracao operator++(Fracao o1);
    //friend Fracao operator++(Fracao o1);
    Fracao operator++(int);
    Fracao& operator++();

private:
    int num;
    int den;
};


/*Fracao Fracao::operator++(Fracao &f, int)
{
    Fracao temp(f);
    f.num += f.den;
    return temp;
}
*/
Fracao Fracao::operator++(int)
{
    Fracao temp(*this);
    num += den;
    return temp;
}

/*

Fracao& Fracao::operator++(fracao& f){
    f.num += f.den;
    return f;
}

*/

Fracao& Fracao::operator++(){
    num += den;
    return *this;
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

void Fracao::Mostrar()
{
    cout << GetNum() << "/" << GetDen() << endl;
}

Fracao Fracao::Mult(Fracao f2) const
{
    return Fracao(this->GetNum() * f2.GetNum(), this->GetDen() * f2.GetDen());
}

Fracao operator*(Fracao o1, Fracao o2)
{
    return Fracao(o1.GetNum() * o2.GetNum(), o1.GetDen() * o2.GetDen());
}

/*Fracao operator*(Fracao o1, int num)
{
    return Fracao(o1.GetNum() * num, o1.GetDen());
}*/

Fracao operator*(int num, Fracao o1)
{
    return o1 * num;
}

int main()
{
    Fracao f1(2, 3);
    Fracao f2(5, 6);
    Fracao multi = f1 * f2;
    multi.Mostrar();

    Fracao f3(8, 6);
    multi = f3.Mult(f2);
    multi.Mostrar();

    multi = f1 * 7;
    multi.Mostrar();

    multi = 12 * f2;
    multi.Mostrar();

    Fracao f4(3, 5);
    f4.Mostrar();
    Fracao f5 = f4++;
    f4.Mostrar();
    f5.Mostrar();
    Fracao f6 = ++f4;
    f4.Mostrar();
    f6.Mostrar();
}