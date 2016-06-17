#include<iostream>
#include"administrator.h"
#include"listFilms.h"
#include"listUsers.h"
#include "readUsers.h"
#include "readFilms.h"
#include "options.h"

using namespace std;

int main(){
ListFilms listH;
ListUsers listU;
ListFilms listF;
Administrator admin;
readFilms("history.txt",listH);
readUsers("users.txt",listU,listH,admin);
int key=0;
key=readFilms("films.txt",listF);

string username,password;
cout << "Please enter your username: ";
getline(cin,username);
while(!listU.findUserByUsernameBool(username) && username!=admin.getUserAcc().getUsername())
  {
     cout << "User with username " << username << " doesn't exist. Please enter a new username: ";
     getline(cin,username);
  }
if(username==admin.getUserAcc().getUsername())
{ cout << "Please enter your password: ";
  getline(cin,password);
  while(password!=admin.getUserAcc().getPassword()){
  cout << "Username " << username << " and password " << password << " do not match. Please enter a new password: ";
  getline(cin,password);
  }
  cout << admin.getName() << ", welcome to videostore Mind Games!" << endl;
  optionsAdmin(listF,listU,key);
}
else
{ cout << "Please enter your password: ";
  getline(cin,password);
  User newuser=listU.findUserByUsername(username);
  while(newuser.getUserAcc().getPassword()!=password)
  {
     cout << "Username " << username << " and password " << password << " do not match. Please enter a new password: ";
     getline(cin,password);
  }
  cout << newuser.getName() << ", welcome to videostore Mind Games!" << endl;
  optionsUser(listF,listU,listH,newuser);
}
return 0;
}

