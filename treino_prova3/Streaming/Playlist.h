#ifndef PLAYLISTS
#define PLAYLISTS

#include <iostream>

template <typename T>
class Playlist
{
private:
    T **lista;
    int tamanhoMaximo;
    int tamanhoAtual;

public:
    Playlist(int tamanhoMaximo)
    {
        this->tamanhoMaximo = (tamanhoMaximo > 0) ? tamanhoMaximo : 1;
        tamanhoAtual = 0;

        lista = new T *[this->tamanhoMaximo];
    }

    ~Playlist()
    {
        if (lista != nullptr)
            delete[] lista;
    }

    Playlist(const Playlist &) = delete;
    Playlist &operator=(const Playlist &) = delete;

    void Adicionar(T *item)
    {
        if (tamanhoMaximo == tamanhoAtual)
            std::cout << "Playlist cheia" << std::endl;
        else
        {
            lista[tamanhoAtual] = item;
            tamanhoAtual++;
        }
    }

    void TocarTudo()
    {
        for (int i = 0; i < tamanhoAtual; i++)
            lista[i]->Reproduzir();
    }

    void ListarInfo()
    {
        std::cout << "A Playlist tem " << tamanhoAtual << " midias";

        int duracaoTotal = 0;

        for (int i = 0; i < tamanhoAtual; i++)
            duracaoTotal += lista[i]->GetDuracao();

        std::cout << " com duracao de " << duracaoTotal << " segundos." << std::endl;
    }
};

#endif