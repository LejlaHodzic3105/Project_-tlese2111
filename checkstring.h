#ifndef _CHECKSTRING_H
#define _CHECKSTRING_H

#include<string>
bool check_string_all_digits(const std::string &a);// provjeri da li su svi brojevi
bool check_string_for_spaces(const std::string &a);//provjeri ima li praznih mjesta u stringu
bool is_integer(char niz[10]); //provjerava da li je proslijedjeni niz karaktera integer, koristi se pri svim unosima integera da bi se izbjegla 					 beskonacna petlja pri pogresnom unosu integera
int enter_int(); //za ispravan unos integera, poziva funkciju is_integer iznad

#endif
