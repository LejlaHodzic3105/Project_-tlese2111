#ifndef _USER_H
#define _USER_H

#include <iostream>
#include "person.h"
#include "date.h"

class User: public Person
{
  private:
  Date _date;
  std::string _unob; // unique numer of birth

  public:
  User()=default;
  User(const std::string& name,const std::string surname,const std::string unob,int year,int month,int day):Person(name,surname){_date.setDate(year,month,day); _unob=unob;}
  ~User()=default;
  const std::string getUnob()const{return _unob;}
  const Date& getDate() const{return _date;}
  User& setDate(const Date& date){_date=date; return *this;}
  friend std::ostream& operator<<(std::ostream& out, const User& user);  

};



#endif
