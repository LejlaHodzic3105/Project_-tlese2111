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
  std::cout<<"Title: "<< _title<<std::endl;
  std::cout<<"Description: "<< _description<<std::endl;
  std::cout<<"Director: ";
  _director.printPerson();
  std::cout<<std::endl;
  std::cout<<"Production Company: "<< _productionCompany<<std::endl;
  std::cout<<"Producents: "<<std::endl;
  _listOfProducents.print();
  std::cout<<std::endl;
  std::cout<<"Actors: "<<std::endl;
  _listOfActors.print();
  std::cout<<std::endl;
  std::cout<<"Scenarists:"<<std::endl;
  _listOfScenarists.print();
  std::cout<<std::endl;
  std::cout<<"Year: "<<_year<<std::endl;
  std::cout<<"Number of copies: "<<_numOfCopies<<std::endl;
  std::cout<<"Unique key: "<<_key<<std::endl;

}
