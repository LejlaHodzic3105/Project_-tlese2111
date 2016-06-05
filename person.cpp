#include "person.h"

void Person::setPerson(const std::string& name, const std::string& surname)
{
  _name=name;
  _surname=surname;
}

 void Person::print() const
{
  std::cout<<"Person: "<<_name << " " <<_surname;
}

