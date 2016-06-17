#include "readFilms.h"



int readFilms(std::string file,ListFilms& myList){
  std::string line;
  Film newFilm;
  int br=0,uniqueKey=-1;
  ifstream nameFileout;
  nameFileout.open(file);
  if(nameFileout.is_open()){
    char dummy;
    int k=0;
    std::string title,nameD,surnameD,prodComp,description,nameP,surnameP,nameS,surnameS,nameA,surnameA;
    int year,key,numofCopies;
    while(getline(nameFileout,line))
    {
      std::string temp;
      if(line.size()!=0)
      temp=line.substr(1,line.size()-1);
      std::stringstream ss(line);
      ss>>dummy;
      if(dummy=='&')
      {
        uniqueKey=std::stoi(temp);
      
      }
      else if(dummy=='#')
      {
      if(br>0)
      {
      myList.addFilm(newFilm);
      }

      std::vector<std::string> vec=split(temp,',');
      title=vec[0];
      year=std::stoi(vec[1]);
      nameD=vec[2];
      surnameD=vec[3];
      prodComp=vec[4];
      key=std::stoi(vec[5]);
      numofCopies=std::stoi(vec[6]);
      newFilm.setFilm(title,year,nameD,surnameD,prodComp,key,numofCopies);
      newFilm.clearProducents();
      newFilm.clearScenarists();
      newFilm.clearActors();
      br++;
      k=0;

      }

      else if(dummy=='*')
      {
        
        if(k==0)
        {
        description=temp;
        k++;
        }
        else
        {
          description=description+temp;
        }
        newFilm.setDescription(description);
      }


      else if(dummy=='$'){
        std::vector<std::string> producents=split(temp,',');
        for(int i=0;i<producents.size();i=i+2)
        { 
          nameP=producents[i];
          surnameP=producents[i+1];
          Person newProducent=Person(nameP,surnameP);
          newFilm.setProducents(newProducent);
          
        }
      }

       else if(dummy=='%'){
        std::vector<std::string> scenarists=split(temp,',');
        for(int i=0;i<scenarists.size();i=i+2)
        { 
          nameS=scenarists[i];
          surnameS=scenarists[i+1];
          Person newScenarist=Person(nameS,surnameS);
          newFilm.setScenarists(newScenarist);
          
        }
      }

       else if(dummy=='/'){
        std::vector<std::string> actors=split(temp,',');
        for(int i=0;i<actors.size();i=i+2)
        { 
          nameA=actors[i];
          surnameA=actors[i+1];
          Person newActor=Person(nameA,surnameA);
          newFilm.setActors(newActor);
          
        }
      }

    }
    if(br!=0)
    myList.addFilm(newFilm); 

  }


  else
  {
    std::cout<< "File doesn't exist!"<<std::endl; 

  }
  nameFileout.close();

  
 return uniqueKey;
}

