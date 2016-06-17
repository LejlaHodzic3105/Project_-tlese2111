#ifndef _READUSERS_H
#define _READUSERS_H

#include "user.h"
#include "listUsers.h"
#include "administrator.h"
#include "split.h"
#include "listFilms.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>

void readUsers(std::string,ListUsers&,ListFilms&,Administrator&); // funkcija za citanje fajla korisnika 

#endif
