#include "horario.h"
#include <cstdio>

void horario::sethorario(int h, int m, int s)
{
    hora = (h >= 0 && h < 24) ? h : 0;
    minuto = (m >= 0 && m < 60) ? m : 0;
    segundo = (s >= 0 && s < 60) ? s : 0;
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