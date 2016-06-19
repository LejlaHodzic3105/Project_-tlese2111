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

//konstruktor koji prima 5 parametara
User::User(const std::string& name,const std::string& surname,std::string& unob,std::string& username,std::string& password):Person(name,surname)
{   int year,month,day;
    _nobf=0; //broj posudjenih pri kreiranju je nula
    time_t t = time(0);
    struct tm * now = localtime( & t );
    _date.setDate((now->tm_year + 1900),(now->tm_mon + 1),now->tm_mday); //automatsko postavljanje datuma sa racunara
    while(unob.size()!=13 || !check_string_all_digits(unob)) //provjera validnosti jmbg
    {   std::cout << "\033[1;34mUnique number of birth must contain exactly 13 digits. Please enter it correctly: \033[0m";
	getline(std::cin,unob);
    }
    _unob=unob;
    while(check_string_for_spaces(username)) //provjera da li username ima prazno mjesto
    {
	std::cout << "\033[1;34mUsername can't contain blank spaces. Please enter a new one: \033[0m";
	getline(std::cin,username);
    }
    while(check_string_for_spaces(password) || password.size()<6) //provjera da li password ima prazno mjesto i da li je kraci od 6 karaktera
    {
	std::cout << "\033[1;34mPassword can't contain blank spaces and must have at least 6 characters. Please enter a new one: \033[0m";
	getline(std::cin,password);
    }
    _useracc.setUserAccount(username,password);
}

//setter za usera, ukoliko ne zelimo koristit konstruktor iznad, nego samo promijeniti vec kreiranog usera
User& User::setUser(const std::string& name,const std::string& surname,const std::string& unob,const std::string& username,const std::string& password,int day,int month,int year,int nobf)
{
  _date.setDate(year,month,day);
  _unob=unob;
  _nobf=nobf;
  _useracc.setUserAccount(username,password);
  (*this).setPerson(name,surname);
  
  return *this;
}

void User::borrowFilm(Film& film){ //posudjivanje filma
  if(film.getNumOfCopies()==0) cout<<"\033[1;31mFilm is not available!\033[0m"<<std::endl; //broj kopija==0, ispis greske
  else if(_nobf==3) cout << "\033[1;31mYou can borrow only 3 films. First return one of films.\033[0m" << std::endl; //broj posudjenih==3 ispis greske
  else{
  _nobf++; //povecaj broj posudjenih
  _borrowedFilms.push_back(film);
  _history.push_back(film);
  film.setNumOfCopies(film.getNumOfCopies()-1); //smanji broj kopija filma
  cout << "\033[1;31mYou have succesfully borrowed \033[0m"<< film.getTitle() << endl;
}
}

void User::returnFilm(Film& film){//vracanje filma
  if(isBorrowed(film)){ //provjerava da li je film uopste posudjen, ako nije ispisuje gresku
  _nobf--; //smanji broj posudjenih
  film.setNumOfCopies(film.getNumOfCopies()+1); //povecaj broj kopija filma
  _borrowedFilms.pop(film);
  std::cout << "\033[1;31mYou have successfully returned film.\033[0m" << std::endl;
}
  else std::cout << "\033[1;31mYou havent borrowed that film yet.\033[0m" << std::endl;
}

bool User::isBorrowed(const Film& film)const{ //provjerava da li je user posudio odredjeni film
  if(!_borrowedFilms.empty()){
  auto it=_borrowedFilms.begin();
  while(it!=_borrowedFilms.end())
  {
    if((*it).getInfo()==film) return true;
    it++;
  }}
  return false;
}

void User::printHistory()const{ //ispisuje historiju posudjivanja filmova
  
  if(!_history.empty()){
  std::cout<<"\033[1;34mHistory of borrowed films:\033[0m"<<std::endl;
  auto it=_history.begin();
  while(it!=_history.end())
  {
    (*it).getInfo().printFilm();
    it++;
  }}
  else{
    std::cout<<"\033[1;31mHistory of films is empty!\033[0m"<<std::endl;
  }
 }

void User::printBorrowedFilms()const{ //ispisuje trenutno posudjene filmove
  if(!_borrowedFilms.empty())
  {
  std::cout<<"\033[1;34mBorrowed films:\033[0m"<<std::endl;
  auto it=_borrowedFilms.begin();
  while(it!=_borrowedFilms.end())
  {
    (*it).getInfo().printFilm();
    it++;
  }}
  else
  {
    std::cout<<"\033[1;31mList of borrowed films is empty!\033[0m"<<std::endl;
  }
 }

bool User::operator==(const User& user){
  return _useracc.getUsername()==user._useracc.getUsername();
}

bool User::operator!=(const User& user){
  return _useracc.getUsername()!=user._useracc.getUsername();
}

