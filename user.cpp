#include "user.h"

std::ostream& operator<<(std::ostream& out, const User& user)
{
  user.printPerson();
  out<<" "<<user.getUnob()<<std::endl;
  user.getDate().printDate();

  return out;
}

void User::borrowFilm(const Film& film){
  if(_nobf==3) cout << "Mozete posuditi maksimalno tri filma. Molimo pokusajte ponovo nakon sto vratite neki od filmova." << endl;
  else{
  _nobf++;
  _borrowedFilms.dodajNaKraj(film);
  _history.dodajNaKraj(film);
  cout << "Uspjesno ste posudili film." << endl;
}
}

void User::returnFilm(const Film& film){
  _nobf--;
  _borrowedFilms.ukloni(film);
  cout << "Uspjesno ste vratili film." << endl;
}

void User::printHistory(){
  for(int i=0;i<_history.velicina();i++)
  {
    _history.dohvatiEl(i).printFilm();
  }
}

void User::printBorrowedFilms(){
  for(int i=0;i<_borrowedFilms.velicina();i++)
  {
    _borrowedFilms.dohvatiEl(i).printFilm();
  }
}

bool User::operator==(const User& user){
  return _useracc.getUsername()==user._useracc.getUsername();
}

bool User::operator!=(const User& user){
  return _useracc.getUsername()!=user._useracc.getUsername();
}

