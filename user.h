#ifndef _USER_H
#define _USER_H

#include<ctime>
#include <iostream>
#include "person.h"
#include "date.h"
#include "lista.hxx"
#include "film.h"
#include "useraccount.h"


class User: public Person
{
  private:
  Date _date;
  std::string _unob;// unique numer of birth
  UserAccount _useracc;
  list<Film> _history;
  list<Film> _borrowedFilms;
  int _nobf; //number of borrowd films

  

  public:
  User(){_nobf=0;}
  User(const std::string& name,const std::string& surname,std::string& unob,std::string& username,std::string& password);// datum se uzima automatski sa racunara
  ~User()=default;
  User& setUser(const std::string& name,const std::string& surname,const std::string& unob,const std::string& username,const std::string& password,int day,int month,int year,int nobf);
  const std::string getUnob()const{return _unob;}
  const Date& getDate() const{return _date;}
  UserAccount& getUserAcc(){ return _useracc;}
  list<Film>& getHistory(){ return  _history; }
  list<Film>& getBorrowed(){return _borrowedFilms;}
  int getNobf(){return _nobf;} 
  User& setDate(const Date& date){_date=date; return *this;}
  User& setUnob(const std::string& unob){_unob=unob; return *this;}
  User& setAccount(const std::string& username,const std::string& password){_useracc.setUserAccount(username,password); return *this;}
  User& setHistory(const Film& film){_history.push_back(film); return *this;}
  User& setBorrowed(const Film& film){_borrowedFilms.push_back(film); return *this;}
  User& setNobf(int nobf){_nobf=nobf; return *this;}
  friend std::ostream& operator<<(std::ostream& out, const User& user);
  void borrowFilm(Film& film);// nije const& jer se mora promijeniti _numofCopies
  void returnFilm(Film& film);
  void printHistory()const;
  void printBorrowedFilms()const;
  bool operator==(const User& user);
  void printUser()const;
  bool operator!=(const User& user);
};



#endif
