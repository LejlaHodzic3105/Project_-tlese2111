#include<iostream>
#include"administrator.h"
#include"listFilms.h"
#include"listUsers.h"
#include "readUsers.h"
#include "readFilms.h"
#include "options.h"
#include<unistd.h>

using namespace std;

int main(){
ListFilms listH; //lista historije filmova
ListUsers listU; //lista korisnika
ListFilms listF; //lista trenutnih filmova, ukoliko se neki film obrise, ostaje u listi historije filmova da bi se mogao koristiti kod historije  			   posudjivanja za usera
Administrator admin;
readFilms("history.txt",listH); //ucitavanje listi i kljuca iz fajlova
readUsers("users.txt",listU,listH,admin);
int key=0;
key=readFilms("films.txt",listF);

string username,password;
cout << "Please enter your username: ";
getline(cin,username);
while(!listU.findUserByUsernameBool(username) && username!=admin.getUserAcc().getUsername()) //ukoliko uneseni username ne pripada ni adminu ni 											       userima trazi novi unos
  {
     cout << "User with username " << username << " doesn't exist. Please enter a new username: ";
     getline(cin,username);
  }
if(username==admin.getUserAcc().getUsername()) //ukoliko username pripada adminu
{ password=getpass("Enter Administrator Password: "); //sakrivanje passworda
  while(password!=admin.getUserAcc().getPassword()){ //trazi unos novog passworda sve dok se ne unese tacan password
  password=getpass("Username and password do not match.Enter Administrator Password: "); 
  }
  cout << admin.getName() << ", welcome to videostore Mind Games!" << endl; //pozdravna poruka
  optionsAdmin(listF,listU,key,admin); //pokrece funkciju opcija za admina
}
else //ukoliko username pripada korisniku
{ password=getpass("Enter user account Password: ");  //sakrivanje passworda
  User newuser=listU.findUserByUsername(username); 
  while(newuser.getUserAcc().getPassword()!=password) //trazi unos novog passworda sve dok se ne unese tacan password
  {
     password=getpass("Username and password do not match.Enter user account Password: "); 
  }
  cout << newuser.getName() << ", welcome to videostore Mind Games!" << endl;
  optionsUser(listF,listU,listH,newuser,admin,key); //pokrece funkciju opcija za usera
}
return 0;
}

