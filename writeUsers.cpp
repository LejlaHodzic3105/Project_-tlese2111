#include "writeUsers.h"

void writeUsers(ListUsers& users,std::string file,Administrator& admin)
{
ListUsers::iterator it=users.begin();
           ListUsers::iterator iter=users.end();
           ofstream logging;
           logging.open(file);
           logging<<"&"<<admin.getName()<<","<<admin.getSurname()<<","<<admin.getUserAcc().getUsername()<<",";
           logging<<admin.getUserAcc().getPassword()<<std::endl;
           while(it!=iter){
             
            logging<<"#"<<(*it).getInfo().getName()<<","<<(*it).getInfo().getSurname()<<","<<(*it).getInfo().getUserAcc().getUsername();
            logging<< ","<<(*it).getInfo().getUserAcc().getPassword()<<","<<(*it).getInfo().getUnob()<<","<<
            (*it).getInfo().getNobf()<<","<<(*it).getInfo().getDate().getDay()<<".";
            logging<<(*it).getInfo().getDate().getMonth()<<"."<<(*it).getInfo().getDate().getYear()<<std::endl;
          
            User nF=(*it).getInfo();
            if(!(nF.getHistory().empty()))
            {
            auto p=nF.getHistory().begin();
            auto k=nF.getHistory().end();
            logging<<"/";
          while(p!=k){
            logging<<(*p).getInfo().getTitle()<<","<<(*p).getInfo().getKey();
            ++p;
            if(p!=k)
              logging<<",";
            
            }
             logging<<std::endl;

            }
            if(!(nF.getBorrowed().empty()))
            {
            auto l=nF.getBorrowed().begin();
            auto f=nF.getBorrowed().end();
            logging<<"$";
          while(l!=f){
            logging<<(*l).getInfo().getTitle()<<","<<(*l).getInfo().getKey();
            ++l;
            if(l!=f)
              logging<<",";
            }
             logging<<std::endl;

            }

            ++it;

           } 

            logging.close();
           
         }



