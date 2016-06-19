#include "listUsers.h"
#include "checkstring.h"

ListUsers& ListUsers::addUser(User& user){ //dodavanje usera, i sortiranje
  while(findUserByUsernameBool(user.getUserAcc().getUsername())) //provjerava je li username zauzet, ukoliko jeste, trazi unos novog
  {
    std::cout << "\033[1;34mUsername " << user.getUserAcc().getUsername() << " is already taken by another user. Please enter a different one: \033[0m";
    std::string username;
    getline(std::cin,username);
    while(check_string_for_spaces(username)) //provjerava da li username ima prazno mjesto
    {
      std::cout << "\033[1;34mUsername can't contain blank spaces. Please enter a new one: \033[0m";
      getline(std::cin,username);
    }
    user.getUserAcc().setUsername(username);
  }
  if(empty()){
    push_back(user);

  }
  else{ //sortiranje
    ListUsers::const_iterator it=(*this).begin();
    while(it!=(*this).end()){
      int br=0;
      int day=(*it).getInfo().getDate().getDay();
      int month=(*it).getInfo().getDate().getMonth();
      int year=(*it).getInfo().getDate().getYear();
      int Uyear=user.getDate().getYear();
      int Umonth=user.getDate().getMonth();
      int Uday=user.getDate().getDay();

      int date=year*1000+month*100+day;
      int dateU=Uyear*1000+Umonth*100+Uday;

      if(dateU>=date)
      {
        insert(it,user);
        return *this;
      }

      ++it;
    }
    push_back(user);
  }
  return *this;
}


void ListUsers::printListUsers()const{ //ispisivanje liste korisnika
    if(!empty()){
    auto it=(*this).begin();
    while(it!=(*this).end()){
         std::cout<<(*it).getInfo();
              ++it;
                
    }}

}

User ListUsers::findUserByName(const std::string& name, const std::string& surname){ //trazenje korisnika po imenu
  if(!empty()){
  auto it=(*this).begin();
  while(it!=(*this).end()){
        if((*it).getInfo().getName()==name && (*it).getInfo().getSurname()==surname) return (*it).getInfo();
	++it;
  }}
  throw std::string("User not found!");
}

User ListUsers::findUserByUsername(const std::string& username){ //trazenje korisnika po usernameu
   if(!empty()){
   auto it=(*this).begin();
  while(it!=(*this).end()){
        if((*it).getInfo().getUserAcc().getUsername()==username) return (*it).getInfo();
	++it;
  }}

  throw std::string("User not found!");
}

bool ListUsers::findUserByUsernameBool(const std::string& username){ //trazenje korisnika po usernameu, ali vraca bool, a ne korisnika
  if(empty()) return false;
   auto it=(*this).begin();
  while(it!=(*this).end()){
        if((*it).getInfo().getUserAcc().getUsername()==username) return true;
	++it;
  }
  return false;
}

void ListUsers::removeUser(const std::string &s1, const std::string &s2){ //brisanje korisnika
  User remove;
  try{if(s2=="") remove=findUserByUsername(s1);
  else remove=findUserByName(s1,s2);
  pop(remove);}
  catch(std::string a){std::cout <<"\033[1;31m"<< a << "\033[0m" << std::endl;}
}

void ListUsers::updateUser(const std::string &s1,const std::string &s2) //azuriranje korisnika
{
  User update;
  try{if(s2=="") update=findUserByUsername(s1);
  else update=findUserByName(s1,s2);
  int choise;
  std::string stariUsername=update.getUserAcc().getUsername();
  int a=1;
  while(a==1)
  {
  cout<<"\033[1;34m--- Options --- "<< std::endl;
  cout<<"\033[1;34m1. Enter 1 to change name and surname "<< std::endl;
  cout<<"\033[1;34m2. Enter 2 to change unique number of birth "<< std::endl;
  cout<<"\033[1;34m3. Enter 3 to change user account settings(username and password) \033[0m"<<std::endl;
  
  choise=enter_int();

  if(choise==1)
  {
   
    std::string name;
    std::string surname;
    std::cout<<"\033[1;34mEnter a new name: \033[0m";
    std::cin>>name;
    std::cout<<"\033[1;34mEnter a new surname: \033[0m";
    std::cin>>surname;
    update.setPerson(name,surname);


  }
  
  
  else if(choise==2)
  {
    std::cout<<"\033[1;34mEnter a new unique number of birth: \033[0m";
    std::string unob;
    cin.ignore();
    getline(std::cin,unob);
    while(unob.size()!=13 || !check_string_all_digits(unob)) //provjerava validnost jmbg
    {   std::cout << "\033[1;34mUnique number of birth must contain exactly 13 digits. Please enter it correctly: \033[0m";
	getline(std::cin,unob);
    }
    update.setUnob(unob);

  }

  else if(choise==3)
  {
    std::string username;
    std::string password;
    std::cout<<"\033[1;34mEnter a new username: \033[0m"; // korisnicko ime  mora biti jedinstveno
    cin.ignore();
    while(getline(std::cin,username))
    { 
      while(check_string_for_spaces(username))
      {
	std::cout << "\033[1;34mUsername can't contain blank spaces. Please enter a new one: \033[0m"; //provjerava prazna mjesta u usernameu
	getline(std::cin,username);
      }
      if(!findUserByUsernameBool(username))
      {
        std::cout<<"\033[1;34mEnter a new password: \033[0m";
        getline(std::cin,password);
	while(check_string_for_spaces(password) || password.size()<6) //provjera da li password ima prazno mjesto i da li je kraci od 6 karaktera
        {
	  std::cout << "\033[1;34mPassword can't contain blank spaces and must have at least 6 characters. Please enter a new one: \033[0m";
	  getline(std::cin,password);
        }
        update.setAccount(username,password); 
        break;
      }
      else
        std::cout<< "\033[1;34mUsername " << username << " is already taken by another user. Please enter a different one: \033[0m";

    }
  }
  else
  {
    cout<<"\033[1;31mWrong input!\033[0m"<< std::endl;
  }
  std::cout<<"\033[1;34mIf you want more changes enter 1, otherwise enter 0: \033[0m"<< std::endl; //nakon sto se izvrsi neka promjena, nudi novu promjenu ili izlaz iz 											    azuriranja
  int x;
  x=enter_int();
  if(x!=1)
    a=0;
  }
  auto it=(*this).begin(); //azuriranje korisnika u listu korisnika
  while(it!=(*this).end()){
  if((*it).getInfo().getUserAcc().getUsername()==stariUsername){ (*it).setInfo(update); break;}
  ++it;
  }}
  catch(std::string a){std::cout <<"\033[1;31m"<< a << "\033[0m" << std::endl;}
}
