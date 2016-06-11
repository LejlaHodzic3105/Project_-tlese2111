#include "listUsers.h"

ListUsers& ListUsers::addUser(User& user){
  if(!(findUserByUsernameBool(user.getUserAcc().getUsername())))
  {
  if(empty()){
    push_back(user);

  }
  else{
    ListUsers::const_iterator it=(*this).begin();
    while(it!=(*this).end()){
      int br=0;
      int day=(*it).getInfo().getDate().getDay();
      int month=(*it).getInfo().getDate().getMonth();
      int year=(*it).getInfo().getDate().getYear();


      if(user.getDate().getYear()>=year){
        br++;
        if(user.getDate().getMonth()>=month){
          br++;
          if(user.getDate().getDay()>=day){
            insert(it,user);
            br=0;
            return *this;
          }
        }
      }

      if(br>=1){
        insert(it,user);
        return *this;
      }
      ++it;
    }
    push_back(user);
  }}
  return *this;
}


void ListUsers::printListUsers()const{
    auto it=(*this).begin();
    while(it!=(*this).end()){
         std::cout<<(*it).getInfo();
              ++it;
                
    }

}

User& ListUsers::findUserByName(const std::string& name, const std::string& surname){
  auto it=(*this).begin();
  while(it!=(*this).end()){
        if((*it).getInfo().getName()==name && (*it).getInfo().getSurname()==surname) return (*it).getInfo();
	++it;
  }
  throw std::string("Korisnik nije pronadjen!");
}

User& ListUsers::findUserByUsername(const std::string& username){
   auto it=(*this).begin();
  while(it!=(*this).end()){
        if((*it).getInfo().getUserAcc().getUsername()==username) return (*it).getInfo();
	++it;
  }

  throw std::string("Korisnik nije pronadjen!");
}

bool ListUsers::findUserByUsernameBool(const std::string& username){
   auto it=(*this).begin();
  while(it!=(*this).end()){
        if((*it).getInfo().getUserAcc().getUsername()==username) return true;
	++it;
  }

  return false;
}

void ListUsers::removeUser(const std::string &s1, const std::string &s2){
  User remove;
  if(s2=="") remove=findUserByUsername(s1);
  else remove=findUserByName(s1,s2);
  pop(remove);
}

void ListUsers::updateUser(const std::string &s1,const std::string &s2)
{
  User update;
  if(s2=="") update=findUserByUsername(s1);
  else update=findUserByName(s1,s2);
  std::string choise;
  std::cout<<"Da li zelite promijeniti jedinstveni maticni broj? Upisite da ili ne: ";
  std::cin>>choise;
  if(choise=="da")
  {
    std::cout<<"Unesite novi JMBG: ";
    std::string unob;
    cin>>unob;
    update.setUnob(unob);

  }
  std::cout<<"Da li zelite promijeniti korisnicki racun? Upisite da ili ne: ";
  std::cin>>choise;
  if(choise=="da")
  {
    std::string username;
    std::string password;
    std::cout<<"Unesite novo korisnicko ime: "; // korisnicko ime  mora biti jedinstveno
    while(cin>>username)
    {
      if(findUserByUsernameBool(username))
      {
        std::cout<<"Unesite novi password; ";
        std::cin>>password;
        update.setAccount(username,password); 
        break;
      }
      else
        cout<<"Korisnicko ime je zauzeto,unesite novo: "<<std::endl;

    }
  }

}
