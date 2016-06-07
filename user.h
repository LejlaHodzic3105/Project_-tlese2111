#ifndef _USER_H
#define _USER_H

#include <iostream>
#include "person.h"
#include "date.h"
#include "listaNizom.hxx"
#include "film.h"
#include "useraccount.h"


class User: public Person
{
  private:
  Date _date;
  std::string _unob;// unique numer of birth
  UserAccount _useracc;
  ListaNizom<Film> _history;
  ListaNizom<Film> _borrowedFilms;
  int _nobf; //number of borrowd films

  

  public:
  User(){_nobf=0;}
  User(const std::string& name,const std::string& surname,const std::string& unob,int year,int month,int day,const std::string& username,const std::string& password):Person(name,surname){_date.setDate(year,month,day); _unob=unob;_useracc.setUserAccount(username,password);}
  ~User()=default;
  const std::string getUnob()const{return _unob;}
  const Date& getDate() const{return _date;}
  User& setDate(const Date& date){_date=date; return *this;}
  User& setUnob(const std::string& unob){_unob=unob; return *this;} 
  friend std::ostream& operator<<(std::ostream& out, const User& user);
  int getNobf(){return _nobf;} 
  UserAccount& getUserAcc(){ return _useracc;}
  void borrowFilm(const Film& film);
  void returnFilm(const Film& film);
  void printHistory();
  void printBorrowedFilms();
  bool operator==(const User& user);
  bool operator!=(const User& user);
};



#endif
