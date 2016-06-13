#ifndef _LISTUSERS_H
#define _LISTUSERS_H

#include "user.h"
#include "lista.hxx"
#include <iostream>

class ListUsers :public list<User>{
  public:
    ListUsers(){};
    ListUsers& addUser(User&); // dodaje korisnika u listu,i sortira, O(n)
    void printListUsers()const;
    User findUserByName(const std::string& name, const std::string& surname);
    User findUserByUsername(const std::string& username);
    void removeUser(const std::string &s1, const std::string &s2="");
    void updateUser(const std::string &s1,const std::string &s2="");
    bool findUserByUsernameBool(const std::string& username);


};

#endif
