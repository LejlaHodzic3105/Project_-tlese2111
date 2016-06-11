#ifndef _USERACCOUNT_H
#define _USERACCOUNT_H

#include<iostream>

class UserAccount{

  private:
  std::string _username;
  std::string _password;

  public:
  UserAccount()=default;
  UserAccount(std::string username, std::string password){_username=username; _password=password;}
  ~UserAccount()=default;
  const std::string& getUsername(){return _username;}
  void setUserAccount(std::string username, std::string password){_username=username; _password=password;}
  std::string getUsername()const{return _username;}

};

#endif
