#include "listUsers.h"

ListUsers& ListUsers::addUser(User& user){
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
            auto p=insert(it,user);
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
  }
  return *this;
}


void ListUsers::printListUsers()const{
    auto it=(*this).begin();
    while(it!=(*this).end()){
         std::cout<<(*it).getInfo();
              ++it;
                
    }

}

