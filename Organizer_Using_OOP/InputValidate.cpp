#include "InputValidate.h"

Date InputValidate::ReadDate(const std::string& prompt)
{
      while(true)
      {
          cout<<prompt;
          string tempd, tempm, tempy;
          cout<<"Format: dd/mm/yyyy\n";
          if(!getline(cin, tempd,'/'))
          continue;
          if(!getline(cin, tempm,'/'))
          continue;
          if(!getline(cin, tempy,'\n'))
          continue;
          if(tempd.size()!=2||tempm.size()!=2||tempy.size()!=4)
          continue;
          int d, m, y;
          d=atoi(tempd.c_str());
          m=atoi(tempm.c_str());
          y=atoi(tempy.c_str());
          Date A(d, m, y);
          return A;
      }
}

int InputValidate::ReadInteger(const std::string& prompt)
{
    cout<<prompt;
    string str;
    cin>>str;
    return (atoi(str.c_str()));
}

Time InputValidate::ReadTime(const std::string& prompt)
{
     cin.ignore();
     while (true)
     {
      cout<<prompt;
      cout<<"24 hour Format: hh:mm\n";
      string temph, tempm;
      if(!getline(cin, temph,':'))
      continue;
      if(!getline(cin, tempm,'\n'))
      continue;
      if(temph.size()!=2||tempm.size()!=2)
      continue;
      int h=atoi(temph.c_str());
      int m=atoi(tempm.c_str());
      Time A(h, m);
      return A;
      }
}
string InputValidate::ReadLine(const std::string& prompt)
{
       cout<<prompt;
       string a;
       getline(cin,a);
       return a;
}
