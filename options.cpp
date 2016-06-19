#include "options.h"
#include "writeFilms.h"
#include "writeUsers.h"

int br;
void optionsAdmin(ListFilms &listF,ListUsers &listU,int &key,Administrator &admin){ //funkcija za adminove opcije

while(true) //sve dok admin ne unese 14 (izlaz iz programa), nudi mu se izbor opcija
{
int choice;
cout<<"\033[1;32m--- Options --- \033[0m"<< std::endl;
std::cout << "\033[1;34m1. Enter 1 to review contents of the videostore" << std::endl;
std::cout << "2. Enter 2 to search the videostore by title" << std::endl;
std::cout << "3. Enter 3 to see all data for entered film title" << std::endl;
std::cout << "4. Enter 4 to add a new film to the videostore" << std::endl;
std::cout << "5. Enter 5 to remove a film from the videostore" << std::endl;
std::cout << "6. Enter 6 to update a film" << std::endl;
std::cout << "7. Enter 7 to review list of users" << std::endl;
std::cout << "8. Enter 8 to search for a user by his username or by his name and surname"<< std::endl;
std::cout << "9. Enter 9 to add a new user" << std::endl;
std::cout << "10. Enter 10 to remove a user" << std::endl;
std::cout << "11. Enter 11 to update a user" << std::endl;
std::cout << "12. Enter 12 to review currently borrowed films by a certain user" << std::endl;
std::cout << "13. Enter 13 to review history of borrowed films by a certain user" << std::endl;
std::cout << "14. Enter 14 to quit program\033[0m" << std::endl;

choice=enter_int();
if(choice==1){ //ispis sadrzaja videoteke
listF.printListFilms();
}

else if(choice==2){ //ispis svih filmova sa datim nazivom
std::cout << "\033[1;34mEnter the title of the film:\033[0m";
std::string t;
cin.ignore();
getline(cin,t);
std::cout << "\033[1;34mFilms with that title are:\033[0m" << std::endl;
listF.printListFilmsByTitle(t);
}

else if(choice==3){ //sve pojedinosti o nekom filmu
std::cout << "\033[1;34mEnter the title of the film:\033[0m";
std::string t;
cin.ignore();
getline(std::cin,t);
listF.printAllInfo(t);
}

else if(choice==4){ //dodavanje novog filma
++key;  //pri svakom novom dodavanju, unikatni kljuc se poveca i tako se sprijeci postojanje dva filma sa istim kljucem
Film newfilm;
std::string title,desc,dname,dsurname,comp;
std::cout << "\033[1;34mAdding a film:\033[0m" << std::endl;
std::cout << "\033[1;34mEnter the title of the film: \033[0m";
cin.ignore();
getline(std::cin,title);
newfilm.setTitle(title);
std::cout << "\033[1;34mEnter the description of the film: \033[0m";
getline(std::cin,desc);
newfilm.setDescription(desc);
std::cout << "\033[1;34mEnter the name of the director: \033[0m";
getline(std::cin,dname);
std::cout << "\033[1;34mEnter the surname of the director: \033[0m";
getline(std::cin,dsurname);
newfilm.setDirector(dname,dsurname);
std::cout << "\033[1;34mHow many producers do you wish to enter: \033[0m";
br=enter_int();
cin.ignore();
for(int i=1;i<=br;i++)
{
std::cout << "\033[1;34mEnter the name of the "<< i << ". producer: \033[0m";
std::string ime,prezime;
getline(std::cin,ime);
std::cout << "\033[1;34mEnter the surname of the "<< i << ". producer: \033[0m";
getline(std::cin,prezime);
newfilm.setProducents(Person(ime,prezime));
}
std::cout << "\033[1;34mHow many screenwriters do you wish to enter: \033[0m";
br=enter_int();
cin.ignore();
for(int i=1;i<=br;i++)
{
std::cout << "\033[1;34mEnter the name of the "<< i << ". screenwriter: \033[0m";
std::string ime,prezime;
getline(std::cin,ime);
std::cout << "\033[1;34mEnter the surname of the "<< i << ". screenwriter: \033[0m";
getline(std::cin,prezime);
newfilm.setScenarists(Person(ime,prezime));
}
std::cout << "\033[1;34mHow many actors do you wish to enter: \033[0m";
br=enter_int();
cin.ignore();
for(int i=1;i<=br;i++)
{
std::cout << "\033[1;34mEnter the name of the "<< i << ". actor: \033[0m";
std::string ime,prezime;
getline(std::cin,ime);
std::cout << "\033[1;34mEnter the surname of the "<< i << ". actor: \033[0m";
getline(std::cin,prezime);
newfilm.setActors(Person(ime,prezime));
}
std::cout << "\033[1;34mEnter the name of the production company: \033[0m";
cin.ignore();
getline(std::cin,comp);
newfilm.setCompany(comp);
std::cout << "\033[1;34mEnter the year of release: \033[0m";
br=enter_int();
newfilm.setYear(br);
std::cout << "\033[1;34mEnter the number of copies: \033[0m";
br=enter_int();
newfilm.setNumOfCopies(br);
newfilm.setKey(key); //postavljanje kljuca
listF.addFilm(newfilm); //nakon svih unosa, dodavanje filma u listu filmova
}

else if(choice==5){ //brisanje filma sa datim nazivom
std::cout << "\033[1;34mEnter the title of the film: \033[0m";
std::string t;
cin.ignore();
getline(std::cin,t);
listF.removeFilm(t);
}

else if(choice==6){ //azuriranje filma sa datim nazivom
std::cout << "\033[1;34mEnter the title of the film: \033[0m";
std::string t;
cin.ignore();
getline(std::cin,t);
listF.updateFilm(t);
}

else if(choice==7){ //pregled liste korisnika
std::cout << "\033[1;34mList of users:\033[0m" << std::endl;
listU.printListUsers();
}

else if(choice==8){ //pretraga korisnika
std::cout << "\033[1;34m1.If you want to search by username enter 1:\033[0m" << std::endl; //1.opcija trazenja po usernameu
std::cout << "\033[1;34m2.If you want to search by name and surname enter 2:\033[0m" << std::endl; //2.opcija trazenja po imenu i prezimenu
std::string s1,s2;
br=enter_int();
cin.ignore();
if(br==1){ std::cout << "\033[1;34mEnter username: \033[0m"; //opcija trazenja po usernameu
getline(std::cin,s1);
try{listU.findUserByUsername(s1).printUser();} //try catch blok, ukoliko nema tog usera, ispisuje gresku
catch(std::string a){std::cout <<"\033[1;31m"<< a << "\033[0m" << std::endl;}
}
else if(br==2){std::cout << "\033[1;34mEnter name:\033[0m"; //opcija trazenja po imenu i prezimenu
getline(std::cin,s1);
std::cout << "\033[1;34mEnter surname:\033[0m";
getline(std::cin,s2);
try{listU.findUserByName(s1,s2).printUser();} //try catch blok, ukoliko nema tog usera, ispisuje gresku
catch(std::string a){std::cout <<"\033[1;31m"<< a << "\033[0m" << std::endl;}
}
else std::cout << "\033[1;31mWrong input!\033[0m" << std::endl; //ukoliko ne unese niti 1 niti 2
}

else if(choice==9){ //dodavanje korisnika
std::cout << "\033[1;34mAdding a user:\033[0m" << std::endl;
std::cout << "\033[1;34mEnter the name of the user: \033[0m";
std::string name;
cin.ignore();
getline(std::cin,name);
std::cout << "\033[1;34mEnter the surname of the user: \033[0m";
std::string surname;
getline(std::cin,surname);
std::cout << "\033[1;34mEnter unique number of birth: \033[0m";
std::string unob;
getline(std::cin,unob);
std::cout << "\033[1;34mEnter username: \033[0m";
std::string uname;
getline(std::cin,uname);
std::cout << "\033[1;34mEnter password: \033[0m";
std::string upass;
getline(std::cin,upass);
User newuser=User(name,surname,unob,uname,upass); //koristi se konstruktor za kreiranje usera
listU.addUser(newuser); //dodavanje kreiranog usera u listu
}

else if(choice==10){ //brisanje usera
std::cout << "\033[1;34m1.Enter 1 if you want to remove the user by entering the username" << std::endl; //1.opcija trazenja po usernameu
std::cout << "\033[1;34m2.Enter 2 if you want to remove the user by entering the name and the surname\033[0m" << std::endl; //2.opcija trazenja po imenu i prezimenu
std::string s1,s2;
br=enter_int();
if(br==1){
cout << "\033[1;34mEnter username: \033[0m";
cin.ignore();
getline(cin,s1);
listU.removeUser(s1); //ista funkcija se koristi za brisanje usera po usernameu te za brisanje usera po imenu i prezimenu.Ta funkcija ima drugi 			parametar koji je po defaultu prazan string
                      //ukoliko taj string ostane prazan znaci da je brisanje po usernameu, u suprotnom znaci da je brisanje po imenu i prezimenu
}
else if(br==2){
cin.ignore();
std::cout << "\033[1;34mEnter name:\033[0m"; //opcija trazenja po imenu i prezimenu
getline(std::cin,s1);
std::cout << "\033[1;34mEnter surname:\033[0m";
getline(std::cin,s2);
listU.removeUser(s1,s2);
}
}

else if(choice==11){ //azuriranje korisnika
std::cout << "\033[1;34m1.Enter 1 if you want to update the user by entering the username" << std::endl;
std::cout << "\033[1;34m2.Enter 2 if you want to update the user by entering the name and the surname\033[0m" << std::endl;
std::string s1,s2;
br=enter_int();
if(br==1){
cout << "\033[1;34mEnter username: \033[0m";
cin.ignore();
getline(cin,s1);
listU.updateUser(s1); //ista funkcija se koristi za azuriranje usera po usernameu te za azuriranje usera po imenu i prezimenu.Ta funkcija ima drugi 				parametar koji je po defaultu prazan string
                      //ukoliko taj string ostane prazan znaci da je brisanje po usernameu, u suprotnom znaci da je brisanje po imenu i prezimenu
}
else if(br==2){
cin.ignore();
std::cout << "\033[1;34mEnter name:\033[0m"; //opcija trazenja po imenu i prezimenu
getline(std::cin,s1);
std::cout << "\033[1;34mEnter surname:\033[0m";
getline(std::cin,s2);
listU.updateUser(s1,s2);
}
}

else if(choice==12){ //pregled posudjenih filmova za odredjenog usera
std::cout << "\033[1;34m1.Enter 1 if you want to review the user's borrowed films by entering the username" << std::endl;
std::cout << "\033[1;34m2.Enter 2 if you want to review the user's borrowed films by entering the name and the surname\033[0m" << std::endl;
std::string s1,s2;
br=enter_int();
if(br==1){
cout << "\033[1;34mEnter username: \033[0m";
cin.ignore();
getline(cin,s1);
try{listU.findUserByUsername(s1).printBorrowedFilms();}
catch(std::string a){std::cout <<"\033[1;31m"<< a << "\033[0m" << std::endl;}
}
else if(br==2){
cin.ignore();
std::cout << "\033[1;34mEnter name:\033[0m"; //opcija trazenja po imenu i prezimenu
getline(std::cin,s1);
std::cout << "\033[1;34mEnter surname:\033[0m";
getline(std::cin,s2);
try{listU.findUserByName(s1,s2).printBorrowedFilms();}
catch(string a){std::cout <<"\033[1;31m"<< a << "\033[0m" << std::endl;}
}
}

else if(choice==13){ //pregled historije posudjivanja za odredjenog usera
std::cout << "\033[1;34m1.Enter 1 if you want to review the user's history of borrowed films by entering the username" << std::endl;
std::cout << "\033[1;34m2.Enter 2 if you want to review the user's history of borrowed films by entering the name and the surname\033[0m" << std::endl;
std::string s1,s2;
br=enter_int();
if(br==1){
cout << "\033[1;34mEnter username: \033[0m";
cin.ignore();
getline(cin,s1);
try{listU.findUserByUsername(s1).printHistory();}
catch(std::string a){std::cout <<"\033[1;31m"<< a << "\033[0m" << std::endl;}
}
else if(br==2){
cin.ignore();
std::cout << "\033[1;34mEnter name:\033[0m"; //opcija trazenja po imenu i prezimenu
getline(std::cin,s1);
std::cout << "\033[1;34mEnter surname:\033[0m";
getline(std::cin,s2);
try{listU.findUserByName(s1,s2).printHistory();}
catch(std::string a){std::cout <<"\033[1;31m"<< a << "\033[0m" << std::endl;}
}
}

else if(choice==14){ //izlaz iz programa, te spremanje u fileove
writeInFile(listF,"films.txt",key,1);
writeUsers(listU,"users.txt",admin);
return;
}
else std::cout << "\033[1;31mWrong input!\033[0m" << std::endl; //ukoliko admin ne unese broj izmedju 1 i 14

}
}

void optionsUser(ListFilms &listF,ListUsers &listU,ListFilms &listH,User& newuser,Administrator &admin,int key){ //opcije za usera
int choice;

while(true)
{
cout<<"\033[1;32m--- Options --- \033[0m"<< std::endl;
std::cout << "\033[1;34m1. Enter 1 to review contents of the videostore" << std::endl;
std::cout << "2. Enter 2 to search the videostore by title" << std::endl;
std::cout << "3. Enter 3 to see all data for entered film title" << std::endl;
std::cout << "4. Enter 4 to borrow a film" << std::endl;
std::cout << "5. Enter 5 to return a film" << std::endl;
std::cout << "6. Enter 6 to review your history of borrowed films" << std::endl;
std::cout << "7. Enter 7 to review your currently borrowed films" << std::endl;
std::cout << "8. Enter 8 to quit program\033[0m" << std::endl;

choice=enter_int();

if(choice==1){ //ispis sadrzaja videoteke
listF.printListFilms();
}

else if(choice==2){ //ispis svih filmova sa datim nazivom
std::cout << "\033[1;34mEnter the title of the film:\033[0m";
std::string t;
cin.ignore();
getline(cin,t);
std::cout << "\033[1;34mFilms with that title are:\033[0m" << std::endl;
listF.printListFilmsByTitle(t);
}

else if(choice==3){ //ispis svih pojedinosti za trazeni film
std::cout << "\033[1;34mEnter the title of the film:\033[0m";
std::string t;
cin.ignore();
getline(std::cin,t);
listF.printAllInfo(t);
}

else if(choice==4){ //posudjivanje filma
std::cout << "\033[1;34mEnter the title of the film:\033[0m";
std::string t;
cin.ignore();
getline(std::cin,t);
try{
Film b=listF.findFilm(t); 
newuser.borrowFilm(b);
auto it=listU.begin();
while(it!=listU.end()){
if((*it).getInfo()==newuser){ (*it).setInfo(newuser); break;}
++it;
}
auto k=listF.begin();
while(k!=listF.end())
{
if((*k).getInfo()==b){ (*k).setInfo(b); break;}
k++;
}
if(!listH.isBorrowed(b)) listH.addFilm(b);
}
catch(std::string a){std::cout <<"\033[1;31m"<< a << "\033[0m" << std::endl;}
}

else if(choice==5){ //vracanje filma
std::cout << "\033[1;34mEnter the title of the film:\033[0m";
std::string t;
cin.ignore();
getline(std::cin,t);
try{
Film b=listF.findFilm(t); 
newuser.returnFilm(b);
auto it=listU.begin();
while(it!=listU.end()){
if((*it).getInfo()==newuser){ (*it).setInfo(newuser); break;}
++it;
}
auto k=listF.begin();
while(k!=listF.end())
{
if((*k).getInfo()==b){ (*k).setInfo(b); break;}
k++;

}
}
catch(std::string a){std::cout <<"\033[1;31m"<< a << "\033[0m" << std::endl;}
}

else if(choice==6){ //ispis svoje historije
newuser.printHistory();
}

else if(choice==7){ //ispis posudjenih filmova
newuser.printBorrowedFilms();
}
else if(choice==8){ //izlaz iz programa i spremanje u fileove
writeUsers(listU,"users.txt",admin);
writeInFile(listF,"films.txt",key,1);
writeInFile(listH,"history.txt",key);
return;
}
else std::cout << "\033[1;31mWrong input!\033[0m" << std::endl;
}

}
