#ifndef _WRITEUSERS_H
#define _WRITEUSERS_H

#include <fstream>
#include <iostream>
#include "listUsers.h"
#include "administrator.h"


void writeUsers(ListUsers& users,std::string file,Administrator& admin);



#endif
