#include<iostream>

#include"administrator.h"
#include"listFilms.h"
#include"listUsers.h"
#include "readUsers.h"

using namespace std;

int main(){

ListUsers lista;



cout << "dodajem usera:" << endl;
cout << "unesite ime: ";
string ime;
getline(cin,ime);
cout << "unesite prezime: ";
string prezime;
getline(cin,prezime);
cout << "Unesite maticni broj: ";
string broj;
getline(cin,broj);
cout << "unesite username: ";
string username;
getline(cin,username);
cout << "unesite password: ";
string password;
getline(cin,password);
User novi=User(ime,prezime,broj,username,password);
lista.addUser(novi);
lista.printListUsers();
cout << novi.getUserAcc().getUsername() << endl;

cout << "dodajem usera:" << endl;
cout << "unesite ime: ";
string ime2;
cin>>ime2;
cout << "unesite prezime: ";
string prezime2;
cin>>prezime2;
cout << "Unesite maticni broj: ";
string broj2;
cin>>broj2;
cout << "unesite username: ";
cin.ignore();
string username2;
getline(cin,username2);
cout << "unesite password: ";
string password2;
getline(cin,password2);
User novi2=User(ime2,prezime2,broj2,username2,password2);
lista.addUser(novi2);
lista.printListUsers();



lista.updateUser(ime,prezime);

lista.printListUsers();
cout << "Unesite username korisnika za brisanje" << endl;
string brisi1,brisi2;
cin >> brisi1;

lista.removeUser(brisi1);
lista.printListUsers();

//ListFilms filmovi;
//int i=1;
//while(i<3){
//cout<<"dodajem film"<<endl;
//Film film;
//cout<<" Unesite naziv filma: "<< endl;
//string naziv;
//cin>>naziv;
//film.setTitle(naziv);
//cout<<"Unesite opis filma: "<<endl;
//string opis;
//cin>>opis;
//film.setDescription(opis);
//cout<<"Unesite kompaniju filma: "<<endl;
//string comp;
//cin>>comp;
//film.setCompany(comp);
//cout<<"Unesite godinu proizvodnje "<<endl;
//int godina;
//cin>>godina;
//film.setYear(godina);
//filmovi.addFilm(film);

//i++;
//}
//filmovi.printListFilms();
//filmovi.printAllInfo("love");
//filmovi.updateFilm("love");
//filmovi.printListFilms();




//ja promijenio main

return 0;
}

