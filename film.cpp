#include "film.h"

bool Film::operator==(const Film &film){
  if(_key==film._key) return true;
  else return false;
}

bool Film::operator!=(const Film& film)
{
  if(_key==film._key) return false;
  else return true;
}

Film& Film::operator=(const Film &other){
  if(this!=&other)
{
  setTitle(other.getTitle());
  setKey(other.getKey());
  setDescription(other.getDescription());
  setDirector(other.getDirector().getName(),other.getDirector().getSurname());
  setCompany(other.getCompany());
  _listOfProducents=other.getProducents();
  _listOfScenarists=other.getScenarists();
  _listOfActors=other.getActors();
  setYear(other.getYear());
  setNumOfCopies(other.getNumOfCopies());
}
  return *this;
}

Film& Film::operator=(Film &&other){
  setTitle(other.getTitle());
  setKey(other.getKey());
  setDescription(other.getDescription());
  setDirector(other.getDirector().getName(),other.getDirector().getSurname());
  setCompany(other.getCompany());
  _listOfProducents=other.getProducents();
  _listOfScenarists=other.getScenarists();
  _listOfActors=other.getActors();
  setYear(other.getYear());
  setNumOfCopies(other.getNumOfCopies());
  return *this;
}

Film::Film(const Film &other){
if(this!=&other)
{
  setTitle(other.getTitle());
  setKey(other.getKey());
  setDescription(other.getDescription());
  setDirector(other.getDirector().getName(),other.getDirector().getSurname());
  setCompany(other.getCompany());
  _listOfProducents=other.getProducents();
  _listOfScenarists=other.getScenarists();
  _listOfActors=other.getActors();
  setYear(other.getYear());
  setNumOfCopies(other.getNumOfCopies());
}
}

Film::Film(Film &&other){
  setTitle(other.getTitle());
  setKey(other.getKey());
  setDescription(other.getDescription());
  setDirector(other.getDirector().getName(),other.getDirector().getSurname());
  setCompany(other.getCompany());
  _listOfProducents=other.getProducents();
  _listOfScenarists=other.getScenarists();
  _listOfActors=other.getActors();
  setYear(other.getYear());
  setNumOfCopies(other.getNumOfCopies());

}

void Film::setFilm(const std::string title,int year,const std::string nameD,const std::string surnameD,const std::string prodC,int key,int num)
{
  _title=title;
  _year=year;
  (*this).setDirector(nameD,surnameD);
  _productionCompany=prodC;
  _key=key;
  _numOfCopies=num;
}

void Film::printInfo() const
{
  std::cout<<"\033[1;34mTitle: \033[0m"<< _title<<std::endl;
  std::cout<<"\033[1;34mDescription: \033[0m"<< _description<<std::endl;
  std::cout<<"\033[1;34mDirector: \033[0m";
  _director.printPerson();
  std::cout<<std::endl;
  std::cout<<"\033[1;34mProduction company: \033[0m"<< _productionCompany<<std::endl;
  std::cout<<"\033[1;34mProducents: \033[0m"<<std::endl;
  _listOfProducents.print();
  std::cout<<std::endl;
  std::cout<<"\033[1;34mActors: \033[0m"<<std::endl;
  _listOfActors.print();
  std::cout<<std::endl;
  std::cout<<"\033[1;34mScreenwriters: \033[0m"<<std::endl;
  _listOfScenarists.print();
  std::cout<<std::endl;
  std::cout<<"\033[1;34mYear of release: \033[0m"<<_year<<std::endl;
  std::cout<<"\033[1;34mNumber of copies: \033[0m"<<_numOfCopies<<std::endl;
  std::cout<<"\033[1;34mUnique key: \033[0m"<<_key<<std::endl;

}
