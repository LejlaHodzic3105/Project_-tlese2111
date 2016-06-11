#include "user.h"

std::ostream& operator<<(std::ostream& out, const User& user)
{
  user.printPerson();
  out<<" "<<user.getUnob()<<std::endl;
  user.getDate().printDate();

  return out;
}

void User::borrowFilm(Film& film){
  if(film.getNumOfCopies()==0) cout<<"Film trenutno nije dostupan!"<<std::endl;
  else if(_nobf==3) cout << "Mozete posuditi maksimalno tri filma. Molimo pokusajte ponovo nakon sto vratite neki od filmova." << std::endl;
  else{
  _nobf++;
  _borrowedFilms.push_back(film);
  _history.push_back(film);
  film.setNumOfCopies(film.getNumOfCopies()-1);
  cout << "Uspjesno ste posudili film." << endl;
}
}

void User::returnFilm(Film& film){
  _nobf--;
  film.setNumOfCopies(film.getNumOfCopies()+1);
  _borrowedFilms.pop(film);
  cout << "Uspjesno ste vratili film." << endl;
}

void User::printHistory(){
  auto it=_history.begin();
  while(it!=_history.end())
  {
    (*it).getInfo().printFilm();
    it++;
  }
 }

void User::printBorrowedFilms(){
  auto it=_borrowedFilms.begin();
  while(it!=_borrowedFilms.end())
  {
    (*it).getInfo().printFilm();
    it++;
  }
 }

bool User::operator==(const User& user){
  return _useracc.getUsername()==user._useracc.getUsername();
}

bool User::operator!=(const User& user){
  return _useracc.getUsername()!=user._useracc.getUsername();
}

