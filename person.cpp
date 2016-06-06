#include "person.h"

void Person::setPerson(const std::string& name, const std::string& surname)
{
  _name=name;
  _surname=surname;
}

 void Person::printPerson() const
{
  std::cout<<_name << " " <<_surname;
}


std::ostream& operator<<(std::ostream& out, const Person& person)
{
  out<<person._name<<" "<<person._surname;
  return out;
}

