#include "Playlist.h"
#include "Podcast.h"
#include "Filme.h"

int main()
{
    Playlist<Midia> minhaPlaylist(5);

    Midia *filme1 = new Filme("Tranformers", 7200, "HD");
    Midia *podcast1 = new Podcast("Como jogar", 3600, "M4");

    minhaPlaylist.Adicionar(filme1);
    minhaPlaylist.Adicionar(podcast1);

    minhaPlaylist.ListarInfo();
    minhaPlaylist.TocarTudo();

    delete filme1;
    delete podcast1;

    return 0;
}