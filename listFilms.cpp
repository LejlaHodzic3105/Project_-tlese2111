#include "listFilms.h"
#include<algorithm>

ListFilms& ListFilms::addFilm(Film& film)
{
  if(empty())
    push_back(film);

  else
  {
    ListFilms::const_iterator it=(*this).begin();
    while(it!=(*this).end()){
        if((*it).getInfo().getYear()<film.getYear())
        {
          insert(it,film);
          return *this;
        }
        it++;
    }
    
push_back(film);
  }
  return *this;
}


void ListFilms::printListFilms()const
{ if(empty()) std::cout << "There are no films available" << std::endl;
  else{auto it=(*this).begin();
  while(it!=(*this).end())
  {
    (*it).getInfo().printFilm();
    ++it;
  }}
}

Film& ListFilms::findFilm(const string& film)const{
  ListFilms foundFilms; //lista pronadjenih filmova moze maksimalno biti duga listi svih filmova
  auto it=(*this).begin();
  while(it!=(*this).end())
  {
    if((*it).getInfo().getTitle()==film)//ako se u listi filmova nadje film sa ciljanim imenom dodaj ga u listu pronadjenih filmova
    {
      foundFilms.push_back((*it).getInfo());
    }
  it++;
  }
    if(foundFilms.size()==0) std::cout<<"Film sa trazenim imenom nije pronadjen!"<<std::endl;
    else if(foundFilms.size()==1) return foundFilms.front();
    else
    {
      std::cout<<"Pronadjeno je "<<foundFilms.size()<< " filmova sa imenom "<< film<< ". Molimo unseite jedinstveni kljuc za trazeni film iz liste pronadjenih kljuceva: ";
      auto p=foundFilms.begin();
      while(p!=foundFilms.end())
      {
        std::cout<< (*p).getInfo().getKey()<< ' ';
        p++;
      }
      std::cout<<std::endl;
      int kljuc;
      std::cin>>kljuc;
      auto k=foundFilms.begin();
      while(k!=foundFilms.end())
      {
       if((*k).getInfo().getKey()==kljuc) return (*k).getInfo();
       k++;

      }

    }
  throw std::string("Film nije pronadjen!");
 }	

void ListFilms::removeFilm(const string& film){
  Film removeF=findFilm(film);
  pop(removeF);
}

void ListFilms::updateFilm(const string& film){
  Film update=findFilm(film);
  std::string izbor;
  std::cout << "Da li zelite da promijenite naziv filma. Upisite da ili ne: ";
  std::cin >> izbor;
  if(izbor=="da")
  {
    std::cout << "Unesite novi naziv filma: ";
    std::string naziv;
    std::cin >> naziv;
    update.setTitle(naziv);
  }
  std::cout << "Da li zelite da promijenite opis filma. Upisite da ili ne: ";
  std::cin >> izbor;
  if(izbor=="da")
  {
    std::cout << "Unesite novi opis filma: ";
    std::string opis;
    std::cin >> opis;
    update.setDescription(opis);
  }
  std::cout << "Da li zelite da promijenite rezisera filma. Upisite da ili ne: ";
  std::cin >> izbor;
  if(izbor=="da")
  {
    std::cout << "Unesite novo ime i prezime rezisera filma: ";
    std::string ime,prezime;
    std::cin >> ime >> prezime;
    update.setDirector(ime,prezime);
  }
  std::cout << "Da li zelite da promijenite produkcijsku kompaniju filma. Upisite da ili ne: ";
  std::cin >> izbor;
  if(izbor=="da")
  {
    std::cout << "Unesite novu produkcijsku kompaniju filma: ";
    std::string kompanija;
    std::cin >> kompanija;
    update.setCompany(kompanija);
  }
  std::cout << "Da li zelite da promijenite godinu izdavanja filma. Upisite da ili ne: ";
  std::cin >> izbor;
  if(izbor=="da")
  {
    std::cout << "Unesite novu godinu izdavanja filma: ";
    int godina;
    std::cin >> godina;
    update.setYear(godina);
  }
  std::cout << "Da li zelite da promijenite broj kopija filma. Upisite da ili ne: ";
  std::cin >> izbor;
  if(izbor=="da")
  {
    std::cout << "Unesite novi broj kopija filma: ";
    int broj_kopija;
    std::cin >> broj_kopija;
    update.setNumOfCopies(broj_kopija);
  }
  std::cout << "Da li zelite da promijenite listu producenata filma. Upisite da ili ne: ";
  std::cin >> izbor;
  if(izbor=="da")
  { update.clearProducents();
    std::cout << "Koliko producenata cete unijeti: ";
    int broj;
    std::cin>>broj;
    for(int i=1;i<=broj;i++)
    {
      std::cout << "Unesite ime i prezime "<< i << ". producenta: ";
      std::string ime,prezime;
      std::cin >> ime >> prezime;
      update.setProducents(Person(ime,prezime));
    }
  }
  std::cout << "Da li zelite da promijenite listu scenarista filma. Upisite da ili ne: ";
  std::cin >> izbor;
  if(izbor=="da")
  { update.clearScenarists();
    std::cout << "Koliko scenarista cete unijeti: ";
    int broj;
    std::cin>>broj;
    for(int i=1;i<=broj;i++)
    {
      std::cout << "Unesite ime i prezime "<< i << ". scenariste: ";
      std::string ime,prezime;
      std::cin >> ime >> prezime;
      update.setScenarists(Person(ime,prezime));
    }
  }
  std::cout << "Da li zelite da promijenite listu glumaca filma. Upisite da ili ne: ";
  std::cin >> izbor;
  if(izbor=="da")
  { update.clearActors();
    std::cout << "Koliko glumaca cete unijeti: ";
    int broj;
    std::cin>>broj;
    for(int i=1;i<=broj;i++)
    {
      std::cout << "Unesite ime i prezime "<< i << ". glumca: ";
      std::string ime,prezime;
      std::cin >> ime >> prezime;
      update.setActors(Person(ime,prezime));
    }
  }
}

void ListFilms::printAllInfo(const string& film)const{
  Film print=findFilm(film);
  std::cout<<"Title: "<< print.getTitle()<<std::endl;
  std::cout<<"Description: "<< print.getDescription()<<std::endl;
  std::cout<<"Director: ";
  print.getDirector().printPerson();
  std::cout<<std::endl;
  std::cout<<"Production Company: "<< print.getCompany()<<std::endl;
  std::cout<<"Producents: "<<std::endl;
  print.getProducents().print();
  std::cout<<std::endl;
  std::cout<<"Actors: "<<std::endl;
  print.getActors().print();
  std::cout<<std::endl;
  std::cout<<"Scenarists:"<<std::endl;
  print.getScenarists().print();
  std::cout<<std::endl;
  std::cout<<"Year: "<<print.getYear()<<std::endl;
  std::cout<<"Number of copies: "<<print.getNumOfCopies()<<std::endl;
  std::cout<<"Unique key: "<<print.getKey()<<std::endl;
}
