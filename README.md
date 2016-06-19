README
     

      Program represents a classic videostore, where users can borrow and return various types of movies. When the program starts it is waiting       for input of a username. The program recognizes if the entered username belongs to administrator or to one of the users. If the username doesn't belong to either of them, the program requires another input of username. When the username is valid, it asks for the password. If the password is valid it offers different options, depending on who logged in: administrator or a user. Administrator has 14 different options, he can review or change users and movies, but a user can only review movies, borrow a movie or return a movie. All data is preserved in .txt files (user's data, movie's data) and it loads to lists from .txt files at the beginning of the program. When the administrator or a user decides to quit the program all data is then stored from lists to .txt files.




AUTHOR AND CONTRIBUTOR LIST
 
              Lejla Hodzic
              Semir Omerovic


CONTACT 
  
   If you have problems,questions,ideas or suggestions,please contact us by
   email:
       
              lejla.hodzic@fet.ba 
              semir.omerovic@fet.ba  
   
   Reported bugs/fixes will be submitted to correction.



WEB SITE

   Visit this site for the latest news and downloads:

      https://github.com/LejlaHodzic3105/videostore_tlese2111.git


DIRECTIONS
  
      Once you have cloned the directory to your local machine,follow the
      directions bellow:

                 1. cd into videostore_tlese2111-master directory
                 2. call make clean
                 3. call make
                 4. call ./p1
      
      This will run this program.

FILE LIST
      
      main.cpp
      administrator.h
      checkstring.h checkstring.cpp
      date.h date.cpp
      film.h film.cpp
      films.txt users.txt history.txt
      lista.hxx node1.hxx
      listFilms.h listFilms.cpp
      listUsers.h listUsers.cpp
      makefile
      options.h options.cpp
      person.h person.cpp
      readFilms.h readFilms.cpp
      readUsers.h readUsers.cpp
      split.h split.cpp
      user.h user.cpp
      useraccount.h 
      writeFilms.h writeFilms.cpp
      writeUsers.h writeUsers.cpp

      
      
