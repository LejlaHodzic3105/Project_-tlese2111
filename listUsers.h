#ifndef _LISTUSERS_H
#define _LISTUSERS_H

#include "user.h"
#include "lista.hxx"
#include <iostream>

class ListUsers :public list<User>{
  public:
    ListUsers(){};
    ListUsers& addUser(User&); // dodaje korisnika u listu,i sortira
    void printListUsers()const; //ispisuje listu korisnika
    User findUserByName(const std::string& name, const std::string& surname);//trazi korisnika po imenu i prezimenu
    User findUserByUsername(const std::string& username); //trazi korisnika po usernameu
    void removeUser(const std::string &s1, const std::string &s2=""); //brise korisnika, ima defaultni parametar s2 koji omogucava brisanje po 										usernameu i po imenu i prezimenu
    void updateUser(const std::string &s1,const std::string &s2=""); //azurira korisnika, defaultni parametar s2 bas kao kod brisanja
    bool findUserByUsernameBool(const std::string& username); //trazi korisnika po usernameu, ali vraca bool


};

#endif
