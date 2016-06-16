#include "user.h"
#include "checkstring.h"

std::ostream& operator<<(std::ostream& out, const User& user)
{
  user.printPerson();
  out<<" "<<user.getUnob()<<std::endl;
  user.getDate().printDate();

  return out;
}

bool check_string_all_digits(const string &a);

bool check_string_for_spaces(const string &a);

User::User(const std::string& name,const std::string& surname,std::string& unob,std::string& username,std::string& password):Person(name,surname)
{   int year,month,day;
    time_t t = time(0);
    struct tm * now = localtime( & t );
    _date.setDate((now->tm_year + 1900),(now->tm_mon + 1),now->tm_mday);
    while(unob.size()!=13 || !check_string_all_digits(unob))
    {   std::cout << "Jedistveni maticni broj se mora sastojati iskljucivo od 13 cifara, molimo unesite ga ponovo: ";
	getline(std::cin,unob);
    }
    _unob=unob;
    while(check_string_for_spaces(username))
    {
	std::cout << "Username ne smije sadrzavati prazno mjesto, molimo unesite novi username: ";
	getline(std::cin,username);
    }
    while(check_string_for_spaces(password))
    {
	std::cout << "Password ne smije sadrzavati prazno mjesto, molimo unesite novi password: ";
	getline(std::cin,password);
    }
    _useracc.setUserAccount(username,password);
}


User& User::setUser(const std::string& name,const std::string& surname,const std::string& unob,const std::string& username,const std::string& password,int day,int month,int year,int nobf)
{
  _date.setDate(year,month,day);
  _unob=unob;
  _nobf=nobf;
  _useracc.setUserAccount(username,password);
  (*this).setPerson(name,surname);
  
  return *this;
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

