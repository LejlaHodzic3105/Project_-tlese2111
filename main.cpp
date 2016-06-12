#include<iostream>

#include"administrator.h"
#include"listFilms.h"
#include"listUsers.h"

using namespace std;

int main(){

cout <<"semin commit" << endl;
ListFilms listafilmova;
cout << "dodajem film:" << endl;
Film novi_film;
cout << "unesite naziv: ";
string naziv;
getline(cin,naziv);
novi_film.setTitle(naziv);
cout << "unesite opis ";
string opis;
getline(cin,opis);
novi_film.setDescription(opis);
novi_film.setKey(listafilmova.size());
cout << "Unesite ime i prezime directora: ";
string ime,prezime;
cin >> ime >> prezime;
cin.ignore();
novi_film.setDirector(ime,prezime);
cout << "unestie produkcijsku kompaniju: ";
string kompanije;
getline(cin,opis);
novi_film.setCompany(opis);
cout << "unesite godinu izdavanja: ";
int god;
cin >>god;
novi_film.setYear(god);
cout << "unesite broj kopija: ";
cin >> god;
novi_film.setNumOfCopies(god);
listafilmova.addFilm(novi_film);
cout << "unesite koji film zelite da vidite detalje: ";
string trazi;
cin>>trazi;
listafilmova.printAllInfo(trazi);
//ja promijenio main

return 0;
}

