#include "readUsers.h"



void readUsers(std::string file,ListUsers& myList,ListFilms& historyFilms,Administrator& admin){
  std::string line;
  User newUser;
  int br=0;
  ifstream nameFileout;
  nameFileout.open(file);
  if(nameFileout.is_open()){
    char dummy;
    std::string name,surname,username,password,unob,date,title,nameA,surnameA,usernameA,passwordA;
    int year,month,day,nobf,key;
    while(getline(nameFileout,line))
    { 
      std::string temp;
      if(line.size()!=0)
      temp=line.substr(1,line.size()-1);
      std::stringstream ss(line);
      ss>>dummy;
      if(dummy=='&') // prije svega se iz fajla cita admin, on se nalazi prvi u fajlu
      {
        std::vector<std::string> adm=split(temp,',');
        nameA=adm[0];
        surnameA=adm[1];
        usernameA=adm[2];
        passwordA=adm[3];
        admin.setAdmin(nameA,surnameA,usernameA,passwordA);


      }
      if(dummy=='#') // citanje osnovnih podataka o korisniku
      {
        if(br>0)
        {
          myList.addUser(newUser); // dodavanje ce se izvrsiti u drugoj iteraciji kada prvi korisnik bude procitan
        }

        std::vector<std::string> vec=split(temp,',');
        name=vec[0];
        surname=vec[1];
        username=vec[2];
        password=vec[3];
        unob=vec[4];
        nobf=std::stoi(vec[5]);
        date=vec[6];
        std::stringstream dd(date);
        dd>>day>>dummy>>month>>dummy>>year;
        newUser.setUser(name,surname,unob,username,password,day,month,year,nobf);
        newUser.getHistory().clear();
        newUser.getBorrowed().clear();
        br++;



      }

      else if(dummy=='/') // citanje korisnikove historije filmova
      {
        std::vector<std::string> history=split(temp,','); // split vraca vektor koji sadrzi ekstraktovane podatke iz historije(file)
        for(int i=0;i<history.size();i=i+2)
        { 
          title=history[i];
          key=std::stoi(history[i+1]);
          if(!(historyFilms.empty()))
          {
          Film newFilm=historyFilms.findFilm(title,key);
          newUser.setHistory(newFilm);
        }
        else
          std::cout<<"History of films is empty! "<<std::endl;
      }
      }

      else if(dummy=='$'){ //citanje liste posudjenih filmova, na isti nacin kao i historija
        std::vector<std::string> borrowed=split(temp,',');
        for(int i=0;i<borrowed.size();i=i+2)
        { 
          title=borrowed[i];
          key=std::stoi(borrowed[i+1]);
          if(!(historyFilms.empty())){
          Film newFilm=historyFilms.findFilm(title,key);
          newUser.setBorrowed(newFilm);

        }
          else
            std::cout<<"History of films is empty!"<<std::endl;

      }
     }
    }
    if(br!=0)
      myList.addUser(newUser); // posljednji korisnik nece biti dodan u while petlji, zbog cega se za njega dodaje poslije petlje

  }


  else
  {
    std::cout<< "File doesn't exist!"<<std::endl; 

  }
  nameFileout.close();



}

