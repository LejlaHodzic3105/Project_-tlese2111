#include "date.h"

void Date::printDate() const
{
  std::cout<<"\033[1;34mDate: \033[0m"<<_day<<"."<<_month<<"."<<_year<<std::endl;
}
