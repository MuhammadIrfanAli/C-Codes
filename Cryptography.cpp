#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

void createTable(char table[26][26]);
void encrypt(char plainText[], char cipherText[], char key[], char table[26][26]);
void stringCase(char plainText[], char key[]);
void decrypt(char plaintext[], char ciphertext[], char key[], char table[26][26]);



int main(){


int pTextSize; int keySize; int encryptSize; int asciiCh;
char plainText[50]; char key[15];
char table[26][26]={'0'};

cout<<"Enter text you want to encrypt. (maxLen-->50)\n";
cin.getline(plainText, 50,'\n');
pTextSize = strlen(plainText);
cout<<"Enter key Word; its length should be less than plain text (maxLen-->15)\n";
cin.getline(key,15,'\n');
keySize = strlen(key);

		//<--------------------------------------------->
				//Simple Check
		for (int i=0; i<pTextSize; i++){
		asciiCh = static_cast <int> (plainText[i]);
			if (asciiCh==32){
			cout<<"ERROR OCCURRED..\n Pls Don't Enter Spaces ... THANKS..!!\n";
			return 0;
			}
		}
		 for (int i=0; i<keySize; i++){
		      asciiCh = static_cast <int> (key[i]);
		   if (asciiCh==32){
		   cout<<"ERROR OCCURRED..\n Pls Don't Enter Spaces ... THANKS..!!\n";
		   return 0;
		   }
		 }   
		//<--------------------------------------------->

char cipherText[pTextSize];
	//check.
	if (keySize>pTextSize){
	cout<<"Length of Key word is greater than plainText. Programme 'll terminate.\n";
	return 0;
	}
//fnction
stringCase(plainText,key);
//function
createTable(table);
//function
encrypt(plainText,cipherText,key,table);

encryptSize = strlen(cipherText);
plainText[encryptSize];

//function.
decrypt(plainText,cipherText,key,table);


}//main.

//<----------------------------------------------------------------------------------->

// In case Small letters are entered.
		void stringCase(char plainText[], char key[]){
		int pTextSize;
		int keySize;
		int ascii_int;
		char asciiCh;
		pTextSize = strlen(plainText);
		keySize = strlen(key);
        // For plain text Words.
            for (int i=0; i<pTextSize; i++){
                	ascii_int = static_cast <int> (plainText[i]);

                if (ascii_int>=97 && ascii_int<=122){
                    ascii_int -=32; // small letter changed to capital letter.
                    asciiCh = ascii_int;
                    plainText[i]=asciiCh;
                } //if


            }// for
	// For Key words.
            for (int i=0; i<keySize; i++){
                	ascii_int = static_cast <int> (key[i]);

                if (ascii_int>=97 && ascii_int<=122){
                    ascii_int -=32; // small letter changed to capital letter.
                    asciiCh = ascii_int;
                    key[i]=asciiCh;
                } //if


            }// for
			cout<<endl;

} // function terminates.
//<--------------------------------------------------------------------------------------->
// FUNCTION TO CREATE TABLE.

		void createTable(char table[26][26]){
		int limBound;
		char tempRow[][27]={"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

		for (int i=0; i<=25; i++){
			for (int j=0; j<=25; j++){
				if (i==0){
					table[i][j] = tempRow[i][j];
				}//if.
				else {
					limBound = j-i;
				if (limBound<0){
					limBound = 26-abs(limBound);
				}//if.
					table[i][limBound] = tempRow[0][j];

				}//else
			} //for
		} //for

// draw the table.

	for (int i=0; i<=25; i++){
		for (int j=0; j<=25; j++){
			cout << table[i][j]<<" ";
		} // for
		cout<< endl;
	} //for


} // function terminates.
//<---------------------------------------------------------------------------------------->
				//Function for Encryption of code.
			void encrypt(char plainText[], char cipherText[], char key[], char table[26][26]){
			int pTextSize; int stopper=0; int keySize;int rowMatch; int colMatch;

			pTextSize = strlen(plainText);
			char keyEnlarge[pTextSize];
			keySize = strlen(key);
			// Key Enlarge.
			for (int i=0;i<pTextSize; i++){
				if (i>=keySize){
					i=0;
				}
				keyEnlarge[stopper]=key[i];

				stopper +=1;
				if (stopper>=pTextSize){
					break;
				}
			}//for.


// Encryption text implemented.
		for (int i=0; i<pTextSize;i++){

				for (int j=0; j<26;j++){//26 len of col tables.
					//to get jth col.
					if (plainText[i]==table[0][j]){//if letter from plainText matches ch @ 0 col of table.
					colMatch=j; //you found jth cols.
					}//if.
					// to get ith row.
					if(keyEnlarge[i]==table[j][0]){
					rowMatch = j; //you found ith row
					}

				}//for.
					cipherText[i]=table[rowMatch][colMatch];
		}//for.

		cout<<"\nEncrypted Text is: ";

		for (int i=0; i<pTextSize; i++){
		cout<<cipherText[i]<<" ";
		}

		cipherText[pTextSize]='\0';

}//function ends.
//<--------------------------------------------------------------------------------------->

// Decrypt the code.
void decrypt(char plainText[], char cipherText[], char key[], char table[26][26]){

int pTextSize; int stopper=0; int keySize;int rowMatch; int colMatch; int decStop=0;
int encryptSize;

encryptSize = strlen(cipherText);
char keyEnlarge[encryptSize];
keySize = strlen(key);
                // Key Enlarge.
                for (int i=0;i<encryptSize; i++){
                        if (i>=keySize){
                        i=0;
                        }
                		keyEnlarge[stopper]=key[i];

                		stopper +=1;
                        if (stopper>=encryptSize){
                        break;
                        }
                }//for.

// Decryption text implemented.
                for (int i=0; i<encryptSize;i++){

                        for (int j=0; j<26;j++){//26 len of col tables.

                            //to get jth row.
                            if (decStop==0){
                                if (table[j][0]==keyEnlarge[i]){//if letter from plainText matches ch @ 0 col of table.
                                    rowMatch=j; //you found jth row.
                                    decStop = 1;
                                    j=0;
                                    }//if.
                             }//if.

                             // to get ith row.
                             if (decStop!=0){
                                 if(table[rowMatch][j]==cipherText[i]){
                                     colMatch = j; //you found ith row
                                 }//if.
                             }//if.

                         }//for.
                plainText[i]=table[0][colMatch];
                decStop=0;
                }//for.

                cout<<"\nDecrypted Text is: ";
                for (int i=0; i<encryptSize; i++){
                cout<<plainText[i]<<" ";
                }
cout<<endl;
				cout<<"Key Word is: ";
				for (int i=0; i<keySize; i++){
				cout<<key[i]<<" ";
				}
cout<<endl;

}//function ends.
//<---------------------------------------------------------------------------------------------->
