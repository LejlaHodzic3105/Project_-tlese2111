#ifndef _PERSON_H
#define _PERSON_H

#include <iostream>
#include <string>



class Person
{
  private: 
    std::string _name;
    std::string _surname;
    std::string _unof; // unique number of birth
  public:
    Person()=default;
    Person(const std::string& name, const std::string& surname,const std::string& unof) : _name(name), _surname(surname), _unof(unof) {};
    std::string getName() const{return _name;}
    std::string getSurname() const{return _surname;}
    std::string getUnof() const{return _unof;}
    void setPerson(const std::string& name, const std::string& surname, const std::string& unof); 
    void print() const;
    ~Person()=default;   

};



#endif
