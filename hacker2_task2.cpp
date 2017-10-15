#include <iostream>
using namespace std;
#include <fstream>
#include <string.h>
int main(){
	int num;
	//int arrayNum[];

	int len, temp;
	ifstream fin;
	fin.open("nextBig.txt");
	while ( !fin.eof()){
		string temp;
		getline (fin, temp, '\n');
		len = strlen("temp");
		//int 
		cout<<temp<<endl;
		cout<<len;
			for (int i=0; i<len; i++)
			{
				cout<<temp[i]<<endl;
				if (temp[i]<temp[i+1]){
					cout<<"sdfsd"<<endl;
					return 0;
				}
				else{
					cout<<"fail"<<endl;
					return 0;
				}
			
			}
		return 0;
	/*	
	if (arrayNum[len-1]>a
	rrayNum[len-2]){
		temp = arrayNum[len-2];
		arrayNum[len-2] =  arrayNum[len-1];
		arrayNum[len-1] = 	temp;
	}
	else {
		cout<<"Num is already in bigger form."<<endl;
	}
	*/
	}
}//main.
