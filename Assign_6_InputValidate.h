#ifndef _INPUTVALIDATE_H_
#define _INPUTVALIDATE_H_

#include <iostream>
#include <string>
#include "Date.h"
#include "Time.h"
#include <stdio.h>
#include <stdlib.h>
/*
 * InputValidate class
 * -----------------
 * Wrapper around Input Stream that allows you to more easily read from 
 * cin in a formatted manner.  It offers public methods like ReadLine,
 * ReadInteger, ReadDate, etc. each in two versions: one that allows you 
 * to specify a prompt string and one without it. All of the methods are 
 * static, so you just send messages to the SimpleInput class itself, like 
 * this:
 *
 *		string name = SimpleInput::ReadLine("Enter your name: ");
 *
 * For those methods that require a particular type of input (integer, 
 * date, etc.) the method will read a full line and attempt to parse the 
 * correct type out, if ill-formatted, the user is chastised and prompted
 * to enter again.
 *
 * Caution: There are some invalid data values that you can not use as legal inputs
 * For reading an int, the value -1 is designated illegal
 * For reading a string, the string "__invalid_string" is designated illegal
 */

const int INVALID_INTEGER = -1;
const std::string INVALID_STRING = "__invalid_string";

class InputValidate
{
 private:
  
 public:
  static std::string ReadLine(const std::string& prompt);
  static std::string ReadLine();
  
  static int ReadInteger(const std::string& prompt);
  static int ReadInteger();
  
  static Date ReadDate(const std::string& prompt);
  static Date ReadDate();
  
  static Time ReadTime(const std::string& prompt);
  static Time ReadTime();

};

#endif /* _SIMPLEINPUT_H_ */
