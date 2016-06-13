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
