#ifndef VETOR3D
#define VETOR3D

#include <iostream>

class Vetor3D
{
private:
    int x;
    int y;
    int z;

public:
    Vetor3D(int x, int y, int z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    };

    friend std::ostream &operator<<(std::ostream &saida, const Vetor3D &obj)
    {
        saida << "(" << obj.x << ", " << obj.y << ", " << obj.z << ")";
        return saida;
    };
};

#endif