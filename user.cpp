#include "user.h"
#include "checkstring.h"

std::ostream& operator<<(std::ostream& out, const User& user)
{
  user.printPerson();
  out<<" "<<user.getUnob()<<std::endl;
  user.getDate().printDate();

  return out;
}

void User::printUser() const
{
  (*this).printPerson();
  std::cout<<" "<< _unob<<" "<< _nobf<< " ";
  (*this).getDate().printDate();
  (*this).printHistory();
  (*this).printBorrowedFilms();


}

User::User(const std::string& name,const std::string& surname,std::string& unob,std::string& username,std::string& password):Person(name,surname)
{   int year,month,day;
    time_t t = time(0);
    struct tm * now = localtime( & t );
    _date.setDate((now->tm_year + 1900),(now->tm_mon + 1),now->tm_mday);
    while(unob.size()!=13 || !check_string_all_digits(unob))
    {   std::cout << "Unique number of birth must contain exactly 13 digits. Please enter it correctly: ";
	getline(std::cin,unob);
    }
    _unob=unob;
    while(check_string_for_spaces(username))
    {
	std::cout << "Username can't contain blank spaces. Please enter a new one: ";
	getline(std::cin,username);
    }
    while(check_string_for_spaces(password))
    {
	std::cout << "Password can't contain blank spaces. Please enter a new one: ";
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
  if(film.getNumOfCopies()==0) cout<<"Film is not available!"<<std::endl;
  else if(_nobf==3) cout << "You can borrow only 3 films. First return one of films." << std::endl;
  else{
  _nobf++;
  _borrowedFilms.push_back(film);
  if(!isBorrowed(film))
  _history.push_back(film);
  film.setNumOfCopies(film.getNumOfCopies()-1);
  cout << "You have succesfully borrowed "<< film.getTitle() << endl;
}
}

void User::returnFilm(Film& film){
  if(isBorrowed(film)){
  _nobf--;
  film.setNumOfCopies(film.getNumOfCopies()+1);
  _borrowedFilms.pop(film);
  std::cout << "You have successfully returned film." << std::endl;
}
  else std::cout << "You havent borrowed that film yet." << std::endl;
}

bool User::isBorrowed(const Film& film)const{
  if(!_borrowedFilms.empty()){
  auto it=_borrowedFilms.begin();
  while(it!=_borrowedFilms.end())
  {
    if((*it).getInfo()==film) return true;
    it++;
  }}
  return false;
}

void User::printHistory()const{
  std::cout<<"History of borrowed films:"<<std::endl;
  if(!_history.empty()){
  auto it=_history.begin();
  while(it!=_history.end())
  {
    (*it).getInfo().printFilm();
    it++;
  }}
 }

void User::printBorrowedFilms()const{
  std::cout<<"Borrowed films:"<<std::endl;
  if(!_borrowedFilms.empty()){
  auto it=_borrowedFilms.begin();
  while(it!=_borrowedFilms.end())
  {
    (*it).getInfo().printFilm();
    it++;
  }}
 }

bool User::operator==(const User& user){
  return _useracc.getUsername()==user._useracc.getUsername();
}

bool User::operator!=(const User& user){
  return _useracc.getUsername()!=user._useracc.getUsername();
}

