#ifndef _LISTFILMS_H
#define _LISTFILMS_H

#include "film.h"
#include "lista.hxx"
#include <iostream>
#include <string>

class ListFilms :public list<Film>{
  public:
    ListFilms(){};
    ListFilms& addFilm(Film&); // dodaje film u listu,i sortira
    void printListFilms()const;// ispisuje sve filmove iz liste, njihovu naziv i godinu proizvodnje
    void printListFilmsByTitle(std::string t)const; //ispisuje sve filmove sa datim nazivom
    Film findFilm(const string& film,int key=-1)const; //trazi film, parametar kljuc se koristi pri popunjavanju listi filmova za korisnika iz filea
    void removeFilm(const string& film); //brisanje filma
    void updateFilm(const string& film); //azuriranje filma
    void printAllInfo(const string& film)const; // opcija pregleda svih podataka za odabrani film
    bool isBorrowed(const Film& film)const; //provjerava da li je neki film posudjen

};

#endif
