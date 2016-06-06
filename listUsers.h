#ifndef _LISTUSERS_H
#define _LISTUSERS_H

#include "user.h"
#include "lista.hxx"
#include <iostream>

class ListUsers :public list<User>{
  public:
    ListUsers(){}
    ListUsers& addUser(User&); // dodaje korisnika u listu,i sortira, O(n)
    void printListUsers()const;

};

#endif
