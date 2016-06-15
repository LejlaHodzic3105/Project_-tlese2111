#include<iostream>

#include"administrator.h"
#include"listFilms.h"
#include"listUsers.h"

using namespace std;

int main(){

ListUsers lista;

cout << "dodajem usera:" << endl;
User user;
cout << "unesite ime: ";
string ime;
cin>>ime;
cout << "unesite prezime: ";
string prezime;
cin>>prezime;
cout << "Unesite maticni broj: ";
string broj;
cin>>broj;
cout << "unesite username: ";
string username;
cin >>username;
cout << "unesite password: ";
string password;
cin >> password;
User novi=User(ime,prezime,broj,username,password);
lista.addUser(novi);
lista.updateUser(ime,prezime);

lista.printListUsers();
cout << "Unesite ime i prezime korisnika za brisanje" << endl;
string brisi1,brisi2;
cin >> brisi1;

lista.removeUser(brisi1);
lista.printListUsers();

ListFilms filmovi;
int i=1;
while(i<3){
cout<<"dodajem film"<<endl;
Film film;
cout<<" Unesite naziv filma: "<< endl;
string naziv;
cin>>naziv;
film.setTitle(naziv);
cout<<"Unesite opis filma: "<<endl;
string opis;
cin>>opis;
film.setDescription(opis);
cout<<"Unesite kompaniju filma: "<<endl;
string comp;
cin>>comp;
film.setCompany(comp);
cout<<"Unesite godinu proizvodnje "<<endl;
int godina;
cin>>godina;
film.setYear(godina);
filmovi.addFilm(film);
i++;
}
filmovi.printListFilms();
filmovi.updateFilm("love");
filmovi.printListFilms();




//ja promijenio main

return 0;
}

