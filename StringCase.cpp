#include <iostream>
#include <string.h>
using namespace std;

void stringCase(char stringinput[], bool choice);

int main(){

bool choice;
char stringinput[26];

cout<<"Please Enter your required Word ( max word lim-->26 )\n";
cin.getline(stringinput,26, '\n');
cout << "enter 1 for UpperCase and 0 for LowerCase\n";
cin>>choice;
stringCase(stringinput, choice);


} // main.


void stringCase(char stringinput[], bool choice){
int strSize; int l1=0;
int ascii_int;
char asciiCh;
        while (stringinput[l1]!='\0'){
                l1 = l1+1;
                strSize = l1;
        }

		// get the ascii values of the word entered.
			for (int i=0; i<strSize; i++){
				ascii_int = static_cast <int> (stringinput[i]);

					if (choice==1){
						if (ascii_int>=97 && ascii_int<=122){
							ascii_int -=32; // capital letter changed to small letter.
							asciiCh = ascii_int;
							stringinput[i]=asciiCh;
						} //if
					}//if

					else if (choice==0){ // for word in small letters.
                         if (ascii_int>=65 && ascii_int<=90){
                             ascii_int +=32; // capital letter changed to small letter.
                             asciiCh = ascii_int;
                             stringinput[i]=asciiCh;
                         } //if
                    }//if


			}// for
		// display the elements.
		for (int i=0; i<strSize; i++){
		cout<< stringinput[i];
		} // for
cout<<endl<<endl;
} // function terminates.
