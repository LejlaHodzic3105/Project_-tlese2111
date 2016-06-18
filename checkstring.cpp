#include "checkstring.h"
bool check_string_all_digits(const std::string &a)
{
  bool numbers=true;
  for(int i=0;i<a.size();i++) numbers=numbers && (a[i]>='0' && a[i]<='9'); // provjerava jesu li sve brojevi
  return numbers;
}

bool check_string_for_spaces(const std::string &a)
{
  for(int i=0;i<a.size();i++) if(a[i]==' ') return true;
  return false;
}

