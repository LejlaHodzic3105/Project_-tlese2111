#include "listFilms.h"

ListFilms& ListFilms::addFilm(Film& film)
{
  if(prazna())
    dodajNaKraj(film);

  else
  {
    for(int i=0;i<(*this).velicina();i++)
    {
      if(elementi[i].getYear()<film.getYear())
      {
        dodajNaLokaciju(i,film);
        return *this;
      }
      else
      {
        i++;
      }
    }
  }
dodajNaKraj(film);
  return *this;
}


void ListFilms::printListFilms()const
{
  for(int i=0;i<(*this).velicina();i++)
    elementi[i].printFilm();
}
