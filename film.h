#ifndef _FILM_H
#define _FILM_H

#include <iostream>
#include <string>
#include "person.h"
#include "lista.hxx"


class Film
{
  private:
   std::string _title;
   int _key;
   std::string _description;
   Person _director;
   std::string _productionCompany;
   list<Person> _listOfProducents;
   list<Person> _listOfScenarists;
   list<Person> _listOfActors;
   int _year;
   int _numOfCopies;

  public:
   Film():_year(0),_numOfCopies(0),_key(0){};
   ~Film()=default;
   const std::string getTitle()const {return _title;}
   const std::string getDescription()const {return _description;}
   const std::string getCompany()const {return _productionCompany;}
   int getYear() const {return _year;}
   int getNumOfCopies()const {return _numOfCopies;}
   const list<Person>& getProducents() const{return _listOfProducents;}
   const list<Person>& getScenarists() const{return _listOfScenarists;}
   const list<Person>& getActors() const{return _listOfActors;}
   const Person& getDirector() const{return _director;}
   int getKey() const{return _key;}
   void setTitle(const std::string& title){_title=title;}
   void setDescription(const std::string& description){_description=description;}
   void setCompany(const std::string& company){_productionCompany=company;}
   void setYear(int year){_year=year;}
   void setNumOfCopies(int num){_numOfCopies=num;}
   void setKey(int num){_key=num;}
   void setDirector(const std::string& name,const std::string& surname){_director.setPerson(name,surname);}
   void setProducents(Person&& producent){_listOfProducents.push_back(producent);}
   void setScenarists(Person&& scenarist){_listOfScenarists.push_back(scenarist);}
   void setActors(Person&& actor){_listOfActors.push_back(actor);}
   void printFilm()const{std::cout<<_title <<" "<< _year<<std::endl;} // pregled sadrzaja videoteke,svi filmovi sortirani po godini 
   bool operator==(const Film &film);
   bool operator!=(const Film &film);
   void clearProducents(){ _listOfProducents.clear();} //za azuriranje, kada zeli da promijeni producente, moramo prvo isprazniti listu postojecih producenata
   void clearScenarists(){ _listOfScenarists.clear();}
   void clearActors(){ _listOfActors.clear();}

  
};







#endif
