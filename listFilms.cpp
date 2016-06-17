#include "listFilms.h"

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

void ListFilms::printListFilmsByTitle(std::string t)const
{ if(empty()) std::cout << "There are no films available" << std::endl;
  else{auto it=(*this).begin();
  while(it!=(*this).end())
  {
    if((*it).getInfo().getTitle()==t) (*it).getInfo().printFilm();
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
    if(foundFilms.size()==0) throw std::string("Film not found!");
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
      std::cout<<"There are "<<foundFilms.size()<< " films with the title "<< film<< std::endl;
      auto p=foundFilms.begin();
      while(p!=foundFilms.end())
      {
        (*p).getInfo().printInfo();
        p++;
      }
      std::cout<<"Please enter the coresponding key: ";
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
  throw std::string("Film not found!");
 }	

void ListFilms::removeFilm(const string& film){
  try{ Film removeF=findFilm(film);
  pop(removeF);}
  catch(std::string a){ std::cout << a << std::endl;}
}



void ListFilms::updateFilm(const string& film){
  try{Film update=findFilm(film);
  int year=update.getYear();
  int izbor;
  int a=1;
  while(a==1)
  {
  std::cout<< " ---- Options ---- " << std::endl;
  std::cout<< "1. Enter 1 to change the title: "<<std::endl;
  std::cout<< "2. Enter 2 to change the description: "<<std::endl;
  std::cout<< "3. Enter 3 to change the director: "<<std::endl;
  std::cout<< "4. Enter 4 to change the production company: "<<std::endl;
  std::cout<< "5. Enter 5 to change year of release: "<< std::endl;
  std::cout<< "6. Enter 6 to change number of copies: "<<std::endl;
  std::cout<< "7. Enter 7 to change list of producers: "<<std::endl;
  std::cout<< "8. Enter 8 to change list of screenwriters: "<<std::endl;
  std::cout<< "9. Enter 9 to change list of actors: "<<std::endl;

  std::cin >> izbor;
  if(izbor==1)
  {
    std::cout << "Enter a new title: ";
    std::string naziv;
    std::cin >> naziv;
    update.setTitle(naziv);
  }
  //cin.ignore();
  else if(izbor==2)
  {
    std::cout << "Enter a new description: ";
    std::string opis;
    std::cin >> opis;
    update.setDescription(opis);
  }
  else if(izbor==3)
  {
    std::cout << "Enter the name and the surname od the director: ";
    std::string ime,prezime;
    std::cin >> ime >> prezime;
    update.setDirector(ime,prezime);
  }
  
  else if(izbor==4)
  {
    std::cout << "Enter the name of the production company: ";
    std::string kompanija;
    std::cin >> kompanija;
    update.setCompany(kompanija);
  }
  else if(izbor==5)
  {
    std::cout << "Enter the year of release: ";
    int godina;
    std::cin >> godina;
    update.setYear(godina);
  }
  else if(izbor==6)
  {
    std::cout << "Enter the number of copies: ";
    int broj_kopija;
    std::cin >> broj_kopija;
    update.setNumOfCopies(broj_kopija);
  }
  else if(izbor==7)
  { update.clearProducents();
    std::cout << "How many producers do you wish to enter: ";
    int broj;
    std::cin>>broj;
    for(int i=1;i<=broj;i++)
    {
      std::cout << "Enter the name and the surname of the "<< i << ". producer: ";
      std::string ime,prezime;
      std::cin >> ime >> prezime;
      update.setProducents(Person(ime,prezime));
    }
  }
  else if(izbor==8)
  { update.clearScenarists();
    std::cout << "How many screenwriters do you wish to enter: ";
    int broj;
    std::cin>>broj;
    for(int i=1;i<=broj;i++)
    {
      std::cout << "Enter the name and the surname of the "<< i << ". screenwriter: ";
      std::string ime,prezime;
      std::cin >> ime >> prezime;
      update.setScenarists(Person(ime,prezime));
    }
  }
  else if(izbor==9)
  { update.clearActors();
    std::cout << "How many actors do you wish to enter: ";
    int broj;
    std::cin>>broj;
    for(int i=1;i<=broj;i++)
    {
      std::cout << "Enter the name and the surname of the "<< i << ". actor: ";
      std::string ime,prezime;
      std::cin >> ime >> prezime;
      update.setActors(Person(ime,prezime));
    }
  }
  else
  {
    std::cout<<"Wrong input! "<<std::endl;
  }
  std::cout<<" If you want more changes enter 1, otherwise enter 0:: "<<std::endl;
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
      }}
  catch(std::string a){std::cout << a << std::endl;}
}

void ListFilms::printAllInfo(const string& film)const{
  try{Film print=findFilm(film);
  print.printInfo();}
  catch(std::string a){std::cout << a << std::endl;}
 }
