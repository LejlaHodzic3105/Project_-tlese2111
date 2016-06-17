#ifndef _OPCIJE_H
#define _OPCIJE_H

#include"administrator.h"
#include<string>
#include<iostream>
#include"listFilms.h"
#include"listUsers.h"
void optionsAdmin(ListFilms &,ListUsers &,int &,Administrator &);
void optionsUser(ListFilms &,ListUsers &,ListFilms &,User&,Administrator &,int);

#endif
