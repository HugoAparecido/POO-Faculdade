#include <iostream>
#include "horario.h"

using namespace std;

int main()
{
    horario acordar(7, 30, 00);
    horario comer(11, 30);
    horario dormir;

    int horario_comer;
    cin >> horario_comer;

    cout << "horario de acordar: ";
    acordar.printStandard();
    cout << "horario de comer: ";
    comer.printStandard();
    cout << "horario de dormir: ";
    dormir.printStandard();

    comer.set_hour(13);
    cout << endl
         << "horario de comer modifiicado: ";
    comer.printStandard();

    cout << "Dormir apos " << dormir.get_hour() << " horas" << endl;
    system("PAUSE");

    return 0;
}