#include "writeFilms.h"

void writeInFile(ListFilms& films,std::string file,int key,int hist)
{
ListFilms::iterator it=films.begin();
           ListFilms::iterator iter=films.end();
           ofstream logging;
           logging.open(file);
           if(hist!=0)
           logging<<"&"<<key<<std::endl;
           while(it!=iter){
             //upisivanje osnovnih podataka o filmu
            logging<<"#"<<(*it).getInfo().getTitle()<<","<<(*it).getInfo().getYear()<<","<<(*it).getInfo().getDirector().getName();
            logging<< ","<<(*it).getInfo().getDirector().getSurname()<<","<<(*it).getInfo().getCompany()<<","<<
            (*it).getInfo().getKey()<<","<<(*it).getInfo().getNumOfCopies()<<std::endl;
            logging<<"*"<<(*it).getInfo().getDescription()<<std::endl;
          
            Film nF=(*it).getInfo();
            if(!(nF.getProducents().empty()))
            {
            auto p=nF.getProducents().begin();
            auto k=nF.getProducents().end();
            logging<<"$"; // upisivanje liste producenata filma
          while(p!=k){
            logging<<(*p).getInfo().getName()<<","<<(*p).getInfo().getSurname();
            ++p;
            if(p!=k)
              logging<<",";
            
            }
             logging<<std::endl;

            }
            
            if(!(nF.getScenarists().empty()))
            {
            auto l=nF.getScenarists().begin();
            auto f=nF.getScenarists().end();
            logging<<"%";// upisivanje liste scenarista filma
            while(l!=f){
            logging<<(*l).getInfo().getName()<<","<<(*l).getInfo().getSurname();
            ++l;
            if(l!=f)
              logging<<",";
            }

            logging<<std::endl;
            }
            
            if(!(nF.getActors().empty()))
            {
            auto m=nF.getActors().begin();
            auto n=nF.getActors().end();
            logging<<"/"; // upisivanje liste glumaca filma
          while(m!=n){
            logging<<(*m).getInfo().getName()<<","<<(*m).getInfo().getSurname();
            ++m;
            if(m!=n)
              logging<<",";
            }
	    logging << std::endl;
            }
            ++it;
           } 
            logging.close();
           
         }


