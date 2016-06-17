#include "listFilms.h"
#include<algorithm>

ListFilms& ListFilms::addFilm(Film& film)
{
  if(empty()){
    push_back(film);
  }

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

Film ListFilms::findFilm(const string& film,int key)const{
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
    else if(key!=-1)
    {
      auto p=foundFilms.begin();
      while(p!=foundFilms.end())
      {
       if((*p).getInfo().getKey()==key){ return (*p).getInfo();}
      p++;

      }

    }
    else
    {
      std::cout<<"Pronadjeno je "<<foundFilms.size()<< " filmova sa imenom "<< film<< std::endl;
      auto p=foundFilms.begin();
      while(p!=foundFilms.end())
      {
        (*p).getInfo().printInfo();
        p++;
      }

      std::cout<<"Ispisani su vam kljucevi odredjenih filmova, unesite kljuc filma koji zelite: ";
      std::cout<<std::endl;
      int kljuc;
      std::cin>>kljuc;
      auto k=foundFilms.begin();
      while(k!=foundFilms.end())
      {
       if((*k).getInfo().getKey()==kljuc){ return (*k).getInfo();}
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
  int year=update.getYear();
  int izbor;
  int a=1;
  while(a==1)
  {
  std::cout<< " ---- Opcije ---- " << std::endl;
  std::cout<< "1. Unesite 1 za promjenu naziva filma "<<std::endl;
  std::cout<< "2. Unesite 2 za promjenu opisa filma "<<std::endl;
  std::cout<< "3. Unesite 3 za promjenu liste rezisera filma "<<std::endl;
  std::cout<< "4. Unesite 4 za promjenu produkcijske kompanije filma "<<std::endl;
  std::cout<< "5. Unesite 5 za promjenu godine izdavanja filma "<< std::endl;
  std::cout<< "6. Unesite 6 za promjenu broja kopija filma "<<std::endl;
  std::cout<< "7. Unesite 7 za promjenu liste producenata filma "<<std::endl;
  std::cout<< "8. Unesite 8 za promjenu liste scenarista filma "<<std::endl;
  std::cout<< "9. Unesite 9 za promjenu liste glumaca filma "<<std::endl;

  std::cin >> izbor;
  if(izbor==1)
  {
    std::cout << "Unesite novi naziv filma: ";
    std::string naziv;
    std::cin >> naziv;
    update.setTitle(naziv);
  }
  //cin.ignore();
  else if(izbor==2)
  {
    std::cout << "Unesite novi opis filma: ";
    std::string opis;
    std::cin >> opis;
    update.setDescription(opis);
  }
  else if(izbor==3)
  {
    std::cout << "Unesite novo ime i prezime rezisera filma: ";
    std::string ime,prezime;
    std::cin >> ime >> prezime;
    update.setDirector(ime,prezime);
  }
  
  else if(izbor==4)
  {
    std::cout << "Unesite novu produkcijsku kompaniju filma: ";
    std::string kompanija;
    std::cin >> kompanija;
    update.setCompany(kompanija);
  }
  else if(izbor==5)
  {
    std::cout << "Unesite novu godinu izdavanja filma: ";
    int godina;
    std::cin >> godina;
    update.setYear(godina);
  }
  else if(izbor==6)
  {
    std::cout << "Unesite novi broj kopija filma: ";
    int broj_kopija;
    std::cin >> broj_kopija;
    update.setNumOfCopies(broj_kopija);
  }
  else if(izbor==7)
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
  else if(izbor==8)
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
  else if(izbor==9)
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
  else
  {
    std::cout<<" Unijeli se pogresan broj! "<<std::endl;
  }
  std::cout<<" Ukoliko zelite izvrsiti jos neke izmjene unesite 1,u suprotnom 0: "<<std::endl;
  int x;
  cin>>x;
  if(x!=1)
    a=0;
  }
  auto k=(*this).begin();
  while(k!=(*this).end())
      {
       if((*k).getInfo().getKey()==update.getKey()){ (*k).setInfo(update); break;}
       k++;

      }
      if(year!=update.getYear()) // ukoliko je bila azurirana godina izdavanja, u skladu sa tim se mora izvrsiti i ponovno sortiranje,odnosno pozicioniranje filma u odnosu na novu godinu
      {
      Film temp=update; 
      removeFilm(update.getTitle());
      addFilm(temp);
      }
}

void ListFilms::printAllInfo(const string& film)const{
  Film print=findFilm(film);
  print.printInfo();
 }
