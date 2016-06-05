#ifndef _USER_H
#define _USER_H

#include <iostream>
#include "person.h"
#include "date.h"

class User: public Person
{
  private:
  Date _date;

  public:
  User()=default;
  User(const std::string& name,const std::string surname,const std::string unof,int year,int month,int day):Person(name,surname,unof){_date.setDate(year,month,day);}
  ~User()=default;
  const Date& getDate() const{return _date;}
  User& setDate(const Date& date){_date=date; return *this;}
  friend std::ostream& operator<<(std::ostream& out, const User& user);  

};



#endif
