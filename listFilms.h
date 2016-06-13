#ifndef _LISTFILMS_H
#define _LISTFILMS_H

#include "film.h"
#include "lista.hxx"
#include <iostream>
#include <string>

class ListFilms :public list<Film>{
  public:
    ListFilms(){};
    ListFilms& addFilm(Film&); // dodaje korisnika u listu,i sortira, O(n)
    void printListFilms()const;// ispisuje sve filmove iz liste, njihovu naziv i godinu proizvodnje
    Film findFilm(const string& film)const;
    void removeFilm(const string& film);
    void updateFilm(const string& film);
    void printAllInfo(const string& film)const; // opcija pregleda svih podataka za odabrani film

};

#endif
