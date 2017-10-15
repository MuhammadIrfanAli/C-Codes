
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

void shiftString(int num,char stringInput[]);
int main(){
int num;
char stringInput[30];
cout<<"Please Enter the Word you want to shift.\n";
cin.getline (stringInput ,30 , '\n');
//char stringInput[]={"Whale"};
cout<<"Please Enter a digit upto which you want your string to be shifted..\n";
cout<<"(Enter + num for Right Shift and - num for left shift.)\n";
cin>>num;
shiftString(num,stringInput);

return 0;
} //main

//<-----------------------------------------------------------------------
void shiftString(int num,char stringInput[]){
int strSize;
int shiftRight; int shiftLeft; int posNum; int l1=0; int stopCode;
char tempArray[30];

        while (stringInput[l1]!='\0'){
         		l1 = l1+1;
         		strSize = l1;
        }
			if (num>strSize){
			cout<<"Entered Num should be less than the lenght of entered string.\n BYE BYE \n";
			stopCode=0;
			}
	if (stopCode!=0){	
		for (int i=0; i<strSize; i++){
			for (int j=0; j<strSize; j++){
				//<FOR RIGHT SHIFT>
				if (num>0){
					shiftRight = i+num;

					if ( shiftRight >=strSize){ //if index increases array bounds.
						j = shiftRight%strSize;
						shiftRight = j;
					}//if

					if (j==shiftRight){ // required pos for new entry.
						tempArray[j] = stringInput[i];
						break;
					}//if
				}//if.

				//<FOR LEFT SHIFT>
				 if (num<0){
                     posNum = -1*num;
                     shiftLeft = i-posNum;

                     if ( shiftLeft < 0){ //if index increases array bounds.
                        shiftLeft = -1*shiftLeft;
                        shiftLeft = strSize-shiftLeft;
                        j=shiftLeft;
                     }//if
                     //shiftLeft = abs(shiftLeft);

                     if (j==shiftLeft){ // required pos for new entry.
                         tempArray[j] = stringInput[i];
                         break;
                     }//if
                }//if.
			}// for
		}// for
// display the elements.
		for (int i=0; i<strSize; i++){
		cout<<tempArray[i]<<" ";
		}
	}//Mega if.
cout<<endl<<endl;
} // func ends.
