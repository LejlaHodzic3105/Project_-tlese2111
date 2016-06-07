#include "listFilms.h"


ListFilms& ListFilms::addFilm(Film& film)
{
  if(prazna())
    dodajNaKraj(film);

  else
  {
    for(int i=0;i<(*this).velicina();i++)
    {
      if(elementi[i].getYear()<film.getYear())
      {
        dodajNaLokaciju(i,film);
        return *this;
      }
      else
      {
        i++;
      }
    }
  }
dodajNaKraj(film);
  return *this;
}


void ListFilms::printListFilms()const
{
  for(int i=0;i<(*this).velicina();i++)
    elementi[i].printFilm();
}

Film& ListFilms::findFilm(const string& film)const{
  ListFilms foundFilms((*this).velicina()); //lista pronadjenih filmova moze maksimalno biti duga listi svih filmova
  for(int i=0;i<(*this).velicina();i++)
  {
    if(elementi[i].getTitle()==film) //ako se u listi filmova nadje film sa ciljanim imenom dodaj ga u listu pronadjenih filmova
    {
       foundFilms.dodajNaKraj(elementi[i]);
    }
  if(foundFilms.velicina()==0) std::cout << "Film sa trazenim imenom nije pronadjen!" << std::endl;
  else if(foundFilms.velicina()==1) return foundFilms.elementi[0];
  else{
    std::cout << "Pronadjeno je " << foundFilms.velicina() << " filmova sa imenom " << film << ". Molimo unesite jedinstveni kljuc za trazeni film iz liste ponudjenih kljuceva: ";
    for(int i=0;i<foundFilms.velicina();i++)
    {
      std::cout << foundFilms.elementi[i].getKey() << ' ';
    }
    std::cout << std::endl;
    int kljuc;
    std::cin >> kljuc;
    for(int i=0;i<foundFilms.velicina();i++)
    {
      if(foundFilms.elementi[i].getKey()==kljuc) return foundFilms.elementi[i];
    }
  }
}
}

void ListFilms::removeFilm(const string& film){
  Film remove=findFilm(film);
  ukloni(remove);
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
