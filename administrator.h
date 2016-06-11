#ifndef _ADMINISTRATOR_H
#define _ADMINISTRATOR_H

#include "useraccount.h"
#include "person.h"

class Administrator: public Person
{
  private:
  UserAccount _useracc;

  public:
  Administrator():Person("William","Watson"){_useracc.setUserAccount("William_W","newPasscode");}
  ~Administrator()=default;

};


#endif
