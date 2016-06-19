#ifndef _WRITEFILMS_H
#define _WRITEFILMS_H

#include <fstream>
#include <iostream>
#include "listFilms.h"


void writeInFile(ListFilms& films,std::string file,int key,int hist=0);
//funkcija za upis filmova u file, koristi se za historiju filova, i glavnu listu filmova
// dodatni parametar hist za funkciju koja cita je potreban zbog file-a historija filmova,koja na pocetku ne sadrzi vrijednost kljuca



#endif
