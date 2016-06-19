#ifndef _ADMINISTRATOR_H
#define _ADMINISTRATOR_H

#include "useraccount.h"
#include "person.h"

class Administrator: public Person
{
  private:
  UserAccount _useracc;

  public:
  Administrator():Person("William","Watson"){_useracc.setUserAccount("William_W","newPasscode");}//administrator postoji od pocetka do kraja, ne dodaje se u sistem
  ~Administrator()=default;//destruktor
  void setAdmin(const std::string& name,const std::string& surname,const std::string& username,const std::string& password){(*this).setPerson(name,surname),(*this)._useracc.setUserAccount(username,password);}
  UserAccount& getUserAcc(){return _useracc;}

};


#endif
