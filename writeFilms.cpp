#include "writeFilms.h"

void writeInFile(ListFilms& films,std::string file,int key)
{
ListFilms::iterator it=films.begin();
           ListFilms::iterator iter=films.end();
           ofstream logging;
           logging.open(file);
           logging<<"&"<<key<<std::endl;
           while(it!=iter){
             
            logging<<"#"<<(*it).getInfo().getTitle()<<","<<(*it).getInfo().getYear()<<","<<(*it).getInfo().getDirector().getName();
            logging<< ","<<(*it).getInfo().getDirector().getSurname()<<","<<(*it).getInfo().getCompany()<<","<<
            (*it).getInfo().getKey()<<","<<(*it).getInfo().getNumOfCopies()<<std::endl;
            logging<<"*"<<(*it).getInfo().getDescription()<<std::endl;
          
            Film nF=(*it).getInfo();
            auto p=nF.getProducents().begin();
            auto k=nF.getProducents().end();
            logging<<"$";
          while(p!=k){
            logging<<(*p).getInfo().getName()<<","<<(*p).getInfo().getSurname();
            ++p;
            if(p!=k)
              logging<<",";
            
            }

            logging<<std::endl;
            p=nF.getScenarists().begin();
            k=nF.getScenarists().end();
            logging<<"%";
          while(p!=k){
            logging<<(*p).getInfo().getName()<<","<<(*p).getInfo().getSurname()<<",";
            ++p;
            if(p!=k)
              logging<<",";
            }

            logging<<std::endl;
            p=nF.getActors().begin();
            k=nF.getActors().end();
            logging<<"/";
          while(p!=k){
            logging<<(*p).getInfo().getName()<<","<<(*p).getInfo().getSurname()<<",";
            ++p;
            if(p!=k)
              logging<<",";
            }
	    logging << std::endl;
            ++it;
           } 
            logging.close();
           
         }


