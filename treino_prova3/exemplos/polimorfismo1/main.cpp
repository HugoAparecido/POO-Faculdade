#include <iostream>

class Ave
{
public:
    virtual void MostrarNome() const
    {
        std::cout << "Sou uma ave";
    }
    virtual ~Ave() {}
};

class Cisne : public Ave
{
public:
    void MostrarNome() const
    {
        std::cout << "Sou um cisne";
    }
};

int main()
{
    Ave *p_ave = new Cisne;

    p_ave->MostrarNome();

    delete p_ave;
}