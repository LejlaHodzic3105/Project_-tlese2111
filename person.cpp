#include "person.h"

void Person::setPerson(const std::string& name, const std::string& surname, const std::string& unof)
{
  _name=name;
  _surname=surname;
  _unof=unof;
}

 void Person::print() const
{
  std::cout<<"Person: "<<_name << " " <<_surname << ", " <<_unof;
}

