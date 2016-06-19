#ifndef _OPCIJE_H
#define _OPCIJE_H

#include"administrator.h"
#include<string>
#include<iostream>
#include"listFilms.h"
#include"listUsers.h"
#include"checkstring.h" //radi provjere inta
void optionsAdmin(ListFilms &,ListUsers &,int &,Administrator &); //opcije za admina
void optionsUser(ListFilms &,ListUsers &,ListFilms &,User&,Administrator &,int); //opcije za usera

#endif
