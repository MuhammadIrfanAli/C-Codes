#include <iostream>
using namespace std;

int main(){
	int input;
	int wrong=0;
	cout<<"Enter number of houses you intend ti invite: "<<endl;
	cin>>input;

	for (int num=3;num<=input;num++){

		for (int i=0;i<input;i++){

			if ( (i+num) <= input ){
				wrong++;
			}//if.
		}//for.
	}//for.
	cout<<"Number of ways to get wrong is: "<<endl;
	cout<< wrong <<endl;

return 0;
}//main.
