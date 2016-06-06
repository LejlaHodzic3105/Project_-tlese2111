#ifndef _USER_H
#define _USER_H

#include <iostream>
#include "person.h"
#include "date.h"
#include "listaNizom.hxx"
#include "film.h"


class User: public Person
{
  private:
  Date _date;
  std::string _unob;// unique numer of birth
  std::string _username;
  std::string _password;
  ListaNizom<Film> _history;
  ListaNizom<Film> _borrowedFilms;

  

  public:
  User()=default;
  User(const std::string& name,const std::string& surname,const std::string& unob,int year,int month,int day,const std::string& username,const std::string& password):Person(name,surname){_date.setDate(year,month,day); _unob=unob; _username=username; _password=password;}
  ~User()=default;
  const std::string getUnob()const{return _unob;}
  const Date& getDate() const{return _date;}
  User& setDate(const Date& date){_date=date; return *this;}
  User& setUnob(const std::string& unob){_unob=unob; return *this;}
  bool operator>(const User& b) const;
  bool operator<(const User& b) const;  
  friend std::ostream& operator<<(std::ostream& out, const User& user);  

};



#endif
