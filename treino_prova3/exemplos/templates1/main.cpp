#include <iostream>
using namespace std;

template <class T>

class Coordenadas
{
private:
    T x, y;

public:
    Coordenadas(T, T);
    void Set(T, T);
    void Get(T &, T &) const;
    T GetX(void) const;
    T GetY(void) const;
};

template <class T>
Coordenadas<T>::Coordenadas(T coord_x, T coord_y)
{
    this->x = coord_x;
    this->y = coord_y;
}

template <class T>
void Coordenadas<T>::Set(T x, T y)
{
    this->x = x;
    this->x = y;
}

template <class T>
void Coordenadas<T>::Get(T &x, T &y) const
{
    x = this->x;
    y = this->y;
}

template <class T>
T Coordenadas<T>::GetX(void) const
{
    return x;
}

template <class T>
T Coordenadas<T>::GetY(void) const
{
    return y;
}

int main(int argc, char *argv[])
{
    int X = 10, Y = 20;
    double Z = 11.1, W = 22.2;

    Coordenadas<int> Posicao_inteira(X, Y);
    Coordenadas<double> Posicao_precisa(Z, W);

    cout << Posicao_inteira.GetX() << " " << Posicao_inteira.GetY() << endl;
    cout << Posicao_precisa.GetX() << " " << Posicao_precisa.GetY() << endl;

    return 0;
}