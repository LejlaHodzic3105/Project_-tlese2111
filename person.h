#ifndef _PERSON_H
#define _PERSON_H

#include <iostream>
#include <string>



class Person
{
  private: 
    std::string _name;
    std::string _surname;
  public:
    Person()=default;
    Person(const std::string& name, const std::string& surname) : _name(name), _surname(surname){};
    std::string getName() const{return _name;}
    std::string getSurname() const{return _surname;}
    void setPerson (const std::string& name, const std::string& surname); 
    void printPerson() const;
    ~Person()=default;
    friend std::ostream& operator<<(std::ostream& out, const Person& person); 

};



#endif
