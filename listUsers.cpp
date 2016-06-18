#include "listUsers.h"
#include "checkstring.h"

ListUsers& ListUsers::addUser(User& user){ //dodavanje usera, i sortiranje
  while(findUserByUsernameBool(user.getUserAcc().getUsername())) //provjerava je li username zauzet, ukoliko jeste, trazi unos novog
  {
    std::cout << "Username " << user.getUserAcc().getUsername() << " is already taken by another user. Please enter a different one: ";
    std::string username;
    getline(std::cin,username);
    while(check_string_for_spaces(username)) //provjerava da li username ima prazno mjesto
      {
	std::cout << "Username can't contain blank spaces. Please enter a new one: ";
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
      if(user.getDate().getYear()==year && user.getDate().getMonth()==month && user.getDate().getDay()<day){
        insertBack(it,user);
        return *this;
      }
       if(user.getDate().getYear()==year && user.getDate().getMonth()<month){
        insertBack(it,user);
        return *this;
      }



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
  catch(std::string a){std::cout << a << std::endl;}
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
  cout<<" --- Options --- "<< std::endl;
  cout<<"1. Enter 1 to change name and surname "<< std::endl;
  cout<<"2. Enter 2 to change unique number of birth "<< std::endl;
  cout<<"3. Enter 3 to change user account settings(username and password) "<<std::endl;
  
  std::cin>>choise;

  if(choise==1)
  {
   
    std::string name;
    std::string surname;
    std::cout<<"Enter a new name: ";
    std::cin>>name;
    std::cout<<"Enter a new surname: ";
    std::cin>>surname;
    update.setPerson(name,surname);


  }
  
  
  else if(choise==2)
  {
    std::cout<<"Enter a new unique number of birth: ";
    std::string unob;
    cin.ignore();
    getline(std::cin,unob);
    while(unob.size()!=13 || !check_string_all_digits(unob)) //provjerava validnost jmbg
    {   std::cout << "Unique number of birth must contain exactly 13 digits. Please enter it correctly: ";
	getline(std::cin,unob);
    }
    update.setUnob(unob);

  }

  else if(choise==3)
  {
    std::string username;
    std::string password;
    std::cout<<"Enter a new username: "; // korisnicko ime  mora biti jedinstveno
    cin.ignore();
    while(getline(std::cin,username))
    { 
      while(check_string_for_spaces(username))
      {
	std::cout << "Username can't contain blank spaces. Please enter a new one: "; //provjerava prazna mjesta u usernameu
	getline(std::cin,username);
      }
      if(!findUserByUsernameBool(username))
      {
        std::cout<<"Enter a new password: ";
        getline(std::cin,password);
	while(check_string_for_spaces(password))
        {
	  std::cout << "Password can't contain blank spaces. Please enter a new one: "; //provjerava prazna mjesta u passwordu
	  getline(std::cin,password);
        }
        update.setAccount(username,password); 
        break;
      }
      else
        std::cout<< "Username " << username << " is already taken by another user. Please enter a different one: ";

    }
  }
  else
  {
    cout<<"Wrong input!"<< std::endl;
  }
  std::cout<<"If you want more changes enter 1, otherwise enter 0: "<< std::endl; //nakon sto se izvrsi neka promjena, nudi novu promjenu ili izlaz iz 											    azuriranja
  int x;
  cin>>x;
  if(x!=1)
    a=0;
  }
  auto it=(*this).begin(); //azuriranje korisnika u listu korisnika
  while(it!=(*this).end()){
  if((*it).getInfo().getUserAcc().getUsername()==stariUsername){ (*it).setInfo(update); break;}
  ++it;
  }}
  catch(std::string a){std::cout << a << std::endl;}
}
