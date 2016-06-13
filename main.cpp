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
getline(cin,ime);
cout << "unesite prezime: ";
string prezime;
getline(cin,prezime);
cout << "Unesite maticni broj: ";
string broj;
getline(cin,broj);
cout << "unestie dan mjesec godinu uclanjivanja ";
int dan,mjesec,godina;
cin >> dan >> mjesec >> godina;
cout << "unesite username: ";
string username;
cin >>username;
cout << "unesite password: ";
string password;
cin >> password;
User novi=User(ime,prezime,broj,dan,mjesec,godina,username,password);
lista.addUser(novi);

lista.printListUsers();
cout << "Unesite ime i prezime korisnika za brisanje" << endl;
string brisi1,brisi2;
cin >> brisi1;
lista.removeUser(brisi1);
lista.printListUsers();


//ja promijenio main

return 0;
}

