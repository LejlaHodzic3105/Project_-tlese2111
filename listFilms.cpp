#include "listFilms.h"

ListFilms& ListFilms::addFilm(Film& film) //dodavanje filma i sortiranje filma pri dodavanju
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


void ListFilms::printListFilms()const //ispis liste filmova
{ if(empty()) std::cout << "\033[1;31mThere are no films available! \033[0m" << std::endl;
  else{auto it=(*this).begin();
  while(it!=(*this).end())
  {
    (*it).getInfo().printFilm();
    ++it;
  }}
}

void ListFilms::printListFilmsByTitle(std::string t)const //ispis svih filmova koji imaju proslijedjeni naziv
{ if(empty()) std::cout << "\033[1;31mThere are no films available! \033[0m" << std::endl;
  else{auto it=(*this).begin();
  bool exist=false;
  while(it!=(*this).end())
  {
    if((*it).getInfo().getTitle()==t) {(*it).getInfo().printFilm(); exist=true;}
    ++it;
  }
  if(exist==false) std::cout << "\033[1;31mThere are no films with that title! \033[0m" << std::endl;}
} 

Film ListFilms::findFilm(const string& film,int key)const{ //metod za trazenje filma po nazivu
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
    if(foundFilms.size()==0) throw std::string("Film not found!"); //ukoliko je lista pronadjenih filmova prazna, nema filma
    else if(foundFilms.size()==1) return foundFilms.front(); //ukoliko je nadjen jedan film sa zadanim nazivom, vratiti taj film
    else if(key!=-1) //ukoliko se za trazenje filma proslijedi i kljuc, koristi se kod popunjavanja liste historije filmova za korisnika
    {
      auto p=foundFilms.begin();
      while(p!=foundFilms.end())
      {
       if((*p).getInfo().getKey()==key){ return (*p).getInfo();}
      p++;

      }

    }
    else //ukoliko je nadjeno vise filmova sa istim nazivom, ponuditi korisniku listu filmova, i zatraziti unos kljuca
    {
      std::cout<<"\033[1;34mThere are "<<foundFilms.size()<< " films with the title "<<film<< std::endl;
      auto p=foundFilms.begin();
      while(p!=foundFilms.end())
      {
        (*p).getInfo().printInfo();
        p++;
      }
      std::cout<<"\033[1;34mPlease enter the coresponding key: \033[0m"<<std::endl;
      int kljuc;
      kljuc=enter_int();
      auto k=foundFilms.begin();
      while(k!=foundFilms.end())
      {
       if((*k).getInfo().getKey()==kljuc){ return (*k).getInfo();}
       k++;

      }

    }
  throw std::string("Film not found!");
 }	

void ListFilms::removeFilm(const string& film){ //brisanje filma, napravljen novi metod pop u lista.hxx
  try{ Film removeF=findFilm(film);
  pop(removeF);}
  catch(std::string a){ std::cout <<"\033[1;31m"<< a << "\033[0m" << std::endl;}
}



void ListFilms::updateFilm(const string& film){ //azuriranje filma
  try{Film update=findFilm(film);
  int year=update.getYear();
  int izbor;
  int a=1;
  while(a==1)
  {
  std::cout<< "\033[1;34m ---- Options ---- " << std::endl;
  std::cout<< "\033[1;34m1. Enter 1 to change the title: "<<std::endl;
  std::cout<< "\033[1;34m2. Enter 2 to change the description: "<<std::endl;
  std::cout<< "\033[1;34m3. Enter 3 to change the director: "<<std::endl;
  std::cout<< "\033[1;34m4. Enter 4 to change the production company: "<<std::endl;
  std::cout<< "\033[1;34m5. Enter 5 to change year of release: "<< std::endl;
  std::cout<< "\033[1;34m6. Enter 6 to change number of copies: "<<std::endl;
  std::cout<< "\033[1;34m7. Enter 7 to change list of producers: "<<std::endl;
  std::cout<< "\033[1;34m8. Enter 8 to change list of screenwriters: "<<std::endl;
  std::cout<< "\033[1;34m9. Enter 9 to change list of actors:\033[0m"<<std::endl;

  izbor=enter_int();
  if(izbor==1)
  {
    std::cout << "\033[1;34mEnter a new title: \033[0m";
    std::string naziv;
    std::cin >> naziv;
    update.setTitle(naziv);
  }
  else if(izbor==2)
  {
    std::cout << "\033[1;34mEnter a new description: \033[0m";
    std::string opis;
    std::cin >> opis;
    update.setDescription(opis);
  }
  else if(izbor==3)
  {
    std::cout << "\033[1;34mEnter the name and the surname od the director: \033[0m";
    std::string ime,prezime;
    std::cin >> ime >> prezime;
    update.setDirector(ime,prezime);
  }
  
  else if(izbor==4)
  {
    std::cout << "\033[1;34mEnter the name of the production company: \033[0m";
    std::string kompanija;
    std::cin >> kompanija;
    update.setCompany(kompanija);
  }
  else if(izbor==5)
  {
    std::cout << "\033[1;34mEnter the year of release: \033[0m";
    int godina;
    godina=enter_int();
    update.setYear(godina);
  }
  else if(izbor==6)
  {
    std::cout << "\033[1;34mEnter the number of copies: \033[0m";
    int broj_kopija;
    broj_kopija=enter_int();
    update.setNumOfCopies(broj_kopija);
  }
  else if(izbor==7)
  { update.clearProducents();
    std::cout << "\033[1;34mHow many producers do you wish to enter: \033[0m";
    int broj;
    broj=enter_int();
    for(int i=1;i<=broj;i++)
    {
      std::cout << "\033[1;34mEnter the name and the surname of the "<< i << ". producer: \033[0m";
      std::string ime,prezime;
      std::cin >> ime >> prezime;
      update.setProducents(Person(ime,prezime));
    }
  }
  else if(izbor==8)
  { update.clearScenarists();
    std::cout << "\033[1;34mHow many screenwriters do you wish to enter: \033[0m";
    int broj;
    broj=enter_int();
    for(int i=1;i<=broj;i++)
    {
      std::cout << "\033[1;34mEnter the name and the surname of the "<< i << ". screenwriter: \033[0m";
      std::string ime,prezime;
      std::cin >> ime >> prezime;
      update.setScenarists(Person(ime,prezime));
    }
  }
  else if(izbor==9)
  { update.clearActors();
    std::cout << "\033[1;34mHow many actors do you wish to enter: \033[0m";
    int broj;
    broj=enter_int();
    for(int i=1;i<=broj;i++)
    {
      std::cout << "\033[1;34mEnter the name and the surname of the "<< i << ". actor: \033[0m";
      std::string ime,prezime;
      std::cin >> ime >> prezime;
      update.setActors(Person(ime,prezime));
    }
  }
  else
  {
    std::cout<<"\033[1;31mWrong input! \033[0m"<<std::endl;
  }
  std::cout<<"\033[1;34mIf you want more changes enter 1, otherwise enter 0: \033[0m"<<std::endl; //nakon sto korisnik nesto izmijeni, ima opciju da mijenja dalje 											     ili napusti azuriranje
  int x;
  x=enter_int();
  if(x!=1)
    a=0;
  }
  auto k=(*this).begin();
  while(k!=(*this).end())
      {
       if((*k).getInfo().getKey()==update.getKey()){ (*k).setInfo(update); break;} //updatovanje filma u listu filmova
       k++;

      }
      if(year!=update.getYear()) // ukoliko je bila azurirana godina izdavanja, u skladu sa tim se mora izvrsiti i ponovno sortiranje,odnosno 					    pozicioniranje filma u odnosu na novu godinu
      {
      Film temp=update; 
      removeFilm(update.getTitle());
      addFilm(temp);
      }}
  catch(std::string a){std::cout <<"\033[1;31m"<< a << "\033[0m" << std::endl;}
}

void ListFilms::printAllInfo(const string& film)const{ //ispis svih detalja za trazeni film
  try{Film print=findFilm(film);
  print.printInfo();}
  catch(std::string a){std::cout <<"\033[1;31m"<< a << "\033[0m" << std::endl;}
 }

bool ListFilms::isBorrowed(const Film& film)const{ //provjerava u listi filmova da li je odredjeni film posudjen
  if(!empty()){
  auto it=(*this).begin();
  while(it!=(*this).end())
  {
    if((*it).getInfo()==film) return true;
    it++;
  }}
  return false;
}
