OBJS= date.o film.o listFilms.o listUsers.o main.o person.o user.o readUsers.o split.o readFilms.o checkstring.o
CC= clang++
CFLAGS = -std=c++11 -c
LFLAGS = -std=c++11

p1: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o p1
date.o: date.cpp date.h
	$(CC) $(CFLAGS) date.cpp
film.o: film.cpp film.h
	$(CC) $(CFLAGS) film.cpp
listFilms.o: listFilms.cpp listFilms.h
	$(CC) $(CFLAGS) listFilms.cpp
listUsers.o: listUsers.cpp listUsers.h checkstring.h
	$(CC) $(CFLAGS) listUsers.cpp
main.o: main.cpp administrator.h listUsers.h listFilms.h readUsers.h readFilms.h
	$(CC) $(CFLAGS) main.cpp
person.o: person.cpp person.h 
	$(CC) $(CFLAGS) person.cpp
user.o: user.cpp user.h checkstring.h
	$(CC) $(CFLAGS) user.cpp
readUsers.o: readUsers.cpp readUsers.h
	$(CC) $(CFLAGS) readUsers.cpp
split.o: split.cpp split.h
	$(CC) $(CFLAGS) split.cpp
readFilms.o: readFilms.cpp readFilms.h
	$(CC) $(CFLAGS) readFilms.cpp
checkstring.o: checkstring.cpp checkstring.h
	$(CC) $(CFLAGS) checkstring.cpp

clean:
	\rm *.o *~ p1

