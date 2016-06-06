#ifndef _LISTFILMS_H
#define _LISTFILMS_H

#include "film.h"
#include "listaNizom.hxx"
#include <iostream>

class ListFilms :public ListaNizom<Film>{
  public:
    ListFilms(int n=1000):ListaNizom(n){}
    ListFilms& addFilm(Film&); // dodaje korisnika u listu,i sortira, O(n)
    void printListFilms()const;// ispisuje sve filmove iz liste, njihovu naziv i godinu proizvodnje


};

#endif
