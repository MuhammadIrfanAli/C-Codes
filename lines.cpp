#include <iostream>
using namespace std;
#include <fstream>
#include <string>
ifstream fin;


int main(){
string tempStr;
string comment;
int count=0;
int stop=0;
	fin.open("task2.cpp");
	while (!fin.eof()){
	/*
	if ( getline(fin, comment,'/') ){
		getline(fin, comment, '\n');
	 	stop=1;
	}
	*/
			if ( getline(fin, tempStr, ';') || getline(fin, tempStr, '\n') ){
				count++;
			}
			/*
			if (getline(fin, tempStr,'\n')){
				if (!tempStr.empty()){
				count++;
				}//if.
			*/	
		//	}
	//	}//if.
	//	stop=0;
	}//while.
	cout<<"Numeber of executable line of code is: "<<count<<endl;

	fin.close();
}//while.
