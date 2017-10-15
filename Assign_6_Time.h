#ifndef _timex_
#define _timex_

#include <iostream>
using namespace std;

class Time
{
public:
  Time(); // default constructor
  Time(int h, int m); // constructor 2
  void setTime(int h, int m); //function to change a time object
  void printTime(); // function to print a time
  friend bool operator < (Time obj_a, Time obj_b);
  friend bool operator > (Time obj_a, Time obj_b);
  friend bool operator == (Time obj_a, Time obj_b);

  static bool comparison(Time tempT1, Time tempT2);
  static bool comparison();

  int getH();
  int getM();
  /* time is less if it came before another time*/
private:
  int hours; // 0 to 23
  int minutes; // 0 to 59
};
#endif
