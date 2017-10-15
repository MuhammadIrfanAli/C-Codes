#include <iostream>
#include<string.h>
using namespace std;
int compareStr(char string1[],char string2[]);

int main(){
char string1[20];
char string2[25];
int strLen1; int strLen2;

cout<<"Please Enter Your first String: \n";
cin.getline(string1, 25, '\n');
cout<<"Now Enter sec string with which you intend to compare: \n";
cin.getline(string2, 20, '\n');

//int ascii_ch1 = static_cast <int>(ch1); //get the ascii value of the strings.

compareStr(string1,string2);



return 0;
}// main

		int compareStr(char string1[], char string2[]){
				int strLen1; int strLen2; int equal=0; int l1=0; int l2=0;;


      // lentgh of first string.
      while (string1[l1]!='\0'){
            l1 = l1+1;
            strLen1=l1;
      }//while.

      		//lentgh of second string.
        while (string2[l2]!='\0'){
        l2 = l2+1;
        strLen2 = l2;
        }
		if (strLen2>strLen1){
		cout<<"Length of second string should be less than the first string.\n";
		return 0;
		}//if.

// get the ascii values for first string.
		for (int i=0; i<strLen1; i++){ // runs less than the len of first string.
			int ascii_ch1 = static_cast <int>(string1[i]); //get the ascii value of the strings.

			for (int j=0; j<strLen2; j++){
			int ascii_ch2= static_cast <int>(string2[j]); //get the ascii value of the strings.

				if (i==j){ //compares only corresponding entries.

					if (ascii_ch1==ascii_ch2 || ascii_ch1+32==ascii_ch2 || ascii_ch1 == ascii_ch2+32){ // We treat capital and small letters as same.
					equal += 1;
						if (equal==strLen1){ //all elements have been compared.
						cout<<"OUTPUT: 0 \n"; 
						cout<<"String Matches \n";
						return 0;
						}
					}
					else if (ascii_ch1>ascii_ch2){
					cout<<"\n OUTPUT: -1 \n";
					cout<<"First Ch in string1 has lesser value.\n";
					return 0;
					}
					else if (ascii_ch1<ascii_ch2){
					cout<<"\n OUTPUT : 1 \n";
					cout<<"First Ch in string1 has Greater value.\n";
					return 0;
					}

				}//if

			}//for
		}//for


} // compare string finishes.
