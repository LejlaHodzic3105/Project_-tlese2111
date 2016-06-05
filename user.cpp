#include "user.h"

std::ostream& operator<<(std::ostream& out, const User& user)
{
  user.print();
  out<<" "<<user.getUnob()<<std::endl;
  user.getDate().printDate();

  return out;
}
