#include <cstdio>
#include <iostream>

using namespace std;

class horario
{
public:
    horario(int = 0, int = 0, int = 0);
    void sethorario(int, int, int);
    void printUniversal();
    void printStandard();
    // getters
    int get_hour();
    int get_minute();
    int get_second();
    // setters
    void set_hour(int h) { hora = (h >= 0 && h < 24) ? h : 0; }
    void set_minutes(int m) { minuto = (m >= 0 && m < 60) ? m : 0; }
    void set_seconds(int s) { segundo = (s >= 0 && s < 60) ? s : 0; }

private:
int hora;
int minuto;
    int segundo;
};

void horario::sethorario(int h, int m, int s)
{
    set_hour(h);
    set_minutes(m);
    set_seconds(s);
}

horario::horario(int h, int m, int s)
{
    sethorario(h, m, s);
}

void horario::printUniversal()
{
    printf("%02d:%02d:%02d\n", hora, minuto, segundo);
}

void horario::printStandard()
{
    printf("%02d:%02d:%02d %s\n", (hora == 0 || hora == 12) ? 12 : hora % 12, minuto, segundo, (hora < 12) ? "AM" : "PM");
}

int horario::get_hour()
{
    return hora;
}
int horario::get_minute()
{
    return minuto;
}
int horario::get_second()
{
    return segundo;
}

int main()
{
    horario acordar(7,30,00);
    horario comer(11, 30);
    horario dormir;

    cout << "horario de acordar: ";
    acordar.printStandard();
    cout << "horario de comer: ";
    comer.printStandard();
    cout << "horario de dormir: ";
    dormir.printStandard();

    comer.set_hour(13);
    cout << endl << "horario de comer modifiicado: ";
    comer.printStandard();

    cout<<"Dormir apos " << dormir.get_hour()<< " horas"<<endl;
    system("PAUSE");

    return 0;
}