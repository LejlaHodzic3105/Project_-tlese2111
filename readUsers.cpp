#include "readUsers.h"



void readFile(std::string file,ListUsers& myList){
  std::string line;
  User newUser;
  int br=0;
  ifstream nameFileout;
  nameFileout.open(file);
  if(nameFileout.is_open()){
    char dummy;
    std::string name,surname,username,password,unob;
    int year,month,day;
    while(getline(nameFileout,line))
    { 
      std::stringstream ss(line);
      ss>>dummy;
      if(dummy=='#')
      {
      if(br>0)
      {
      myList.addUser(newUser);
      }

        ss>>name>> surname>> username>> password>> unob>> day>> dummy>> month>>dummy>>year;
        newUser.setUser(name,surname,unob,username,password,day,month,year);
        //newBill.getProducts().clear();
        br++;


      }

      //else if(dummy=='*'){
        //ss>>code>> productName>> num>> price;
        //Product newProduct;
        //newProduct.makeProduct(code,productName,num,price);
       // newBill.insertProduct(newProduct);


      //}


    }
    myList.addUser(newUser); 

  }


  else
  {
    std::cout<< "Taj fajl ne postoji!"<<std::endl; 

  }
  nameFileout.close();



}

