#include "checkstring.h"
#include<iostream>
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

bool is_integer(char niz[10]){
int j=0;
for(;j<10;j++)
if(niz[j]=='\0') break;
for(int i=0;i<j;++i)
if(!isdigit(niz[i])) return false;
return true;
}

int enter_int(){
char broj[10]; //za unos bilo kojeg inta, ovaj niz karaktera sa salje u funkciju iz is_integer (funkcija iznad)
std::cin >> broj;
while(!is_integer(broj)){
std::cin.ignore();
std::cout << "\033[1;31mWrong input. Please input an integer: \033[0m";
std::cin>>broj;
}
return atoi(broj);
}
