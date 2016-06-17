#include<iostream>
#include"administrator.h"
#include"listFilms.h"
#include"listUsers.h"
#include "readUsers.h"
#include "readFilms.h"
#include "options.h"
#include<unistd.h>

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
{ password=getpass("Enter Administrator Password: "); 
  while(password!=admin.getUserAcc().getPassword()){
  password=getpass("Username and password do not match.Enter Administrator Password: "); 
  }
  cout << admin.getName() << ", welcome to videostore Mind Games!" << endl;
  optionsAdmin(listF,listU,key,admin);
}
else
{ password=getpass("Enter user account Password: "); 
  User newuser=listU.findUserByUsername(username);
  while(newuser.getUserAcc().getPassword()!=password)
  {
     password=getpass("Username and password do not match.Enter user account Password: "); 
  }
  cout << newuser.getName() << ", welcome to videostore Mind Games!" << endl;
  optionsUser(listF,listU,listH,newuser,admin,key);
}
return 0;
}

