#include <iostream>

using namespace std;

class Fracao
{
public:
    Fracao(int n = 0, int d = 1);
    void SetNum(int n);
    void SetDen(int d);
    int GetNum() const;
    int GetDen() const;

private:
    int num;
    int den;
};

Fracao::Fracao(int n, int d)
{
    SetNum(n);
    SetDen(d);
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

int main(){
    
}