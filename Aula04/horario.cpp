#include <cstdio>
#include <iostream>
#include "horario.h"

using namespace std;

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
    printf("%02d:%02d:%02d\n", this->get_hour(), this->get_minute(), get_second());
}

void horario::printStandard()
{
    printf("%02d:%02d:%02d %s\n", (this->get_hour() == 0 || this->get_hour() == 12) ? 12 : this->get_hour() % 12, this->get_minute(), get_second(), (this->get_hour() < 12) ? "AM" : "PM");
}

int horario::get_hour()
{
    return (segundos / 3600);
}
int horario::get_minute()
{
    return (segundos / 60) % 60;
}
int horario::get_second()
{
    return segundos % 3600 % 60;
}

void horario::set_hour(int h)
{
    segundos %= 3600;
    segundos += (h >= 0 && h < 24) ? h * 3600 : 0;
}
void horario::set_minutes(int m)
{
    int aux = segundos / 3600;
    segundos %= 3600;
    segundos %= 60;
    segundos += aux * 3600;
    segundos += (m >= 0 && m < 60) ? m * 60 : 0;
}
void horario::set_seconds(int s)
{
    segundos -= segundos % 60;
    segundos += (s >= 0 && s < 60) ? s : 0;
}