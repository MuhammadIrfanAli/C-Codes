#ifndef _DATE_H_
#define _DATE_H_
#include<iostream>
#include "Time.h"
using namespace std;
class Date
{
 private:
  int Day;
  int Month;
  int Year;

 public:
  Date(int day, int month, int year);
  Date();
  void printDate();
  void setDate(int tempd, int tempm, int tempy); //function to change a date object
  friend bool operator < (Date obj_a, Date obj_b);
  friend bool operator > (Date obj_a, Date obj_b);
  friend bool operator == (Date obj_a, Date obj_b);
  int getDay();
  int getMonth();
  int getYear();
  bool comparison(Date d1, Date d2);
  /* date is less if it came before another date*/
};

#endif /* _DATE_H_ */
