#include "film.h"


void Film::printAllInfo()const
{
  std::cout<<"Title: "<<_title<<std::endl;
  std::cout<<"Description: "<< _description<<std::endl;
  std::cout<<"Director: ";
  _director.printPerson();
  std::cout<<std::endl;
  std::cout<<"Production Company: "<<_productionCompany<<std::endl;
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

}
