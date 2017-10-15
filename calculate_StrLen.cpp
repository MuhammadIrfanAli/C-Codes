#include <iostream>
using namespace std;
int stringLen(char strInput[]);

int main(){
//char strInput;
char strInput[] = "Code Harder, Die harder";
cout<<"String Lentgh for '"<<strInput<<"' is: ";
stringLen(strInput);
}// main

int stringLen(char strInput[]){
int i=0;
		while (strInput[i]!='\0'){
		i = i+1;
		}
		cout<<i<<endl;
}
