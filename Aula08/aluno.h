#include <string>
#include <vector>

using namespace std;

class Aluno
{
public:
    Aluno(string nome, int qtdeNotas, double *notas);
    ~Aluno();
    // getters
    string GetNome() const;
    int GetRA() const;
    bool GetNotas(double *notas) const;
    bool GetNota(int pos, double &val) const;
    int GetQtdNotas() const;
    // setters
    void SetNome(string nome);
    bool SetNotas(int qtdeNotas, double *notas);
    void SetQtdNotas(int qtdeNotas);
    // outros
    static void IncrementarContador();
    void ImprimeTodasNotas() const;

private:
    static int contador;
    const int RA;
    string nome;
    int qtdeNotas;
    vector<double> notas;
};