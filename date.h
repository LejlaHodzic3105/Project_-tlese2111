#ifndef _DATE_H
#define _DATE_H

#include <iostream>
#include<string>

class Date{
  private:
    int _year;
    int _month;
    int _day;
  public:
    Date():_year(0),_month(0), _day(0){}
    ~Date()=default;
    Date(int year,int month,int day):_year(year),_month(month),_day(day){};//konstruktor ako korisnik zada tacan datum
    void setDay(int day){_day=day;}
    void setMonth(int month){_month=month;}
    void setYear(int year){_year=year;}
    int getDay()const{return _day;}
    int getMonth()const{return _month;}
    int getYear()const{return _year;}
    void  setDate(int year,int month,int day){_year=year;_month=month;_day=day;}
    void printDate() const ;// funkcija za ispis datuma

    
};

#endif
