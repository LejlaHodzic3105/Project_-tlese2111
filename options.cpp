#include "options.h"
#include "writeFilms.h"
#include "writeUsers.h"

void optionsAdmin(ListFilms &listF,ListUsers &listU,int &key,Administrator &admin){ //funkcija za adminove opcije
int choice;

while(true) //sve dok admin ne unese 14 (izlaz iz programa), nudi mu se izbor opcija
{

std::cout << "1. Enter 1 to review contents of the videostore" << std::endl;
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
std::cout << "14. Enter 14 to quit program" << std::endl;

std::cin >> choice;

if(choice==1){ //ispis sadrzaja videoteke
listF.printListFilms();
}

else if(choice==2){ //ispis svih filmova sa datim nazivom
std::cout << "Enter the title of the film:";
std::string t;
cin.ignore();
getline(cin,t);
std::cout << "Films with that title are:" << std::endl;
listF.printListFilmsByTitle(t);
}

else if(choice==3){ //sve pojedinosti o nekom filmu
std::cout << "Enter the title of the film:";
std::string t;
cin.ignore();
getline(std::cin,t);
listF.printAllInfo(t);
}

else if(choice==4){ //dodavanje novog filma
++key;  //pri svakom novom dodavanju, unikatni kljuc se poveca i tako se sprijeci postojanje dva filma sa istim kljucem
Film newfilm;
std::string title,desc,dname,dsurname,comp;
std::cout << "Adding a film:" << std::endl;
std::cout << "Enter the title of the film: ";
cin.ignore();
getline(std::cin,title);
newfilm.setTitle(title);
std::cout << "Enter the description of the film: ";
getline(std::cin,desc);
newfilm.setDescription(desc);
std::cout << "Enter the name of the director: ";
getline(std::cin,dname);
std::cout << "Enter the surname of the director: ";
getline(std::cin,dsurname);
newfilm.setDirector(dname,dsurname);
std::cout << "How many producers do you wish to enter: ";
int broj;
std::cin>>broj;
for(int i=1;i<=broj;i++)
{
std::cout << "Enter the name and the surname of the "<< i << ". producer: ";
std::string ime,prezime;
std::cin >> ime >> prezime;
newfilm.setProducents(Person(ime,prezime));
}
std::cout << "How many screenwriters do you wish to enter: ";
std::cin>>broj;
for(int i=1;i<=broj;i++)
{
std::cout << "Enter the name and the surname of the "<< i << ". screenwriter: ";
std::string ime,prezime;
std::cin >> ime >> prezime;
newfilm.setScenarists(Person(ime,prezime));
}
std::cout << "How many actors do you wish to enter: ";
std::cin>>broj;
for(int i=1;i<=broj;i++)
{
std::cout << "Enter the name and the surname of the "<< i << ". actor: ";
std::string ime,prezime;
std::cin >> ime >> prezime;
newfilm.setActors(Person(ime,prezime));
}
std::cout << "Enter the name of the production company: ";
cin.ignore();
getline(std::cin,comp);
newfilm.setCompany(comp);
std::cout << "Enter the year of release: ";
int year;
cin>>year;
newfilm.setYear(year);
std::cout << "Enter the number of copies: ";
int noc;
cin>>noc;
newfilm.setNumOfCopies(noc);
newfilm.setKey(key); //postavljanje kljuca
listF.addFilm(newfilm); //nakon svih unosa, dodavanje filma u listu filmova
}

else if(choice==5){ //brisanje filma sa datim nazivom
std::cout << "Enter the title of the film: ";
std::string t;
cin.ignore();
getline(std::cin,t);
listF.removeFilm(t);
}

else if(choice==6){ //azuriranje filma sa datim nazivom
std::cout << "Enter the title of the film: ";
std::string t;
cin.ignore();
getline(std::cin,t);
listF.updateFilm(t);
}

else if(choice==7){ //pregled liste korisnika
std::cout << "List of users:" << std::endl;
listU.printListUsers();
}

else if(choice==8){ //pretraga korisnika
std::cout << "1.If you want to search by username enter 1:" << std::endl; //1.opcija trazenja po usernameu
std::cout << "2.If you want to search by name and surname enter 2:" << std::endl; //2.opcija trazenja po imenu i prezimenu
std::string s1,s2;
int c;
cin >> c;
if(c==1){ std::cout << "Enter username: "; //opcija trazenja po usernameu
cin.ignore();
getline(std::cin,s1);
try{listU.findUserByUsername(s1).printUser();} //try catch blok, ukoliko nema tog usera, ispisuje gresku
catch(std::string a){std::cout << a << std::endl;}
}
else if(c==2){std::cout << "Enter name and surname:"; //opcija trazenja po imenu i prezimenu
std::cin >> s1 >> s2;
try{listU.findUserByName(s1,s2).printUser();} //try catch blok, ukoliko nema tog usera, ispisuje gresku
catch(std::string a){std::cout << a << std::endl;}
}
else std::cout << "Wrong input!" << std::endl; //ukoliko ne unese niti 1 niti 2
}

else if(choice==9){ //dodavanje korisnika
std::cout << "Adding a user:" << std::endl;
std::cout << "Enter the name of the user: ";
std::string name;
cin.ignore();
getline(std::cin,name);
std::cout << "Enter the surname of the user: ";
std::string surname;
getline(std::cin,surname);
std::cout << "Enter unique number of birth: ";
std::string unob;
getline(std::cin,unob);
std::cout << "Enter username: ";
std::string uname;
getline(std::cin,uname);
std::cout << "Enter password: ";
std::string upass;
getline(std::cin,upass);
User newuser=User(name,surname,unob,uname,upass); //koristi se konstruktor za kreiranje usera
listU.addUser(newuser); //dodavanje kreiranog usera u listu
}

else if(choice==10){ //brisanje usera
std::cout << "1.Enter 1 if you want to remove the user by entering the username" << std::endl; //1.opcija trazenja po usernameu
std::cout << "2.Enter 2 if you want to remove the user by entering the name and the surname" << std::endl; //2.opcija trazenja po imenu i prezimenu
std::string s1,s2;
int iz;
cin >> iz;
if(iz==1){
cout << "Enter username: ";
cin.ignore();
getline(cin,s1);
listU.removeUser(s1); //ista funkcija se koristi za brisanje usera po usernameu te za brisanje usera po imenu i prezimenu.Ta funkcija ima drugi 			parametar koji je po defaultu prazan string
                      //ukoliko taj string ostane prazan znaci da je brisanje po usernameu, u suprotnom znaci da je brisanje po imenu i prezimenu
}
else if(iz==2){
cout << "Enter the name and the surname: ";
cin >> s1 >> s2;
listU.removeUser(s1,s2);
}
}

else if(choice==11){ //azuriranje korisnika
std::cout << "1.Enter 1 if you want to update the user by entering the username" << std::endl;
std::cout << "2.Enter 2 if you want to update the user by entering the name and the surname" << std::endl;
std::string s1,s2;
int iz;
cin >> iz;
if(iz==1){
cout << "Enter username: ";
cin.ignore();
getline(cin,s1);
listU.updateUser(s1); //ista funkcija se koristi za azuriranje usera po usernameu te za azuriranje usera po imenu i prezimenu.Ta funkcija ima drugi 				parametar koji je po defaultu prazan string
                      //ukoliko taj string ostane prazan znaci da je brisanje po usernameu, u suprotnom znaci da je brisanje po imenu i prezimenu
}
else if(iz==2){
cout << "Enter the name and the surname: ";
cin >> s1 >> s2;
listU.updateUser(s1,s2);
}
}

else if(choice==12){ //pregled posudjenih filmova za odredjenog usera
std::cout << "1.Enter 1 if you want to review the user's borrowed films by entering the username" << std::endl;
std::cout << "2.Enter 2 if you want to review the user's borrowed films by entering the name and the surname" << std::endl;
std::string s1,s2;
int iz;
cin >> iz;
if(iz==1){
cout << "Enter username: ";
cin.ignore();
getline(cin,s1);
try{listU.findUserByUsername(s1).printBorrowedFilms();}
catch(std::string a){std::cout << a<<std::endl;}
}
else if(iz==2){
cout << "Enter the name and the surname: ";
cin >> s1 >> s2;
try{listU.findUserByName(s1,s2).printBorrowedFilms();}
catch(string a){std::cout << a << std::endl;}
}
}

else if(choice==13){ //pregled historije posudjivanja za odredjenog usera
std::cout << "1.Enter 1 if you want to review the user's history of borrowed films by entering the username" << std::endl;
std::cout << "2.Enter 2 if you want to review the user's history of borrowed films by entering the name and the surname" << std::endl;
std::string s1,s2;
int iz;
cin >> iz;
if(iz==1){
cout << "Enter username: ";
cin.ignore();
getline(cin,s1);
try{listU.findUserByUsername(s1).printHistory();}
catch(std::string a){std::cout << a << std::endl;}
}
else if(iz==2){
cout << "Enter the name and the surname: ";
cin >> s1 >> s2;
try{listU.findUserByName(s1,s2).printHistory();}
catch(std::string a){std::cout << a << std::endl;}
}
}

else if(choice==14){ //izlaz iz programa, te spremanje u fileove
writeInFile(listF,"films.txt",key,1);
writeUsers(listU,"users.txt",admin);
return;
}
else std::cout << "Wrong input!" << std::endl; //ukoliko admin ne unese broj izmedju 1 i 14

}
}

void optionsUser(ListFilms &listF,ListUsers &listU,ListFilms &listH,User& newuser,Administrator &admin,int key){ //opcije za usera
int choice;

while(true)
{
std::cout << "1. Enter 1 to review contents of the videostore" << std::endl;
std::cout << "2. Enter 2 to search the videostore by title" << std::endl;
std::cout << "3. Enter 3 to see all data for entered film title" << std::endl;
std::cout << "4. Enter 4 to borrow a film" << std::endl;
std::cout << "5. Enter 5 to return a film" << std::endl;
std::cout << "6. Enter 6 to review your history of borrowed films" << std::endl;
std::cout << "7. Enter 7 to review your currently borrowed films" << std::endl;
std::cout << "8. Enter 8 to quit program" << std::endl;

std::cin >> choice;

if(choice==1){ //ispis sadrzaja videoteke
listF.printListFilms();
}

else if(choice==2){ //ispis svih filmova sa datim nazivom
std::cout << "Enter the title of the film:";
std::string t;
cin.ignore();
getline(cin,t);
std::cout << "Films with that title are:" << std::endl;
listF.printListFilmsByTitle(t);
}

else if(choice==3){ //ispis svih pojedinosti za trazeni film
std::cout << "Enter the title of the film:";
std::string t;
cin.ignore();
getline(std::cin,t);
listF.printAllInfo(t);
}

else if(choice==4){ //posudjivanje filma
std::cout << "Enter the title of the film:";
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
catch(std::string a){std::cout << a << std::endl;}
}

else if(choice==5){ //vracanje filma
std::cout << "Enter the title of the film:";
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
catch(std::string a){std::cout << a << std::endl;}
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
else std::cout << "Wrong input!" << std::endl;
}

}
