#ifndef DATA_H
#define DATA_H

class Data
{
public:
    Data(int dia, int mes, int ano);
    ~Data();
    void imprimePorExtenso() const;
    void imprime() const;
    bool anoBissexto() const;
    int compare(const Data &data) const;

private:
    int dia;
    int mes;
    int ano;
};

#endif /* DATA_H */